#include "SAP.h"


SAP::SAP()
{
    qDebug()<<"3.01"<<endl;
    qDebug()<<"start"<<endl;
    udpreceiver = new QUdpSocket(this);
    udpreceiver->bind(8000,QUdpSocket::ShareAddress);  // shareAddress mode
    connect(udpreceiver, SIGNAL(readyRead()), this, SLOT(udprecv_slot()));
}
void SAP::Run() //���к���
{

}
void SAP::HandleConvince()//������֤��Ϣ����ͻ��˷��͵�ͬ����Ϣ
{}
void SAP::HandleRegister()//����ע����Ϣ��
{
    qDebug()<<"handle register";
    if(sd.SDRegisterSearch(id))
    {
        if(sd.SDRegisterInput(id,password,name))//ע��ɹ�����ע����Ϣд�����ݿ�
        {
            msign=21;
            send();
            qDebug()<<"successful register\n";
        }
        else
        {
            msign=22;
            send();
            qDebug()<<"fail in write in database\n";
        }
    }
    else
    {
        msign=22;
        send();
        qDebug()<<"fail in register\n";//ע��ʧ�ܣ�����
    }

}
void SAP::HandleLogin()//�����½��Ϣ
{
    QString tempname;


    if(sd.SDLoginSearch(id,password))
    {
        tempname=sd.SDGetName(id);
       sd.SDBeOnline(id,tempname,ip);
       qDebug()<<"log in successful\n";
       msign=24;
       send();
       msign=29;
       ip="255.255.255.255";
       name=sd.SDGetName(id);
       send();


    }
    else
    {
        msign=23;
        send();
        qDebug()<<"fail in log in\n";//�û����벻ƥ��
    }
}
void SAP::HandleQuit()//�����˳���Ϣ
{


    qDebug()<<"!!!";
    msign=30;
    sd.SDQuit(id);//�����߱���ɾ�����ߵ���
    ip="255.255.255.255";
    send();

}
void SAP::HandlePrivate()//����˽����Ϣ
{
    msign =27;

    QString tempid;
    tempid=id;  //�ݴ�������˺�



  id=sd.SDGetId(ip);        //��ȡ�������˺�    δ���
  qDebug()<<id<<endl;
    ip=sd.SDGetIp(tempid);    //��ȡ�����ߵ�ַ
    send();

}
void SAP::HandlePublic()//����Ⱥ����Ϣ
{
    msign =28;
  id=sd.SDGetId(ip);        //��ȡ�������˺�    δ���
    ip="255.255.255.255";
    send();//�㲥Ⱥ����Ϣ
}

void SAP::HandleGetList()
{
    qDebug()<<"GetList";
    msign=25;
    int listnum=sd.SDGetListNum();
    for(int temp=1;temp<=listnum;temp++)
    {
         sd.SDGetList(temp,id,name);

         send();
    }

}

void SAP::send()
{
    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_6);
    out <<msign;
    out <<id;
    out <<password;
    out <<name;
    out <<message;
    udpreceiver->writeDatagram(block.data(),block.size(),QHostAddress(ip),2000); // �㲥�ķ�ʽ
}
void SAP::udprecv_slot()
{
    QHostAddress hostaddress;

    QByteArray datagram; //ӵ�ڴ�Ž��յ����ݱ�
    while(udpreceiver->hasPendingDatagrams())
    {
        datagram.resize(udpreceiver->pendingDatagramSize()); //��datagram�Ĵ�СΪ�ȴ���������ݱ��Ĵ�С���������ܽ��յ�����������
        udpreceiver->readDatagram(datagram.data(),datagram.size(),&hostaddress);
        ip=hostaddress.toString();


        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in >>msign>>id>>password>>name>>message;//����Ϣ������SAP��

        qDebug()<<"successful connecting\n"<<msign<<id;//ע��ʧ�ܣ�����

        HandleMessage();//������Ϣ��

    }

}


void SAP::HandleMessage() //��Ҫ�������
{
    switch(msign)
    {
    case 11:HandleRegister();break;//����ע����Ϣ��
    case 12:HandleLogin();break;//�����½��Ϣ
    case 13:HandlePrivate();break;//����˽����Ϣ
    case 14:HandlePublic();break;//����Ⱥ����Ϣ
    case 15:HandleQuit();break;//�����˳���Ϣ
    case 16:HandleGetList();break;
    default:break;


    };
}
/*�����˵��:
QbyteArray���͡�
Bool SDRegisterSearch(Qstring id)
Void SDRegisterInput(Qstring id,Qstring password,Qstring name)
Bool SDLoginSearch(Qstring id,Qstring password)
Void SDOnlineUpdate(Qstring id,Qstring name)

�ͻ��˷���
�ͻ��˷�����֤��Ϣ��
ע����Ϣ��11+�ʺ�+����+�ǳ�+�Ա�
��½��Ϣ��12+�ʺ�+����
˽�� ��13+ �Է��ʺ�+����
Ⱥ�ģ�14+��Ϣ
���ߣ�15+�ʺ�
�����������б�16



����������
ע��ɹ���21
ע��ʧ�ܣ�22
��½ʧ�ܣ�23
��½�ɹ���24
���������б�25+������+1�ʺ�+2�ʺ�+��������
������ϸ��Ϣ��26+�ǳ�+�Ա�
����˽����Ϣ��27+�������ʺ�+����
����Ⱥ����Ϣ��28+�������ʺ�+����
*/
