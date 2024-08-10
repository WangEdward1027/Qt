#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QString>
#include <QByteArray>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString filepath = QFileDialog::getOpenFileName(this, "open file");
    file = new QFile(filepath, this);
    file->open(QIODevice::ReadWrite);
    QByteArray array = file->readAll();
    ui->textBrowser->setText(QString(array));  //仅浏览
    ui->textEdit->setText(QString(array));     //可浏览,可编辑
}
