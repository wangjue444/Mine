#ifndef SERVERDATABASE_H
#define SERVERDATABASE_H

#endif // SERVERDATABASE_H


#include<QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QVariant>


class ServerDatabase
{

private:
    QSqlDatabase m_sd;
    QSqlQuery    m_sq;



public:
    ServerDatabase();
    ~ServerDatabase();
    bool SDRegisterSearch(QString id);  //
    bool SDRegisterInput(QString id,QString password,QString name);
    bool SDLoginSearch(QString id,QString password);
    bool SDBeOnline(QString id,QString name,QString ip);
    QString SDGetIp(QString id);
    bool SDQuit(QString id);
    QString SDGetName(QString id);
    QString SDGetId(QString ip);
    bool SDGetList(int i,QString& id,QString& name);//���������б���Ԫ����Ŀ
    int SDGetListNum();//�����߱��е�i���е��˺� �ǳƴ���SAP���Ա����


};
