#include <QtGui/QApplication>
#include "widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.startcv();
    return a.exec();
}
