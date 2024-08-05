#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

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

void MainWindow::on_pushButton_1_clicked()
{
    _str += "1";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_2_clicked()
{
    _str += "2";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_3_clicked()
{
    _str += "3";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_4_clicked()
{
    _str += "4";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_5_clicked()
{
    _str += "5";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_6_clicked()
{
    _str += "6";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_7_clicked()
{
    _str += "7";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_8_clicked()
{
    _str += "8";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_9_clicked()
{
    _str += "9";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_0_clicked()
{
    _str += "0";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_plus_clicked()
{
    _str += "+";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_subtract_clicked()
{
    _str += "-";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_multiply_clicked()
{
    _str += "*";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_divide_clicked()
{
    _str += "/";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_equal_clicked()
{
    _str += "=";
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_del_clicked()
{
    _str.chop(1);
    ui->output->setText(_str);
}

void MainWindow::on_pushButton_AC_clicked()
{
    _str.clear();
    ui->output->setText(_str);
}
