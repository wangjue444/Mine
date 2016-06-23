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
    //设置所有要发送的消息的值
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


    QByteArray datagram; //拥于存放接收的数据报
    while(udpreceiver->hasPendingDatagrams())
    {
        datagram.resize(udpreceiver->pendingDatagramSize()); //让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        udpreceiver->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in >>msign>>id>>password>>name>>message>>windowsnum;//把消息传给了SAP类
        HandleMessage();//分析消息包
    }
}
void Client::HandleMessage() //主要拆包函数
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
    QMessageBox::about(regist,"注册成功","注册成功");
    regist->setVisible(false);
}
void Client::HandleRegisterFail()
{
    QMessageBox::about(regist,"注册失败","注册失败");
}
void Client::HandleLoginFail()
{
    QMessageBox::about(login,"登录失败","登录失败");
}
void Client::HandleLoginSuccsee()
{
    QMessageBox::about(login,"登录成功","登录成功");
    login->setVisible(false);
    myid=id;
    CreateMenu();
}
void Client::HandlePrivate()
{
    QMessageBox::about(0,message,"e");
    for(int i=0;i<1000;i++)
    {
        if(privatea[i]==NULL)//如果关闭窗口是销毁的话就可以
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
     qDebug()<<"在窗口显示 群聊消息\n";
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


void Client::createprivatewindow(QListWidgetItem *link)//新建私聊对话框
{

   //加一个控制重复窗口的算法
      privatea[++windowsnum]=new Private(this);
      id=link->toolTip();
      ip=link->statusTip();

      msign=13;
      ip=SERVERIP;
      privatea[windowsnum]->GetInfo(id,password,name,ip,message,msign,windowsnum);
      privatea[windowsnum]->show();

}
