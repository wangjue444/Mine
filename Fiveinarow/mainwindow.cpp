#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QApplication>
#include <QCoreApplication>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    for(int i=0;i<15;i++)
        for(int j=0;j<15;j++)
            situation[i][j]=-1;

    ChessIcon=NULL;
    LastIcon=NULL;



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent* event)///////////////////////////90   12    21   35
{
    int x_f,y_f;
    char temp[10];
    char temp1[10];
    char final[20];
    x_f=(event->x()-103+17)/35+1;
    y_f=(event->y()-35+17)/35+1;


    if(event->button()==Qt::LeftButton&&event->x()>=85&&event->y()>=23&&event->x()<=610&&event->y()<=542&&situation[x_f-1][y_f-1]==-1)
    {

        if(LastIcon)
        {
           LastIcon->setPixmap(QPixmap(":/images/white.png"));
        }

        ChessIcon=new QLabel(ui->centralWidget);
        ChessIcon->setPixmap(QPixmap(":/images/latestblack.png"));
        LastIcon=ChessIcon;


        ChessIcon->move(((event->x()-103+17)/35)*35+103-16,((event->y()-35+17)/35)*35+35-12-16);

        situation[x_f-1][y_f-1]=0;

        ChessIcon->show();

        Judge();

        AI();
    }
    else
    {
        QApplication::beep();
        return;

    }


}

void MainWindow::mouseReleaseEvent(QMouseEvent *)
{


}

void MainWindow::AI()
{

   //static int i=0;
 //  static int j=0;
   int i;
    int j;

    Analysis(i,j);


    situation[i][j]=1;

    if(LastIcon)
    {
       LastIcon->setPixmap(QPixmap(":/images/black.png"));
    }

    ChessIcon=new QLabel(ui->centralWidget);
    ChessIcon->setPixmap(QPixmap(":/images/latestwhite.png"));

    LastIcon=ChessIcon;
    ChessIcon->move(i*35+103-16,j*35+35-12-16);
    ChessIcon->show();

    if(i<15)
        i++;
    if(i==15)
    {
        i=0;
       j++;
    }

    Judge();
    return;

}

void MainWindow::Judge()
{
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i<=10)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&situation[i+3][j]==1&&situation[i+4][j]==1)
                {
                    QMessageBox::about(this,tr("The white win"),tr("The white win"));
                    exit(0);
                }
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&situation[i+3][j]==0&&situation[i+4][j]==0)
                {


                    QMessageBox::about(this,tr("The black win"),tr("The black win"));
                    exit(0);


                }





            }
            if(j<=10)
            {
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&situation[i][j+3]==1&&situation[i][j+4]==1)
                {
                    QMessageBox::about(this,tr("The white win"),tr("The white win"));
                    exit(0);
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&situation[i][j+3]==0&&situation[i][j+4]==0)
                {
                    QMessageBox::about(this,tr("The black win"),tr("The black win"));
                    exit(0);
                }
            }
            if(i<=10&&j<=10)
            {
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&situation[i+3][j+3]==1&&situation[i+4][j+4]==1)
                {
                    QMessageBox::about(this,tr("The white win"),tr("The white win"));
                    exit(0);
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&situation[i+3][j+3]==0&&situation[i+4][j+4]==0)
                {
                    QMessageBox::about(this,tr("The black win"),tr("The black win"));
                    exit(0);
                }

            }
            if(i>=4&&j<=10)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&situation[i-3][j+3]==1&&situation[i-4][j+4]==1)
                {
                    QMessageBox::about(this,tr("The white win"),tr("The white win"));
                    exit(0);
                }
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&situation[i-3][j+3]==0&&situation[i-4][j+4]==0)
                {
                    QMessageBox::about(this,tr("The black win"),tr("The black win"));
                    exit(0);
                }

            }


        }
    }
}


bool MainWindow::JudgeWin(int x,int y)
{
    situation[x][y]=1;

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i<=10)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&situation[i+3][j]==1&&situation[i+4][j]==1)
                {
                    situation[x][y]=-1;

                    return true;
                }






            }
            if(j<=10)
            {
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&situation[i][j+3]==1&&situation[i][j+4]==1)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }
            if(i<=10&&j<=10)
            {
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&situation[i+3][j+3]==1&&situation[i+4][j+4]==1)
                {
                    situation[x][y]=-1;
                   return true;
                }


            }
            if(i>=4&&j<=10)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&situation[i-3][j+3]==1&&situation[i-4][j+4]==1)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }


        }
    }
    situation[x][y]=-1;
    return false;
}

bool MainWindow::JudgeLose(int x,int y)
{
    situation[x][y]=0;

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i<=10)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&situation[i+3][j]==0&&situation[i+4][j]==0)
                {
                    situation[x][y]=-1;
                    return true;
                }






            }
            if(j<=10)
            {
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&situation[i][j+3]==0&&situation[i][j+4]==0)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }
            if(i<=10&&j<=10)
            {
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&situation[i+3][j+3]==0&&situation[i+4][j+4]==0)
                {
                    situation[x][y]=-1;
                   return true;
                }


            }
            if(i>=4&&j<=10)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&situation[i-3][j+3]==0&&situation[i-4][j+4]==0)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }


        }
    }
    situation[x][y]=-1;
    return false;


}

bool MainWindow::SiLianW(int x,int y)
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i<=10&&i>=1)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&situation[i+3][j]==1&&(situation[i+4][j]==-1&&situation[i-1][j]==-1))
                {


                    situation[x][y]=-1;
                    return true;
                }
            }

            if(j<=10&&j>=1)
            {
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&situation[i][j+3]==1&&(situation[i][j+4]==-1&&situation[i][j-1]==-1))
                {

                    situation[x][y]=-1;
                    return true;
                }

            }
            if(i<=10&&j<=10&&i>=1&&j>=1)
            {
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&situation[i+3][j+3]==1&&(situation[i+4][j+4]==-1&&situation[i-1][j-1]==-1))
                {

                    situation[x][y]=-1;
                   return true;
                }


            }
            if(i>=4&&j<=10&&i<=13&&j>=1)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&situation[i-3][j+3]==1&&(situation[i-4][j+4]==-1&&situation[i+1][j-1]==-1))
                {

                    situation[x][y]=-1;
                    return true;
                }

            }


        }
    }
    situation[x][y]=-1;
    return false;
}

bool MainWindow::SiLianL(int x,int y)
{
    situation[x][y]=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i<=10&&i>=1)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&situation[i+3][j]==0&&situation[i+4][j]==-1&&situation[i-1][j]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }

            if(j<=10&&j>=1)
            {
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&situation[i][j+3]==0&&situation[i][j+4]==-1&&situation[i][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }
            if(i<=10&&j<=10&&i>=1&&j>=1)
            {
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&situation[i+3][j+3]==0&&situation[i+4][j+4]==-1&&situation[i-1][j-1]==-1)
                {
                    situation[x][y]=-1;
                   return true;
                }


            }
            if(i>=4&&j<=10&&i<=13&&j>=1)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&situation[i-3][j+3]==0&&situation[i-4][j+4]==-1&&situation[i+1][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }

            }


        }
    }
    situation[x][y]=-1;
    return false;


}

bool MainWindow::ShuangSanW(int x, int y)
{
    int count=0;
    situation[x][y]=1;

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==1)
            {
                count=0;
                if(i>=3&&j>=3&&i<=11&&j<=11)
                {
                    if(!(situation[i][j-2]==0||situation[i][j-1]==0||situation[i][j]==0||situation[i][j+1]==0||situation[i][j+2]==0))
                    {
                        if(situation[i][j-2]+situation[i][j-1]+situation[i][j]+situation[i][j+1]+situation[i][j+2]==1&&(situation[i][j-2]!=1||situation[i][j]!=1||situation[i][j+2]!=1))
                        {
                            if(!((situation[i][j-2]==1&&situation[i][j-3]==0)||(situation[i][j+2]==1&&situation[i][j+3]==0)))
                            {

                                count++;
                            }
                        }

                        if(count>=2)
                        {
                            situation[x][y]=-1;
                            return true;
                        }

                    }

                    if(!(situation[i-1][j-1]==0||situation[i-2][j-2]==0||situation[i][j]==0||situation[i+1][j+1]==0||situation[i+2][j+2]==0))
                    {
                        if(situation[i-1][j-1]+situation[i-2][j-2]+situation[i][j]+situation[i+1][j+1]+situation[i+2][j+2]==1&&(situation[i-2][j-2]!=1||situation[i][j]!=1||situation[i+2][j+2]!=1))
                        {
                            if(!((situation[i-2][j-2]==1&&situation[i-3][j-3]==0)||(situation[i+2][j+2]==1&&situation[i+3][j+3]==0)))
                            {


                                count++;
                            }
                        }

                        if(count>=2)
                        {
                            situation[x][y]=-1;
                            return true;
                        }


                    }
                    if(!(situation[i-1][j]==0||situation[i-2][j]==0||situation[i][j]==0||situation[i+1][j]==0||situation[i+2][j]==0))
                    {
                        if(situation[i-1][j]+situation[i-2][j]+situation[i][j]+situation[i+1][j]+situation[i+2][j]==1&&(situation[i-2][j]!=1||situation[i][j]!=1||situation[i+2][j]!=1))
                        {
                            if(!((situation[i-2][j]==1&&situation[i-3][j]==0)||(situation[i+2][j]==1&&situation[i+3][j]==0)))
                            {


                                count++;
                            }

                        }
                        if(count>=2)
                        {
                            situation[x][y]=-1;
                            return true;
                        }
                    }

                    if(!(situation[i-1][j+1]==0||situation[i-2][j+2]==0||situation[i][j]==0||situation[i+1][j-1]==0||situation[i+2][j-2]==0))
                    {
                        if(situation[i-1][j+1]+situation[i-2][j+2]+situation[i][j]+situation[i+1][j-1]+situation[i+2][j-2]==1&&(situation[i-2][j+2]!=1||situation[i][j]!=1||situation[i+2][j-2]!=1))
                        {
                            if(!((situation[i-2][j+2]==1&&situation[i-3][j+3]==0)||(situation[i+2][j-2]==1&&situation[i+3][j-3]==0)))
                            {
                                count++;
                            }
                        }
                        if(count>=2)
                        {
                            situation[x][y]=-1;
                            return true;
                        }
                    }


                }





            }
        }
    }


    situation[x][y]=-1;
    return false;

}


bool MainWindow::ShuangSanL(int x, int y)
{

    int count=0;
    situation[x][y]=0;


    char temp[20];
    char temp1[20];


    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==0)
            {
                count=0;
                if(i>=3&&j>=3&&i<=11&&j<=11)
                {
                    if(!(situation[i][j-2]==1||situation[i][j-1]==1||situation[i][j]==1||situation[i][j+1]==1||situation[i][j+2]==1))
                    {
                        if(situation[i][j-2]+situation[i][j-1]+situation[i][j]+situation[i][j+1]+situation[i][j+2]==-2&&(situation[i][j-2]!=0||situation[i][j]!=0||situation[i][j+2]!=0))

                        {
                            if(!((situation[i][j-2]==0&&situation[i][j-3]==1)||(situation[i][j+2]==0&&situation[i][j+3]==1)))
                            {


                               // itoa(i+1,temp,10);
                               // itoa(j+1,temp1,10);
                               // strcat(temp,temp1);
                                count++;
                            }
                        }
                        if(count>=2)
                        {
                           // QMessageBox::about(this,"s",temp);

                            situation[x][y]=-1;
                            return true;
                        }

                    }

                    if(!(situation[i-1][j-1]==1||situation[i-2][j-2]==1||situation[i][j]==1||situation[i+1][j+1]==1||situation[i+2][j+2]==1))
                    {
                        if(situation[i-1][j-1]+situation[i-2][j-2]+situation[i][j]+situation[i+1][j+1]+situation[i+2][j+2]==-2&&(situation[i-2][j-2]!=0||situation[i][j]!=0||situation[i+2][j+2]!=0))
                        {
                            if(!((situation[i-2][j-2]==0&&situation[i-3][j-3]==1)||(situation[i+2][j+2]==0&&situation[i+3][j+3]==1)))
                            {
                              //  itoa(i+1,temp,10);
                               // itoa(j+1,temp1,10);
                               // strcat(temp,temp1);
                                count++;
                            }
                        }

                        if(count>=2)
                        {
                           // QMessageBox::about(this,"s",temp);
                            situation[x][y]=-1;
                            return true;
                        }


                    }
                    if(!(situation[i-1][j]==1||situation[i-2][j]==1||situation[i][j]==1||situation[i+1][j]==1||situation[i+2][j]==1))
                    {
                        if(situation[i-1][j]+situation[i-2][j]+situation[i][j]+situation[i+1][j]+situation[i+2][j]==-2&&(situation[i-2][j]!=0||situation[i][j]!=0||situation[i+2][j]!=0))
                        {
                            if(!((situation[i-2][j]==0&&situation[i-3][j]==1)||(situation[i+2][j]==0&&situation[i+3][j]==1)))
                            {
                               //  //   itoa(i+1,temp,10);
                               // itoa(j+1,temp1,10);
                               // strcat(temp,temp1);
                                count++;
                             }
                        }
                        if(count>=2)
                        {
                           // QMessageBox::about(this,"s",temp);
                            situation[x][y]=-1;
                            return true;
                        }
                    }

                    if(!(situation[i-1][j+1]==1||situation[i-2][j+2]==1||situation[i][j]==1||situation[i+1][j-1]==1||situation[i+2][j-2]==1))
                    {
                        if(situation[i-1][j+1]+situation[i-2][j+2]+situation[i][j]+situation[i+1][j-1]+situation[i+2][j-2]==-2&&(situation[i-2][j+2]!=0||situation[i][j]!=0||situation[i+2][j-2]!=0))
                        {
                            if(!((situation[i-2][j+2]==0&&situation[i-3][j+3]==1)||(situation[i+2][j-2]==0&&situation[i+3][j-3]==1)))
                            {
                               // itoa(i+1,temp,10);
                               // itoa(j+1,temp1,10);
                               // strcat(temp,temp1);
                                count++;
                            }
                        }
                        if(count>=2)
                        {
                           // QMessageBox::about(this,"s",temp);
                            situation[x][y]=-1;
                            return true;
                        }
                    }


                }





            }
        }
    }


    situation[x][y]=-1;
    return false;

}


bool MainWindow::SanLianW(int x, int y,int point[2][2])
{

    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=11&&j<=11)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&situation[i-1][j]==-1&&situation[i+3][j]==-1)
                {
                    point[0][0]=i-1;
                    point[0][1]=j;
                    point[1][0]=i+3;
                    point[1][1]=j;
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&situation[i][j-1]==-1&&situation[i][j+3]==-1)
                {
                    point[0][0]=i;
                    point[0][1]=j-1;
                    point[1][0]=i;
                    point[1][0]=j+3;

                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&situation[i-1][j-1]==-1&&situation[i+3][j+3]==-1)
                {
                    point[0][0]=i-1;
                    point[0][1]=j-1;
                    point[1][0]=i+3;
                    point[1][1]=j+3;
                    situation[x][y]=-1;
                    return true;

                }
            }
            if(i>=3&&i<=13&&j<=11&&j>=1)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&situation[i+1][j-1]==-1&&situation[i-3][j+3]==-1)
                {
                    point[0][0]=i+1;
                    point[0][1]=j-1;
                    point[1][0]=i-3;
                    point[1][1]=j+3;
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;
}

bool MainWindow::SanLianL(int x, int y)
{
    situation[x][y]=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=11&&j<=11)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&situation[i-1][j]==-1&&situation[i+3][j]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&situation[i][j-1]==-1&&situation[i][j+3]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&situation[i-1][j-1]==-1&&situation[i+3][j+3]==-1)
                {
                    situation[x][y]=-1;
                    return true;

                }
            }
            if(i>=3&&i<=13&&j<=11&&j>=1)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&situation[i+1][j-1]==-1&&situation[i-3][j+3]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;

}

bool MainWindow::YiSanW(int x, int y)
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=11&&j<=11)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&((situation[i-1][j]==0&&situation[i+3][j]==-1)||(situation[i-1][j]==-1&&situation[i+3][j]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&((situation[i][j-1]==0&&situation[i][j+3]==-1)||(situation[i][j-1]==-1&&situation[i][j+3]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&((situation[i-1][j-1]==0&&situation[i+3][j+3]==-1)||(situation[i-1][j-1]==-1&&situation[i+3][j+3]==0)))
                {
                    situation[x][y]=-1;
                    return true;

                }
            }
            if(i>=3&&i<=13&&j<=11&&j>=1)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&((situation[i+1][j-1]==0&&situation[i-3][j+3]==-1)||(situation[i+1][j-1]==-1&&situation[i-3][j+3]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;

}

bool MainWindow::YiSanL(int x, int y)
{
    situation[x][y]=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=11&&j<=11)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&((situation[i-1][j]==1&&situation[i+3][j]==-1)||(situation[i-1][j]==-1&&situation[i+3][j]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&((situation[i][j-1]==1&&situation[i][j+3]==-1)||(situation[i][j-1]==-1&&situation[i][j+3]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&((situation[i-1][j-1]==1&&situation[i+3][j+3]==-1)||(situation[i-1][j-1]==-1&&situation[i+3][j+3]==1)))
                {
                    situation[x][y]=-1;
                    return true;

                }
            }
            if(i>=3&&i<=13&&j<=11&&j>=1)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&((situation[i+1][j-1]==1&&situation[i-3][j+3]==-1)||(situation[i+1][j-1]==-1&&situation[i-3][j+3]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;

}

bool MainWindow::ErLianW(int x, int y)
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&i<=12&&j>=1&&j<=12)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i-1][j]==-1&&situation[i+2][j]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==-1&&situation[i][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==-1&&situation[i-1][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
            if(i>=2&&i<=13&&j>=1&&j<=12)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==-1&&situation[i+1][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }



    situation[x][y]=-1;
    return false;
}

bool MainWindow::ErLianL(int x, int y)
{
    situation[x][y]=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&i<=12&&j>=1&&j<=12)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i-1][j]==-1&&situation[i+2][j]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==-1&&situation[i][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==-1&&situation[i-1][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
            if(i>=2&&i<=13&&j>=1&&j<=12)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==-1&&situation[i+1][j-1]==-1)
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }



    situation[x][y]=-1;
    return false;
}

bool MainWindow::YiErW(int x, int y)
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&i<=12&&j>=1&&j<=12)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&((situation[i-1][j]==0&&situation[i+2][j]==-1)||(situation[i-1][j]==-1&&situation[i+2][j]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i][j+1]==1&&((situation[i][j+2]==0&&situation[i][j-1]==-1)||(situation[i][j+2]==-1&&situation[i][j-1]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&((situation[i+2][j+2]==0&&situation[i-1][j-1]==-1)||(situation[i+2][j+2]==-1&&situation[i-1][j-1]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
            if(i>=2&&i<=13&&j>=1&&j<=12)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&((situation[i-2][j+2]==0&&situation[i+1][j-1]==-1)||(situation[i-2][j+2]==-1&&situation[i+1][j-1]==0)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }



    situation[x][y]=-1;
    return false;

}

bool MainWindow::YiErL(int x, int y)
{
    situation[x][y]=0;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&i<=12&&j>=1&&j<=12)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&((situation[i-1][j]==1&&situation[i+2][j]==-1)||(situation[i-1][j]==-1&&situation[i+2][j]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&((situation[i][j+2]==1&&situation[i][j-1]==-1)||(situation[i][j+2]==-1&&situation[i][j-1]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&((situation[i+2][j+2]==1&&situation[i-1][j-1]==-1)||(situation[i+2][j+2]==-1&&situation[i-1][j-1]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
            if(i>=2&&i<=13&&j>=1&&j<=12)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&((situation[i-2][j+2]==1&&situation[i+1][j-1]==-1)||(situation[i-2][j+2]==-1&&situation[i+1][j-1]==1)))
                {
                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }



    situation[x][y]=-1;
    return false;

}

//此处判断连杀
bool MainWindow::VCT(int x, int y)
{
    int count;
    int point[2][2];
    if(JudgeWin(x,y)||SiLianW(x,y)||ShuangSanW(x,y))
    {
        QMessageBox::about(this,"s","s");
        return true;
    }
    else
    {
        count=0;
        if(YiSi(x,y,point))
        {

            situation[x][y]=1;
            situation[point[0][0]][point[0][1]]=0;
            for(int i=0;i<15;i++)
            {
                for(int j=0;j<15;j++)
                {
                    if(situation[i][j]==-1)
                    {

                        if(VCT(i,j))
                        {
                            situation[point[0][0]][point[0][1]]=-1;


                            situation[x][y]=-1;
                            count++;
                            return true;
                        }
                    }

                }
            }
            situation[point[0][0]][point[0][1]]=-1;


            situation[x][y]=-1;


        }

        return false;
    }

}

bool MainWindow::YiSi(int x, int y, int point[2][2])
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=10&&j<=10)
            {
                if(situation[i][j]==1&&situation[i+1][j]==1&&situation[i+2][j]==1&&situation[i+3][j]==1&&((situation[i-1][j]==-1&&situation[i+4][j]==0)||(situation[i-1][j]==0&&situation[i+4][j]==-1)))
                {
                    if(situation[i-1][j]==-1)
                    {
                        point[0][0]=i-1;
                        point[0][1]=j;
                    }
                    else
                    {
                        point[0][0]=i+4;
                        point[0][1]=j;
                    }
                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i][j+1]==1&&situation[i][j+2]==1&&situation[i][j+3]==1&&((situation[i][j-1]==-1&&situation[i][j+4]==0)||(situation[i][j-1]==0&&situation[i][j+4]==-1)))
                {
                    if(situation[i][j-1]==-1)
                    {
                        point[0][0]=i;
                        point[0][1]=j-1;
                    }
                    else
                    {
                        point[0][0]=i;
                        point[0][1]=j+4;
                    }


                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==1&&situation[i+1][j+1]==1&&situation[i+2][j+2]==1&&situation[i+3][j+3]==1&&((situation[i-1][j-1]==-1&&situation[i+4][j+4]==0)||(situation[i-1][j-1]==0&&situation[i+4][j+4]==-1)))
                {
                    if(situation[i-1][j-1]==-1)
                    {
                        point[0][0]=i-1;
                        point[0][1]=j-1;
                    }
                    else
                    {
                        point[0][0]=i+4;
                        point[0][1]=j+4;
                    }

                    situation[x][y]=-1;
                    return true;

                }
            }

            if(i>=4&&i<=13&&j<=10&&j>=1)
            {
                if(situation[i][j]==1&&situation[i-1][j+1]==1&&situation[i-2][j+2]==1&&situation[i-3][j+3]==1&&((situation[i+1][j-1]==-1&&situation[i-4][j+4]==0)||(situation[i+1][j-1]==0&&situation[i-4][j+4]==-1)))
                {
                    if(situation[i+1][j-1]==-1)
                    {
                        point[0][0]=i+1;
                        point[0][1]=j-1;
                    }
                    else
                    {
                        point[0][0]=i-4;
                        point[0][1]=j+4;
                    }

                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;
}

bool MainWindow::YiSiL(int x, int y)
{
    situation[x][y]=1;
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(i>=1&&j>=1&&i<=10&&j<=10)
            {
                if(situation[i][j]==0&&situation[i+1][j]==0&&situation[i+2][j]==0&&situation[i+3][j]==0&&((situation[i-1][j]==-1&&situation[i+4][j]==1)||(situation[i-1][j]==1&&situation[i+4][j]==-1)))
                {


                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i][j+1]==0&&situation[i][j+2]==0&&situation[i][j+3]==0&&((situation[i][j-1]==-1&&situation[i][j+4]==1)||(situation[i][j-1]==1&&situation[i][j+4]==-1)))
                {



                    situation[x][y]=-1;
                    return true;
                }
                if(situation[i][j]==0&&situation[i+1][j+1]==0&&situation[i+2][j+2]==0&&situation[i+3][j+3]==0&&((situation[i-1][j-1]==-1&&situation[i+4][j+4]==1)||(situation[i-1][j-1]==1&&situation[i+4][j+4]==-1)))
                {


                    situation[x][y]=-1;
                    return true;

                }
            }

            if(i>=4&&i<=13&&j<=10&&j>=1)
            {
                if(situation[i][j]==0&&situation[i-1][j+1]==0&&situation[i-2][j+2]==0&&situation[i-3][j+3]==0&&((situation[i+1][j-1]==-1&&situation[i-4][j+4]==1)||(situation[i+1][j-1]==1&&situation[i-4][j+4]==-1)))
                {


                    situation[x][y]=-1;
                    return true;
                }
            }
        }
    }
    situation[x][y]=-1;
    return false;

}

void MainWindow::Default(int &x, int &y)
{
    int final=-1000;
    int themax=0;
    int pp[2][2];
    for(int i=0;i<15;i++)
    {

        for(int j=0;j<15;j++)
        {
            themax=0;
            if(situation[i][j]==-1)
            {
                if(situation[i][j]==-1&&SanLianW(i,j,pp))
                {
                    analy[i][j]=70;

                }
                else if(situation[i][j]==-1&&YiSi(i,j,pp))
                {
                    analy[i][j]=60;
                }

                else if(situation[i][j]==-1&&YiSanW(i,j))
                {
                    analy[i][j]=50;
                }
                else if(situation[i][j]==-1&&ErLianW(i,j))
                {
                    analy[i][j]=40;
                }
                else if(situation[i][j]==-1&&YiErW(i,j))
                {
                    analy[i][j]=30;
                }
                /*else if(situation[i][j]==-1&&i==8&&j==8)
                {
                    analy[i][j]==10;
                }*/
                else
                {

                    analy[i][j]=0;
                }

                /*situation[i][j]=1;
                for(int k=0;k<15;k++)
                {
                    for(int l=0;l<15;l++)
                    {

                        if(situation[k][l]==-1&&JudgeLose(k,l))
                        {
                            if(themax<100)
                            themax=100;
                        }
                        else if(situation[k][l]==-1&&SiLianL(k,l))
                        {
                            if(themax<90)
                            themax=90;
                        }
                        else if(situation[k][l]==-1&&ShuangSanL(k,l))
                        {
                            if(themax<80)
                            themax=80;
                        }
                        else if(situation[k][l]==-1&&SanLianL(k,l))
                        {
                            if(themax<110)
                            themax=110;
                        }
                        else if(situation[k][l]==-1&&YiSiL(k,l))
                        {
                            if(themax<60)
                                themax=60;
                        }
                        else if(situation[k][l]==-1&&YiSanL(k,l))
                        {
                            if(themax<50)
                                themax=50;
                        }
                        else if(situation[k][l]==-1&&ErLianL(k,l))
                        {
                            if(themax<40)
                                themax=40;
                        }
                        else if(situation[k][l]==-1&&YiErL(k,l))
                        {
                            if(themax<30)
                                themax=30;
                        }
                        else
                        {
                            if(themax<=0)
                            themax=0;
                        }

                    }

                }
                analy[i][j]-=themax;


                situation[i][j]=-1;
                */


                if(situation[i][j]==-1&&JudgeLose(i,j))
                {
                    //if(themax<100)
                    themax=100;
                }
                else if(situation[i][j]==-1&&SiLianL(i,j))
                {
                   // if(themax<90)
                    themax=90;
                }
                else if(situation[i][j]==-1&&ShuangSanL(i,j))
                {
                    //if(themax<80)
                    themax=80;
                }
                else if(situation[i][j]==-1&&SanLianL(i,j))
                {
                    //if(themax<110)
                    themax=70;
                }
                else if(situation[i][j]==-1&&YiSiL(i,j))
                {
                   // if(themax<60)
                        themax=60;
                }
                else if(situation[i][j]==-1&&YiSanL(i,j))
                {
                    //if(themax<50)
                        themax=50;
                }
                else if(situation[i][j]==-1&&ErLianL(i,j))
                {
                    //if(themax<40)
                        themax=40;
                }
                else if(situation[i][j]==-1&&YiErL(i,j))
                {
                    //if(themax<30)
                        themax=30;
                }
                else
                {
                    //if(themax<=0)
                    themax=0;
                }

                analy[i][j]+=themax;

            }
            else
            {
                analy[i][j]=-100000000000;
            }
        }
    }

    for(int a=0;a<15;a++)
    {
        for(int b=0;b<15;b++)
        {
            if(final<analy[a][b])
            {
                final=analy[a][b];
                x=a;
                y=b;
            }


        }
    }
    char f[10];
    itoa(final,f,10);
    QMessageBox::about(this,"e",f);


}

void MainWindow::Analysis(int &x, int &y)
{





    /////////////////////////////////////////能赢就赶紧
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&JudgeWin(i,j))
            {
                x=i;
                y=j;
                return;
            }
        }
    }
    ///////////////////////////////////////自己不能赢，优先把人家能赢得堵上
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&JudgeLose(i,j))
            {
                x=i;
                y=j;
                return;

            }

        }
    }
     /////////////////////////////////四连 两边没堵
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&SiLianW(i,j))
            {
                x=i;
                y=j;
                return;

            }
        }
    }

////////////////////////////////////////////VCT
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&VCT(i,j))
            {
                x=i;
                y=j;
                return;
            }
        }
    }


    //////////////////////////////////还是四连，别让别人连成两边没堵

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&SiLianL(i,j))
            {
                x=i;
                y=j;
                return;
            }
        }
    }

    ///////////////////////////////////双三赢
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&ShuangSanW(i,j))
            {
                QMessageBox::about(this,"d","d");
                x=i;
                y=j;
                return;
            }
        }
    }
    //////////////////////////////////双三输
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&ShuangSanL(i,j))
            {
                QMessageBox::about(this,"fang","fang");
                x=i;
                y=j;
                return;
            }
        }
    }






    /////////////////////////////////////默认的

   Default(x,y);
   return;

   int pp[2][2];


    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&SanLianW(i,j,pp))
            {
                x=i;
                y=j;
                return;
            }
        }
    }
    for(int i=0;i<15;i++)
    {
         for(int j=0;j<15;j++)
         {
                if(situation[i][j]==-1&&ErLianW(i,j))
                {
                    x=i;
                    y=j;
                    return;

                }
          }
     }

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1&&SanLianL(i,j))
            {
                x=i;
                y=j;
                return;
            }
        }
    }







   int x_s;
    int y_s;
    x_s=7;
    y_s=7;

    while(x_s<=14&&x_s>=0&&y_s>=0&&y_s<=14)
    {
        if(situation[x_s][y_s]==-1)
        {
            x=x_s;
            y=y_s;
            return;
        }
        else
        {
            x_s++;
            y_s++;
        }
    }
    while(x_s<=14&&x_s>=0&&y_s>=0&&y_s<=14)
    {
        if(situation[x_s][y_s]==-1)
        {
            x=x_s;
            y=y_s;
            return;
        }
        else
        {
            x_s--;
            y_s--;
        }
    }
    while(x_s<=14&&x_s>=0&&y_s>=0&&y_s<=14)
    {
        if(situation[x_s][y_s]==-1)
        {
            x=x_s;
            y=y_s;
            return;

        }
        else
        {
            x_s++;
            y_s++;
        }
    }

    for(int i=0;i<15;i++)
    {
        for(int j=0;j<15;j++)
        {
            if(situation[i][j]==-1)
            {
                x=i;
                y=j;
                return;
            }
        }
    }

    ////////////////////////////////////


}
