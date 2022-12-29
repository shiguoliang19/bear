#include "easyvpn.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EasyVPN w;
    w.show();
    return a.exec();
}
