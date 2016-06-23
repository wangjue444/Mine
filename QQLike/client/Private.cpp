#include "CAP.h"


Private::Private(Client *parent)
{
    id="123";
    password="1234";
    name="io";
    ip=SERVERIP;
    message="d";
    msign=13;
    windowsnum=0;



    commit=new QPushButton(this);

    close=new QPushButton(this);
    commit->setText(QString("Ìá½»"));
    close->setText(tr("¹Ø±Õ"));
    tedit= new QTextEdit(this);
    tedit_send = new QTextEdit(this);
    tedit->setGeometry(10,50,500,220);
    tedit_send->setGeometry(10,300,500,160);
    commit->setGeometry(345,470,80,25);
    close->setGeometry(430,470,80,25);
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
    this->resize(600,500);


   connect(commit,SIGNAL(clicked()),parent,SLOT(oncommit()));
  connect(commit,SIGNAL(clicked()),this,SLOT(handupdateedit()));
   connect(close,SIGNAL(clicked()),this,SLOT(close()));
  connect(tedit_send,SIGNAL(textChanged()),this,SLOT(handtextsendenter()));
  connect(tedit,SIGNAL(textChanged()),this,SLOT(handtextsendenter()));

}

void Private::SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum)
{
    id=this->id;
    password=this->password;
    name=this->name;
    message=this->message;
    msign=this->msign;
    windowsnum=this->windowsnum;
    ip=this->ip;

}

void Private::GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->ip=ip;
    this->message=message;
    this->msign=msign;
    this->windowsnum=windowsnum;

}
QString Private::SendId()
{
    return id;
}

Private::~Private()
{

}

void Private::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,600,500,QPixmap(":/images/2027.jpg"));
}

void Private::handtextsendenter()
{

    message=tedit_send->toPlainText();
  //  QMessageBox::about(0,message,"e");
}

void Private::handupdateedit()
{
    tedit->append(tedit_send->toPlainText());


}

void Private::Update()
{
    tedit->append(message);
}
