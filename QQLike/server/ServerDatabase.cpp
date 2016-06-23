/*
 ServerDatabase.cpp
 数据库类实现
 作者：王珏
 版本：1.0

 */

#include "ServerDatabase.h"

ServerDatabase::ServerDatabase()   //构造函数  连接数据库 QQLike
{
    //分配内存
   // m_sd=new QSqlDatabase;
    //m_sq=new QSqlQuery;

    //连接数据库
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
    //将查询绑定数据库
    m_sq=QSqlQuery(m_sd);

    //测试两个表是否有效
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

ServerDatabase::~ServerDatabase() //析构函数
{
   // delete m_sq;
    //delete m_sd;
}

bool ServerDatabase::SDRegisterSearch(QString id) //判断注册帐号是否成功。 是否已存在.已存在返回false 未存在返回true
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

bool ServerDatabase::SDRegisterInput(QString id,QString password,QString name)//将注册信息写入数据库.成功返回true 失败返回false
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

bool ServerDatabase::SDLoginSearch(QString id,QString password)//判断登陆用户密码是否匹配 匹配返回true 未匹配或未找到返回false
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


bool ServerDatabase::SDBeOnline(QString id, QString name, QString ip)//将信息加入在线表。加入成功返回true 失败返回false
{
    QString strtemp;
    strtemp=QString("insert into online values('%1','%2','%3')").arg(id).arg(name).arg(ip);
    m_sq.exec(strtemp);
    if(!m_sq.isActive())
        return false;
    else
        return true;
}

QString ServerDatabase::SDGetIp(QString id)//在私聊时由帐号获取ip 成功返回获取的ip.失败返回"fail"
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

bool ServerDatabase::SDQuit(QString id)//当由用户下线时，从在线表中删除  成功返回true 失败返回false
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

int ServerDatabase::SDGetListNum() //返回在线列表中元祖数目
{

    int final=0;
    m_sq.exec("select* from online");
    while(m_sq.next())
    {
        final++;
    }
    return final;

}

bool ServerDatabase::SDGetList(int i,QString& id,QString& name)//将在线表中第i条中的账号 昵称存入SAP类成员变量
{

    m_sq.exec("select * from online");
    for(int temp=0;temp<i;temp++)
    {
        m_sq.next();
        id=m_sq.value(0).toString();
        name=m_sq.value(1).toString();
    }

}
