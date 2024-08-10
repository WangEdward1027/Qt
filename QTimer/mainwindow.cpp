#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();

    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
    showTime();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    QString text = QString("current time is %1").arg(QTime::currentTime().toString());
    ui->textBrowser->setText(text);
}
