#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QMessageBox>
namespace Ui {
    class MainWindow;
}



struct Tree
{
    int tsituation[15][15];
    Tree* son[255];
    int authority;
    int x;
    int y;
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent *);
    ~MainWindow();
    void AI();
    void Judge();
    void Analysis(int&x,int&y);
    bool JudgeWin(int x,int y);
    bool JudgeLose(int x,int y);
    bool SiLianW(int x,int y);
    bool YiSi(int x,int y,int point[2][2]);
    bool YiSiL(int x,int y);
    bool YiSanW(int x,int y);
    bool YiSanL(int x,int y);
    bool SiLianL(int x,int y);
    bool ShuangSanW(int x,int y);
    bool ShuangSanL(int x,int y);
    bool SanLianW(int x,int y,int point[2][2]);

    bool SanLianL(int x,int y);
    bool ErLianW(int x,int y);
    bool ErLianL(int x,int y);

    bool YiErW(int x,int y);
    bool YiErL(int x,int y);
    bool VCT(int x,int y);
    void Default(int& x,int& y);


private:
    Ui::MainWindow *ui;
    Tree Method;
    QLabel* ChessIcon;
    QLabel* LastIcon;
    int situation[15][15];
    int analy[15][15];
    QMessageBox messagebox;

};

#endif // MAINWINDOW_H
