#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QtWidgets>

int main(int argc, char *argv[])
{    
    QApplication a(argc, argv);  //创建一个应用程序实例，这是Qt应用程序的基础

    QThread child;  //创建一个新的线程对象

    Worker * worker = new Worker;   //创建一个Worker对象, 实际的工作将在该对象中执行
    worker->moveToThread(&child);

    QWidget w;
    w.resize(800,600);
    QGridLayout layout;
    w.setLayout(&layout);

    QLabel l1(&w);
    layout.addWidget(&l1,1,1);

    QPushButton btn1("start",&w);
    layout.addWidget(&btn1,2,1);

    QObject::connect(&btn1,&QPushButton::clicked,worker,&Worker::childSlot); //点击按钮,执行
    QObject::connect(&child, &QThread::finished, worker, &QObject::deleteLater);  //线程结束时，自动删除Worker对象,因为没有对象树
    QObject::connect(worker, &Worker::childSignal, [&](){  //worker发出childSignal信号,将label内容更新为done
        l1.setText("done");
    });

    child.start();   //启动child线程，线程开始运行

    w.show();   //显示窗口
    return a.exec();   //进入应用程序的事件循环，等待用户操作
}
