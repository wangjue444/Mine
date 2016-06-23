#ifndef CAP_H
#define CAP_H



#include <QtGui/QWidget>
#include <QHostAddress>
#include <QTextCodec>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>
#include <QObject>
#include <QUdpSocket>
#include <QHostAddress>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <QListWidget>
#include <QLabel>//
#include <QLineEdit>
#include <QPixmap>
#include <QPainter>
#include <QTextEdit>

#define SERVERIP "169.254.142.172"
class Client;





///////////////////////////////////////////////////////////
class Login:public QWidget
{
    Q_OBJECT;
public:
    explicit Login(Client *parent = 0);
    ~Login();
    void paintEvent(QPaintEvent *event);//贴图
    void SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum);
    void GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum);
private:
    QLabel* label_id;
    QLabel* label_password;
    QLineEdit* ledit_id;
    QLineEdit* ledit_password;
    QPixmap *map_login;
    QPushButton* regist;
    QPushButton* login;
    QPushButton* close;


    QString id;        //账号
    QString password;  //密码
    QString name;      //昵称
    QString ip;        //服务器地址
    QString message;   //消息
    qint32  msign;     //标识
    qint32  windowsnum;//窗口号

public slots:
    void handidenter(QString te);
    void handpasswordenter(QString te);


};
//////////////////////////////////////////////////






class Register:public QWidget
{
    Q_OBJECT;
public:
    explicit Register(Client *parent = 0);
    ~Register();
    void paintEvent(QPaintEvent *event);//贴图
    void SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum);
    void GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum);
private:
    QLabel* label_id;
    QLabel* label_password;
    QLabel* label_name;
    QLineEdit* ledit_id;
    QLineEdit* ledit_password;
    QLineEdit* ledit_name;
    QPixmap *map;
    QPushButton* commit;
    QPushButton* close;


    QString id;        //账号
    QString password;  //密码
    QString name;      //昵称
    QString ip;        //服务器地址
    QString message;   //消息
    qint32  msign;     //标识
    qint32  windowsnum;//窗口号

public slots:
    void handidenter(QString te);
    void handpasswordenter(QString te);
    void handnameenter(QString te);


};


////////////////////////////////////////////////////////////

class Menu:public QWidget
{
    Q_OBJECT;
public:
    explicit Menu(QString myid,Client *parent = 0);
    ~Menu();
    void SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum);
    void GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum);
    void closeEvent(QCloseEvent *);

    //2.0b
    void ShowPrivateMessage();
    void ReduceMemberIcon();
    void paintEvent(QPaintEvent *event);//贴图
private:

    //QPushButton* commit;

    //QPushButton* close;
    QPixmap *map_menu;

    QString id;        //账号
    QString password;  //密码
    QString name;      //昵称
    QString ip;        //服务器地址
    QString message;   //消息
    qint32  msign;     //标识
    qint32  windowsnum;//窗口号
    QString myid;

    Client* parent;


    //2.0b
    QListWidget* ListWidget;
    QVBoxLayout* layout;
    QPushButton *publicbutton;//群聊按钮
    QListWidgetItem* list[1000];
    qint32  itemcount;
    //Windows  *window[1000];   设置一个私聊窗口数组
    //这个类中点发送按钮时就要给所有变量赋值，
    //类中要声明一个标识自己窗口号的变量,构造函数加一个接收count的形参
    //一个接收Menu的指针。写一个信号关联到  Menu指针中的CAP指针中的send函数，直接发送




public slots:
    void AddMemberIcon();//增加好友图标
    void CreatePublicWindow();




};


class Private:public QWidget
{
    Q_OBJECT;
public:
    explicit Private(Client *parent = 0);
    ~Private();
    void paintEvent(QPaintEvent *event);
    void SendInfo(QString& id,QString& password,QString& name,QString& ip,QString& message,qint32& msign,qint32& windowsnum);
    void GetInfo(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum);
    QString SendId();  //增加的函数  把id发送到大类让大类，判断消息属于哪个窗口
    void Update();
private:

    QPushButton* commit;

    QPushButton* close;
    QPixmap *map;
    QTextEdit* tedit;
    QTextEdit* tedit_send;

    QString id;        //账号
    QString password;  //密码
    QString name;      //昵称
    QString ip;        //服务器地址
    QString message;   //消息
    qint32  msign;     //标识
    qint32  windowsnum;//窗口号

public slots:
    void handtextsendenter();
    void handupdateedit();



};









class Client:public QObject
{
    Q_OBJECT
public:
    QUdpSocket *udpreceiver;//udp套接字
    QString id;        //账号
    QString password;  //密码
    QString name;      //昵称
    QString ip;        //服务器地址
    QString message;   //消息
    qint32  msign;     //标识
    qint32  windowsnum;//窗口号
    QString myid;//当登录成功后，不变

    qint32 windowscount;//当前窗口个数

    Register* regist;
    Login* login;
    Menu* menu;
    Private* privatea[1000];



public:
    Client();
    void GetSeverAddress();//获得服务器 ip地址
    void HandleMessage(); //主要拆包函数
    void HandleConvince();//处理验证信息，如客户端发送的同步信息
    void HandleRegisterSuccess();//处理注册成功信息
    void HandleRegisterFail();//处理注册失败信息
    void HandleLoginSuccsee();//处理登陆成功信息
    void HandleLoginFail();//处理登陆失败信息
    void HandleQuit();//处理退出信息
    void HandlePrivate();//处理私聊信息
    void HandlePublic();//处理群聊信息
    void HandleAddFriend();//增加上线好友
    void HandleReduceFriend();//去掉下线好友
    void HandleGetList();//获取在线列表
   void  CreateMenu();
    void readysend_slot();    //准备发送消息之前的初始化
    void send();// 发送
 public slots:
    void udprecv_slot();
    void updatedata(QString id,QString password,QString name,QString ip,QString message,qint32 msign,qint32 windowsnum);
    void createregister();
    void onlogin();
    void onregist();
    void onquit();
    void oncommit();
    void createprivatewindow(QListWidgetItem *link);
};




#endif // CAP_H
