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
        ServerDatabase  sd;//���ݿ������
        QUdpSocket    *udpreceiver;//udp�׽���   
        QString  id;       //�˺�
        QString password;  //����
        QString name;      //�ǳ�
        QString message;
        qint32  msign;     //��ʶ
        QString ip;

public:
        SAP();
        void Run(); //���к���
        void HandleMessage(); //��Ҫ�������
        void HandleConvince();//������֤��Ϣ����ͻ��˷��͵�ͬ����Ϣ
        void HandleRegister();//����ע����Ϣ��
        void HandleLogin();//�����½��Ϣ
        void HandleQuit();//�����˳���Ϣ
        void HandlePrivate();//����˽����Ϣ
        void HandlePublic();//����Ⱥ����Ϣ
        void HandleGetList();
        void send();

        //      ����
 public slots:
        void udprecv_slot();   //  UDP    ����
};
#endif
/*

�������ˣ�����ǰ��Server

�����ࣺServerSocket
        ��Ա����������SS+������


���ݿ��ࣺServerDatabase
        ��Ա����������SD+������
�ͻ��ˣ�����ǰ��Client

�����ࣺClientSocket
        ��Ա����������CC+������

���ݿ��� : ClientDatabase
        ��Ա����������CD+������





void SAP::Run()
{
        while(1)
        {
                //����������Ϣ
                //��������packet
                if(//������)
                        HandleMessage();

        }



}



void SAP::HandleMessage()
{
        //���

        switch(//�������Ϣ���ͱ��)
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

}��



class ServerSocket
{
        ...
};

class ServerDatabase
{
        ...
};


�ͻ��˼ܹ�ģ��
#include "ClientSocket.h"




class CAP
{
private:
        ClientSocket* cs;//�ͻ���������
        QByteArray packet;
        QWidget* qw;//���ڶ�̬ʵ��. ָ����ּ̳���QWidget�Ŀؼ�
        QStaticText* qst;//���ڶ�̬ʵ��,������ּ̳���QStaticText�ľ�̬�ı���
        QTextEdit* qte;//ͬ��
        ...

public:

        void Run();





};


�����˵��:
QbyteArray���͡�

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

