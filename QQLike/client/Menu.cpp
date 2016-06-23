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
    //��ӦȺ�ĵ����Ի���
    connect(ListWidget,SIGNAL(itemDoubleClicked(QListWidgetItem *)),parent,SLOT(createprivatewindow(QListWidgetItem*)));
    //��Ӧ˫������˽�ĶԻ���

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



void Menu::AddMemberIcon()//���Ӻ���ͼ��
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
   list[itemcount]->setStatusTip(ip); // ���º��ѵĵ�ַ  ^^^^^^^^^^^
   list[itemcount]->setToolTip(id); // ���º��ѵ��˺ţ������������������ʾ
   //����setStatusTip��setToolTip������δ֪�ı��������ݴ��ַ���˺�
   //�����ڵ���˽�Ĵ���ʱ����ȡ����Щ��Ϣ
}


void Menu::CreatePublicWindow()//�½�Ⱥ�ĶԻ���
{
   //window[0]=new Windows(0,this);   //���� 0 �Ŵ�����˽�Ĵ���
   //window[0]->ip="255,255,255,255";
   //window[0]->id=myid;
   //window[0]->show();
}
void Menu::ShowPrivateMessage()//ȷ��˽�Ĵ��ڣ���ʾ��Ϣ
{
  //  int temp=0;
  //  while(window[++temp]->id!=id)    �Ҷ�Ӧ����
  //     ;
  // window[temp]->//��ʾ��Ϣ
}

void Menu::paintEvent(QPaintEvent *event)//��ͼ
{
    QPainter painter(this);
    painter.drawPixmap(0,0,250,600,QPixmap(":/images/back.jpg"));
}
