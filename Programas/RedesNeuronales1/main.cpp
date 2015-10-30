#include "red.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Red w;
    w.show();

    return a.exec();
}
