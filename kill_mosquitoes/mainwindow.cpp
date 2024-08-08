#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mypushbutton.h"
#include <QPixmap> //将图片从磁盘加载到内存

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->resize(800, 600);

    mybtn = new MyPushButton(this);
    mybtn->resize(100, 100);

    QPixmap pixmap(":/new/prefix1/images/mos.jpg");
    mybtn->setPixmap(pixmap);

    QObject::connect(mybtn , &MyPushButton::mySignal, mybtn, &MyPushButton::mySlot);
    QObject::connect(mybtn , &MyPushButton::mySignal, this, &MainWindow::addScores);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addScores()
{
    _scores += 10;
    ui->label->setText( QString("scores : %1").arg(_scores));
}
