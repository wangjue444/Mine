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
    void paintEvent(QPaintEvent *event);//��ͼ
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


    QString id;        //�˺�
    QString password;  //����
    QString name;      //�ǳ�
    QString ip;        //��������ַ
    QString message;   //��Ϣ
    qint32  msign;     //��ʶ
    qint32  windowsnum;//���ں�

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
    void paintEvent(QPaintEvent *event);//��ͼ
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


    QString id;        //�˺�
    QString password;  //����
    QString name;      //�ǳ�
    QString ip;        //��������ַ
    QString message;   //��Ϣ
    qint32  msign;     //��ʶ
    qint32  windowsnum;//���ں�

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
    void paintEvent(QPaintEvent *event);//��ͼ
private:

    //QPushButton* commit;

    //QPushButton* close;
    QPixmap *map_menu;

    QString id;        //�˺�
    QString password;  //����
    QString name;      //�ǳ�
    QString ip;        //��������ַ
    QString message;   //��Ϣ
    qint32  msign;     //��ʶ
    qint32  windowsnum;//���ں�
    QString myid;

    Client* parent;


    //2.0b
    QListWidget* ListWidget;
    QVBoxLayout* layout;
    QPushButton *publicbutton;//Ⱥ�İ�ť
    QListWidgetItem* list[1000];
    qint32  itemcount;
    //Windows  *window[1000];   ����һ��˽�Ĵ�������
    //������е㷢�Ͱ�ťʱ��Ҫ�����б�����ֵ��
    //����Ҫ����һ����ʶ�Լ����ںŵı���,���캯����һ������count���β�
    //һ������Menu��ָ�롣дһ���źŹ�����  Menuָ���е�CAPָ���е�send������ֱ�ӷ���




public slots:
    void AddMemberIcon();//���Ӻ���ͼ��
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
    QString SendId();  //���ӵĺ���  ��id���͵������ô��࣬�ж���Ϣ�����ĸ�����
    void Update();
private:

    QPushButton* commit;

    QPushButton* close;
    QPixmap *map;
    QTextEdit* tedit;
    QTextEdit* tedit_send;

    QString id;        //�˺�
    QString password;  //����
    QString name;      //�ǳ�
    QString ip;        //��������ַ
    QString message;   //��Ϣ
    qint32  msign;     //��ʶ
    qint32  windowsnum;//���ں�

public slots:
    void handtextsendenter();
    void handupdateedit();



};









class Client:public QObject
{
    Q_OBJECT
public:
    QUdpSocket *udpreceiver;//udp�׽���
    QString id;        //�˺�
    QString password;  //����
    QString name;      //�ǳ�
    QString ip;        //��������ַ
    QString message;   //��Ϣ
    qint32  msign;     //��ʶ
    qint32  windowsnum;//���ں�
    QString myid;//����¼�ɹ��󣬲���

    qint32 windowscount;//��ǰ���ڸ���

    Register* regist;
    Login* login;
    Menu* menu;
    Private* privatea[1000];



public:
    Client();
    void GetSeverAddress();//��÷����� ip��ַ
    void HandleMessage(); //��Ҫ�������
    void HandleConvince();//������֤��Ϣ����ͻ��˷��͵�ͬ����Ϣ
    void HandleRegisterSuccess();//����ע��ɹ���Ϣ
    void HandleRegisterFail();//����ע��ʧ����Ϣ
    void HandleLoginSuccsee();//�����½�ɹ���Ϣ
    void HandleLoginFail();//�����½ʧ����Ϣ
    void HandleQuit();//�����˳���Ϣ
    void HandlePrivate();//����˽����Ϣ
    void HandlePublic();//����Ⱥ����Ϣ
    void HandleAddFriend();//�������ߺ���
    void HandleReduceFriend();//ȥ�����ߺ���
    void HandleGetList();//��ȡ�����б�
   void  CreateMenu();
    void readysend_slot();    //׼��������Ϣ֮ǰ�ĳ�ʼ��
    void send();// ����
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
