#include "slideinggamemainwindow.h"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    SlideingGameMainWindow w;
    w.show();
    return a.exec();
}
