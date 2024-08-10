#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QTcpSocket(this);

    //连接状态一改变,就打印一次
    QObject::connect(socket, &QTcpSocket::stateChanged, this, &MainWindow::do_status_changed);
    //连接完成,通知可以进行写操作
    QObject::connect(socket, &QTcpSocket::connected, this, &MainWindow::do_connected_send);
    //可读状态,调用读取的槽函数
    QObject::connect(socket, &QTcpSocket::readyRead, this, &MainWindow::do_readyRead_show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    socket->connectToHost("www.baidu.com" ,80);
}

void MainWindow::do_status_changed(QAbstractSocket::SocketState socketState)
{
    qDebug() << "current state = " << socketState;
}

void MainWindow::do_connected_send()
{
    qDebug() << "send request";
    QByteArray request("GET / HTTP/1.1\r\n\r\n");
    socket->write(request);
}

void MainWindow::do_readyRead_show()
{
    qDebug() << "show response";
    QByteArray response = socket->readAll();
    content += QString(response);
    ui->textBrowser->setText(content);
    //ui->webEngineView->setHtml(content);
}

