#include "listdialog.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    listdialog w;
    w.show();

    return a.exec();
}
