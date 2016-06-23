/*
 ServerDatabase.cpp
 ���ݿ���ʵ��
 ���ߣ�����
 �汾��1.0

 */

#include "ServerDatabase.h"

ServerDatabase::ServerDatabase()   //���캯��  �������ݿ� QQLike
{
    //�����ڴ�
   // m_sd=new QSqlDatabase;
    //m_sq=new QSqlQuery;

    //�������ݿ�
    QString strDatabaseName = QString("DRIVER={SQL Server};Server=(%1);Database=%2").arg("local").arg("QQLike");
    m_sd=QSqlDatabase::addDatabase("QODBC","m_sd");
    m_sd.setDatabaseName(strDatabaseName);
    m_sd.setHostName("local");
    m_sd.setPort(1433);

    if(!m_sd.open())
    {
       qDebug()<<"fail when connecting database"<<endl;
        exit(0);
    }
    //����ѯ�����ݿ�
    m_sq=QSqlQuery(m_sd);

    //�����������Ƿ���Ч
    m_sq.exec("insert into online values('qq-like','qq-like','192.168.1.1')");



    if(!m_sq.isActive())
    {

        qDebug()<<"table online is not ready"<<endl;
        m_sq.exec("delete from online where id='qq-like' and name='qq-like'") ;
        exit(0);
    }
    else
    {
        qDebug()<<"table online is ready"<<endl;
        m_sq.exec("delete from online where id='qq-like' and name='qq-like'") ;
    }

    m_sq.exec("insert into account values('qq-like','qq-like','qq-like')");
    if(!m_sq.isActive())
    {
       qDebug()<<"table account is not ready"<<endl;
       m_sq.exec("delete from account where id='qq-like' and password='qq-like'");
       exit(0);
    }
    else
    {
        qDebug()<<"table account is ready"<<endl;
        m_sq.exec("delete from account where id='qq-like' and password='qq-like'");
    }




  /*  while(query.next())
    {
        QString kind=query.value(0).toString();
        int ele=query.value(1).toInt();
        qDebug()<<kind<<ele<<endl;
    }
*/
}

ServerDatabase::~ServerDatabase() //��������
{
   // delete m_sq;
    //delete m_sd;
}

bool ServerDatabase::SDRegisterSearch(QString id) //�ж�ע���ʺ��Ƿ�ɹ��� �Ƿ��Ѵ���.�Ѵ��ڷ���false δ���ڷ���true
{
    QString strid;
    QString strtemp=QString("select * from Account where id='%1'").arg(id);
    m_sq.exec(strtemp);
    if(!m_sq.isActive())
    {
        return true;
    }
    else
    {
        while(m_sq.next())
        {
             strid=m_sq.value(0).toString();
             if(strid==id)
                 return false;
        }
        return true;
    }

}

bool ServerDatabase::SDRegisterInput(QString id,QString password,QString name)//��ע����Ϣд�����ݿ�.�ɹ�����true ʧ�ܷ���false
{
    QString strtemp=QString("insert into Account values('%1','%2','%3')").arg(id).arg(password).arg(name);
    m_sq.exec(strtemp);
    if(!m_sq.isActive())
    {
        return false;
    }
    else
        return true;

}

bool ServerDatabase::SDLoginSearch(QString id,QString password)//�жϵ�½�û������Ƿ�ƥ�� ƥ�䷵��true δƥ���δ�ҵ�����false
{
    QString strtemp;
    QString strtemp1;

    strtemp=QString("select * from Account where id='%1'").arg(id);
    strtemp1=QString("select *from online where id='%1'").arg(id);
    m_sq.exec(strtemp1);



    if(m_sq.next())
        return false;


    m_sq.exec(strtemp);

    if(!m_sq.isActive())
    {

        return false;
    }

    m_sq.next();

    QString pas=m_sq.value(1).toString();

    if(pas==password)
        return true;
    else
        return false;

}


bool ServerDatabase::SDBeOnline(QString id, QString name, QString ip)//����Ϣ�������߱�����ɹ�����true ʧ�ܷ���false
{
    QString strtemp;
    strtemp=QString("insert into online values('%1','%2','%3')").arg(id).arg(name).arg(ip);
    m_sq.exec(strtemp);
    if(!m_sq.isActive())
        return false;
    else
        return true;
}

QString ServerDatabase::SDGetIp(QString id)//��˽��ʱ���ʺŻ�ȡip �ɹ����ػ�ȡ��ip.ʧ�ܷ���"fail"
{
    QString strtemp;
    strtemp=QString("select ip from online where id='%1'").arg(id);
    m_sq.exec(strtemp);
    m_sq.next();
    QString re=m_sq.value(0).toString();
    if(!m_sq.isActive())
        return "fail";
    else
        return re;

}

bool ServerDatabase::SDQuit(QString id)//�����û�����ʱ�������߱���ɾ��  �ɹ�����true ʧ�ܷ���false
{
    QString strtemp;
    strtemp=QString("delete from online where id='%1'").arg(id);
    m_sq.exec(strtemp);
    if(!m_sq.isActive())
        return false;
    else
        return true;

}

QString ServerDatabase::SDGetName(QString id)
{
    QString re;
    QString strtemp;
    strtemp=QString("select *from account where id='%1'").arg(id);

    m_sq.exec(strtemp);
    m_sq.next();
    re=m_sq.value(2).toString();
    return re;

}
QString ServerDatabase::SDGetId(QString ip)
{

    QString re;
    QString strtemp;
    strtemp=QString("select* from online where ip='%1'").arg(ip);
    m_sq.exec(strtemp);
    m_sq.next();
    re=m_sq.value(0).toString();
    qDebug()<<"getid"<<endl;
    return re;

}

int ServerDatabase::SDGetListNum() //���������б���Ԫ����Ŀ
{

    int final=0;
    m_sq.exec("select* from online");
    while(m_sq.next())
    {
        final++;
    }
    return final;

}

bool ServerDatabase::SDGetList(int i,QString& id,QString& name)//�����߱��е�i���е��˺� �ǳƴ���SAP���Ա����
{

    m_sq.exec("select * from online");
    for(int temp=0;temp<i;temp++)
    {
        m_sq.next();
        id=m_sq.value(0).toString();
        name=m_sq.value(1).toString();
    }

}
