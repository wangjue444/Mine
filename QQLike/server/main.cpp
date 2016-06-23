#include <QtCore/QCoreApplication>
#include "SAP.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SAP  sap;
    return a.exec();
}
