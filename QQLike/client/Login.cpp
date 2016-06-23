#include "CAP.h"

Login::Login(Client *parent)
{
    id="1";
    password="1";
    name="io";
    ip=SERVERIP;
    message="d";
    msign=12;
    windowsnum=0;

    this->setWindowTitle(tr("µÇÂ¼´°¿Ú"));//&&&
    label_id = new QLabel(tr("ÕËºÅ"),this);
    label_password = new QLabel(tr("ÃÜÂë"),this);
    label_id->setGeometry(50,50,50,25);
    label_password->setGeometry(50,95,50,25);
    ledit_id =new QLineEdit(this);//µ¥ÐÐÎÄ±¾±à¼­¿ò
    ledit_password=new QLineEdit(this);
    ledit_id->setGeometry(85,50,185,25);
    ledit_password->setGeometry(85,95,185,25);//&&

    regist=new QPushButton(this);
    login=new QPushButton(this);
    close=new QPushButton(this);
    regist->setText(QString("×¢²á"));
    login->setText(tr("µÇÂ¼"));
    close->setText(tr("¹Ø±Õ"));
    regist->setGeometry(20,170,75,25);
    login->setGeometry(160,170,75,25);
    close->setGeometry(260,170,75,25);

   /* QHBoxLayout* blayout;
    blayout=new QHBoxLayout;
    blayout->addStretch();
    blayout->addWidget(regist);
    blayout->addSpacing(20);
    blayout->addWidget(login);
    blayout->addSpacing(20);
    blayout->addWidget(close);
    QVBoxLayout* layout;
    layout=new QVBoxLayout;
    layout->addLayout(blayout);
    this->setLayout(layout);*/
    this->resize(350,250);


   connect(regist,SIGNAL(clicked()),parent,SLOT(createregister()));
   connect(login,SIGNAL(clicked()),parent,SLOT(onlogin()));
   connect(close,SIGNAL(clicked()),this,SLOT(close()));
   connect(ledit_id,SIGNAL(textChanged(QString)),this,SLOT(handidenter(QString)));
   connect(ledit_password,SIGNAL(textChanged(QString)),this,SLOT(handpasswordenter(QString)));

}

void Login::SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum)
{
    id=this->id;
    password=this->password;
    name=this->name;
    message=this->message;
    msign=this->msign;
    windowsnum=this->windowsnum;
    ip=this->ip;

}

void Login::GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->ip=ip;
    this->message=message;
    this->msign=msign;
    this->windowsnum=windowsnum;

}
Login::~Login()
{

}
void Login::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,350,250,QPixmap(":/images/11.jpg"));
}

void Login::handidenter(QString te)
{
    id=te;
}

void Login::handpasswordenter(QString te)
{
    password=te;
}
