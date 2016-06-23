#include <QtGui/QApplication>
#include <QWidget>
#include "CAP.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb2312"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("gb2312"));

    Client c;
    return a.exec();
}
