#include "CAP.h"


Register::Register(Client *parent)
{
    id="";
    password="1234";
    name="";
    ip=SERVERIP;
    message="d";
    msign=11;
    windowsnum=0;

    this->setWindowTitle(tr("×¢²á´°¿Ú"));
    label_id =new QLabel(tr("ÕËºÅ"),this);
    label_password =new QLabel(tr("ÃÜÂë"),this);
    label_name =new QLabel(tr("êÇ³Æ"),this);
    label_id->setGeometry(40,80,50,40);
    label_password->setGeometry(40,135,50,40);
    label_name->setGeometry(40,185,50,40);
    ledit_id =new QLineEdit(this);//ÕËºÅ
    ledit_password=new QLineEdit(this);//ÃÜÂë
    ledit_name =new QLineEdit(this);
    ledit_id->setGeometry(75,80,185,30);
    ledit_password->setGeometry(75,135,185,30);
    ledit_name->setGeometry(75,185,185,30);

    commit=new QPushButton(tr("Ìá½»"),this);
    close=new QPushButton(tr("¹Ø±Õ"),this);
    commit->setGeometry(80,320,75,25);
    close->setGeometry(180,320,75,25);

   /* QHBoxLayout* blayout;
    blayout=new QHBoxLayout;
    blayout->addStretch();
    blayout->addWidget(commit);
    blayout->addSpacing(20);

    blayout->addWidget(close);
    QVBoxLayout* layout;
    layout=new QVBoxLayout;
    layout->addLayout(blayout);
    this->setLayout(layout);*/
    this->resize(300,400);


   connect(commit,SIGNAL(clicked()),parent,SLOT(onregist()));
   connect(close,SIGNAL(clicked()),this,SLOT(close()));
   connect(ledit_id,SIGNAL(textChanged(QString)),this,SLOT(handidenter(QString)));
   connect(ledit_password,SIGNAL(textChanged(QString)),this,SLOT(handpasswordenter(QString)));
   connect(ledit_name,SIGNAL(textChanged(QString)),this,SLOT(handnameenter(QString)));

}

void Register::SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum)
{
    id=this->id;
    password=this->password;
    name=this->name;
    message=this->message;
    msign=this->msign;
    windowsnum=this->windowsnum;
    ip=this->ip;

}

void Register::GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->ip=ip;
    this->message=message;
    this->msign=msign;
    this->windowsnum=windowsnum;

}


Register::~Register()
{
}
void Register::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,300,400,QPixmap(":/images/22.jpg"));
}

void Register::handidenter(QString te)
{
    id=te;
}

void Register::handpasswordenter(QString te)
{
    password=te;
}

void Register::handnameenter(QString te)
{
    name=te;
}
