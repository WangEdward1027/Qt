//QTimer定时器
//加入模态对话框，发现不会阻塞主窗口QTimer的刷新

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
    showTime(); //先手动调用一次槽函数,以在刚开始时就显示时间
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

void MainWindow::on_pushButton_clicked()
{
    //    QDialog dialog(this);
    //    dialog.setWindowTitle("模态对话框");
    //    dialog.exec();  //弹出模态对话框
    QMessageBox::StandardButton btn = QMessageBox::information(
                this,                             // 父窗口
                "模态对话框",                       // 标题
                "看看QTimer时间是否有卡住？",         // 消息内容
                QMessageBox::Ok | QMessageBox::No // 按钮类型
                );
}
