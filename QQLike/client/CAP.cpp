#include "CAP.h"


Client::Client()
{
    windowscount=0;
    windowsnum=-1;
    menu=NULL;
    regist=NULL;
    login=NULL;
    udpreceiver = new QUdpSocket(this);
    udpreceiver->bind(2000,QUdpSocket::ShareAddress);  // shareAddress mode
    connect(udpreceiver, SIGNAL(readyRead()), this, SLOT(udprecv_slot()));
  //  connect(sendbutton,SIGNAL(clicked()),this,SLOT(readysend_slot()));
    login=new Login(this);
    login->show();

}
void Client::readysend_slot()
{
    //��������Ҫ���͵���Ϣ��ֵ
    //SSSend();
}
void Client::send()
{
    QMessageBox::about(login,"1",myid);

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out <<msign<<id<<password<<name<<message<<windowsnum;
    udpreceiver->writeDatagram(block.data(),block.size(),QHostAddress(ip),8000);
}
void Client::udprecv_slot()
{


    QByteArray datagram; //ӵ�ڴ�Ž��յ����ݱ�
    while(udpreceiver->hasPendingDatagrams())
    {
        datagram.resize(udpreceiver->pendingDatagramSize()); //��datagram�Ĵ�СΪ�ȴ���������ݱ��Ĵ�С���������ܽ��յ�����������
        udpreceiver->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in >>msign>>id>>password>>name>>message>>windowsnum;//����Ϣ������SAP��
        HandleMessage();//������Ϣ��
    }
}
void Client::HandleMessage() //��Ҫ�������
{
    switch(msign)
    {
    case 21:HandleRegisterSuccess();break;
    case 22:HandleRegisterFail();break;
    case 23:HandleLoginFail();break;
    case 24:HandleLoginSuccsee();break;
    case 25:HandleGetList();break;
  //  case 26:HandleRegister();break;
    case 27:HandlePrivate();break;
    case 28:HandlePublic();break;
    case 29:HandleAddFriend();break;
    case 30:HandleReduceFriend();break;
    };
}
void Client::HandleRegisterSuccess()
{
    QMessageBox::about(regist,"ע��ɹ�","ע��ɹ�");
    regist->setVisible(false);
}
void Client::HandleRegisterFail()
{
    QMessageBox::about(regist,"ע��ʧ��","ע��ʧ��");
}
void Client::HandleLoginFail()
{
    QMessageBox::about(login,"��¼ʧ��","��¼ʧ��");
}
void Client::HandleLoginSuccsee()
{
    QMessageBox::about(login,"��¼�ɹ�","��¼�ɹ�");
    login->setVisible(false);
    myid=id;
    CreateMenu();
}
void Client::HandlePrivate()
{
    QMessageBox::about(0,message,"e");
    for(int i=0;i<1000;i++)
    {
        if(privatea[i]==NULL)//����رմ��������ٵĻ��Ϳ���
            continue;
        if(privatea[i]->SendId()==id)
        {
            msign=13;
            ip=SERVERIP;
            windowsnum=0;
            privatea[i]->GetInfo(id,password,name,ip,message,msign,windowsnum);
            privatea[i]->Update();
        }
    }




}
void Client::HandlePublic()
{
     qDebug()<<"�ڴ�����ʾ Ⱥ����Ϣ\n";
}



void Client::HandleAddFriend()
{
    if(menu!=NULL)
    {
    menu->GetInfo(id,password,name,ip,message,msign,windowsnum);
    menu->AddMemberIcon();
    }

}


void Client::HandleReduceFriend()
{
    menu->GetInfo(id,password,name,ip,message,msign,windowsnum);
    menu->ReduceMemberIcon();

}

void Client::HandleGetList()
{
    QMessageBox::about(menu,"s","s");


    HandleAddFriend();

}

void Client::CreateMenu()
{
    menu=new Menu(myid,this);
    menu->show();
    msign=16;
    send();

}

void Client::updatedata(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->ip=ip;
    this->message=message;
    this->msign=msign;
    this->windowsnum=windowsnum;
    send();

}

void Client::createregister()
{

    regist=new Register(this);
    regist->show();
}

void Client::onlogin()
{

    login->SendInfo(id,password,name,ip,message,msign,windowsnum);
    QMessageBox::about(login,name,ip);
    send();
}

void Client::onregist()
{

    regist->SendInfo(id,password,name,ip,message,msign,windowsnum);

    send();

}

void Client::onquit()
{
  menu->SendInfo(id,password,name,ip,message,msign,windowsnum);

  QMessageBox::about(menu,id,ip);
  send();
}


void Client::oncommit()//private
{
    privatea[windowsnum]->SendInfo(id,password,name,ip,message,msign,windowsnum);

    send();
}


void Client::createprivatewindow(QListWidgetItem *link)//�½�˽�ĶԻ���
{

   //��һ�������ظ����ڵ��㷨
      privatea[++windowsnum]=new Private(this);
      id=link->toolTip();
      ip=link->statusTip();

      msign=13;
      ip=SERVERIP;
      privatea[windowsnum]->GetInfo(id,password,name,ip,message,msign,windowsnum);
      privatea[windowsnum]->show();

}
