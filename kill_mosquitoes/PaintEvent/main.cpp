#include "mainwindow.h"
#include "mywidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MyWidget *pw = new MyWidget(&w);
    pw->move(50,50);
    pw->resize(600,400);
    QObject::connect(pw,&MyWidget::addPoint, &w, &MainWindow::changePoint);
    w.show();
    return a.exec();
}
