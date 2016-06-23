#include "CAP.h"


Menu::Menu(QString myid,Client *parent)
{
    this->parent=parent;
    this->myid=myid;

    //2.0b

    itemcount=0;
    publicbutton=new QPushButton;
    publicbutton->setText("public talking");

     ListWidget = new QListWidget;
    layout = new QVBoxLayout;
    layout->addWidget(ListWidget);
    layout->addWidget(publicbutton);
    this->setLayout(layout);
    this->resize(250,600);
    connect(publicbutton,SIGNAL(clicked()),this,SLOT(CreatePublicWindow()));
    //响应群聊弹出对话框
    connect(ListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),parent,SLOT(createprivatewindow(QListWidgetItem*)));
    //响应双击弹出私聊对话框

}

void Menu::SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum)
{
    id=this->id;
    password=this->password;
    name=this->name;
    message=this->message;
    msign=this->msign;
    windowsnum=this->windowsnum;
    ip=this->ip;

}

void Menu::GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum)
{
    this->id=id;
    this->password=password;
    this->name=name;
    this->ip=ip;
    this->message=message;
    this->msign=msign;
    this->windowsnum=windowsnum;

}


Menu::~Menu()
{


}

void Menu::closeEvent(QCloseEvent *e)
{

    msign=15;
    id=myid;
    ip=SERVERIP;
    parent->onquit();


 /*   int key = QMessageBox::warning(this,tr("eed"),tr("hello"),QMessageBox::Yes);
    if(key == QMessageBox::Yes)
        close();
    else
        return ;
  */
}

void Menu::ReduceMemberIcon()
{

    for(int i=0;i<=itemcount;i++)
    {
        if(list[i]==NULL)
            continue;
        if(list[i]->toolTip()==id)
        {
           // list[i]->setHidden(true);
            delete list[i];
            list[i]=NULL;
        }
    }
}



void Menu::AddMemberIcon()//增加好友图标
{

    for(int i=0;i<=itemcount;i++)
    {
        if(list[i]==NULL)
            continue;
        if(list[i]->toolTip()==id)
            return;
    }
   list[++itemcount] = new QListWidgetItem(QIcon(":/images/M4.jpg"),name, ListWidget);
   ListWidget->insertItem(1, list[itemcount]);
   list[itemcount]->setStatusTip(ip); // 存下好友的地址  ^^^^^^^^^^^
   list[itemcount]->setToolTip(id); // 存下好友的账号，名字再上面存用来显示
   //以上setStatusTip，setToolTip是两个未知的变量用来暂存地址和账号
   //下面在弹出私聊窗口时可以取出这些信息
}


void Menu::CreatePublicWindow()//新建群聊对话框
{
   //window[0]=new Windows(0,this);   //设置 0 号窗口是私聊窗口
   //window[0]->ip="255,255,255,255";
   //window[0]->id=myid;
   //window[0]->show();
}
void Menu::ShowPrivateMessage()//确定私聊窗口，显示信息
{
  //  int temp=0;
  //  while(window[++temp]->id!=id)    找对应窗口
  //     ;
  // window[temp]->//显示信息
}

void Menu::paintEvent(QPaintEvent *event)//贴图
{
    QPainter painter(this);
    painter.drawPixmap(0,0,250,600,QPixmap(":/images/back.jpg"));
}
