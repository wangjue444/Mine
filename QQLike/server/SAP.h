#ifndef SAP_H
#define SAP_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTextCodec>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include "ServerDatabase.h"
class SAP  :public QObject
{
    Q_OBJECT
private:
        ServerDatabase  sd;//数据库类对象
        QUdpSocket    *udpreceiver;//udp套接字   
        QString  id;       //账号
        QString password;  //密码
        QString name;      //昵称
        QString message;
        qint32  msign;     //标识
        QString ip;

public:
        SAP();
        void Run(); //运行函数
        void HandleMessage(); //主要拆包函数
        void HandleConvince();//处理验证信息，如客户端发送的同步信息
        void HandleRegister();//处理注册信息。
        void HandleLogin();//处理登陆信息
        void HandleQuit();//处理退出信息
        void HandlePrivate();//处理私聊信息
        void HandlePublic();//处理群聊信息
        void HandleGetList();
        void send();

        //      接收
 public slots:
        void udprecv_slot();   //  UDP    接收
};
#endif
/*

服务器端：类名前加Server

网络类：ServerSocket
        成员函数命名：SS+函数名


数据库类：ServerDatabase
        成员函数命名：SD+函数名
客户端：类名前加Client

网络类：ClientSocket
        成员函数命名：CC+函数名

数据库类 : ClientDatabase
        成员函数命名：CD+函数名





void SAP::Run()
{
        while(1)
        {
                //接收网络消息
                //将包存入packet
                if(//包更新)
                        HandleMessage();

        }



}



void SAP::HandleMessage()
{
        //拆包

        switch(//拆出的消息类型标记)
        {
        case :

                HandleRegister();
                break;




        case:

                HandleLogin();
                break;

        case:
                .
                .
                .


        }

}；



class ServerSocket
{
        ...
};

class ServerDatabase
{
        ...
};


客户端架构模型
#include "ClientSocket.h"




class CAP
{
private:
        ClientSocket* cs;//客户端网络类
        QByteArray packet;
        QWidget* qw;//用于多态实现. 指向各种继承自QWidget的控件
        QStaticText* qst;//用于多态实现,处理各种继承自QStaticText的静态文本框
        QTextEdit* qte;//同上
        ...

public:

        void Run();





};


传输包说明:
QbyteArray类型。

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

