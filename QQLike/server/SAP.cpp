#include "SAP.h"


SAP::SAP()
{
    qDebug()<<"3.01"<<endl;
    qDebug()<<"start"<<endl;
    udpreceiver = new QUdpSocket(this);
    udpreceiver->bind(8000,QUdpSocket::ShareAddress);  // shareAddress mode
    connect(udpreceiver, SIGNAL(readyRead()), this, SLOT(udprecv_slot()));
}
void SAP::Run() //运行函数
{

}
void SAP::HandleConvince()//处理验证信息，如客户端发送的同步信息
{}
void SAP::HandleRegister()//处理注册信息。
{
    qDebug()<<"handle register";
    if(sd.SDRegisterSearch(id))
    {
        if(sd.SDRegisterInput(id,password,name))//注册成功，将注册信息写入数据库
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
        qDebug()<<"fail in register\n";//注册失败，返回
    }

}
void SAP::HandleLogin()//处理登陆信息
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
        qDebug()<<"fail in log in\n";//用户密码不匹配
    }
}
void SAP::HandleQuit()//处理退出信息
{


    qDebug()<<"!!!";
    msign=30;
    sd.SDQuit(id);//从在线表中删除下线的人
    ip="255.255.255.255";
    send();

}
void SAP::HandlePrivate()//处理私聊信息
{
    msign =27;

    QString tempid;
    tempid=id;  //暂存接收者账号



  id=sd.SDGetId(ip);        //获取发送者账号    未完成
  qDebug()<<id<<endl;
    ip=sd.SDGetIp(tempid);    //获取接收者地址
    send();

}
void SAP::HandlePublic()//处理群聊信息
{
    msign =28;
  id=sd.SDGetId(ip);        //获取发送者账号    未完成
    ip="255.255.255.255";
    send();//广播群聊消息
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
    udpreceiver->writeDatagram(block.data(),block.size(),QHostAddress(ip),2000); // 广播的方式
}
void SAP::udprecv_slot()
{
    QHostAddress hostaddress;

    QByteArray datagram; //拥于存放接收的数据报
    while(udpreceiver->hasPendingDatagrams())
    {
        datagram.resize(udpreceiver->pendingDatagramSize()); //让datagram的大小为等待处理的数据报的大小，这样才能接收到完整的数据
        udpreceiver->readDatagram(datagram.data(),datagram.size(),&hostaddress);
        ip=hostaddress.toString();


        QDataStream in(&datagram,QIODevice::ReadOnly);
        in.setVersion(QDataStream::Qt_4_6);
        in >>msign>>id>>password>>name>>message;//把消息传给了SAP类

        qDebug()<<"successful connecting\n"<<msign<<id;//注册失败，返回

        HandleMessage();//分析消息包

    }

}


void SAP::HandleMessage() //主要拆包函数
{
    switch(msign)
    {
    case 11:HandleRegister();break;//处理注册信息。
    case 12:HandleLogin();break;//处理登陆信息
    case 13:HandlePrivate();break;//处理私聊信息
    case 14:HandlePublic();break;//处理群聊信息
    case 15:HandleQuit();break;//处理退出信息
    case 16:HandleGetList();break;
    default:break;


    };
}
/*传输包说明:
QbyteArray类型。
Bool SDRegisterSearch(Qstring id)
Void SDRegisterInput(Qstring id,Qstring password,Qstring name)
Bool SDLoginSearch(Qstring id,Qstring password)
Void SDOnlineUpdate(Qstring id,Qstring name)

客户端发：
客户端发出验证消息：
注册消息：11+帐号+密码+昵称+性别
登陆消息：12+帐号+密码
私聊 ：13+ 对方帐号+内容
群聊：14+消息
下线：15+帐号
申请获得在线列表：16



服务器发：
注册成功：21
注册失败：22
登陆失败：23
登陆成功：24
发送在线列表：25+多少人+1帐号+2帐号+。。。。
发送详细消息：26+昵称+性别
发送私聊消息：27+发送者帐号+内容
发送群聊消息：28+发送者帐号+内容
*/
