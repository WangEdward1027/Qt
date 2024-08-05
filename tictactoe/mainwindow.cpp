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
    if(ui->pushButton_1->text().isEmpty()){
        ui->pushButton_1->setText("O");
        _stack.push(1);
        return;
    }

    if(ui->pushButton_1->text() == "X"){
        ui->pushButton_1->setText("O");
    }else{
        ui->pushButton_1->setText("X");
    }

    _stack.push(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text().isEmpty()){
        ui->pushButton_2->setText("O");
        _stack.push(2);
        return;
    }

    if(ui->pushButton_2->text() == "X"){
        ui->pushButton_2->setText("O");
    }else{
        ui->pushButton_2->setText("X");
    }

    _stack.push(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text().isEmpty()){
        ui->pushButton_3->setText("O");
        _stack.push(3);
        return;
    }

    if(ui->pushButton_3->text() == "X"){
        ui->pushButton_3->setText("O");
    }else{
        ui->pushButton_3->setText("X");
    }

    _stack.push(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text().isEmpty()){
        ui->pushButton_4->setText("O");
        _stack.push(4);
        return;
    }

    if(ui->pushButton_4->text() == "X"){
        ui->pushButton_4->setText("O");
    }else{
        ui->pushButton_4->setText("X");
    }

    _stack.push(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text().isEmpty()){
        ui->pushButton_5->setText("O");
        _stack.push(5);
        return;
    }

    if(ui->pushButton_5->text() == "X"){
        ui->pushButton_5->setText("O");
    }else{
        ui->pushButton_5->setText("X");
    }

    _stack.push(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text().isEmpty()){
        ui->pushButton_6->setText("O");
        _stack.push(6);
        return;
    }

    if(ui->pushButton_6->text() == "X"){
        ui->pushButton_6->setText("O");
    }else{
        ui->pushButton_6->setText("X");
    }

    _stack.push(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_7->text().isEmpty()){
        ui->pushButton_7->setText("O");
        _stack.push(7);
        return;
    }

    if(ui->pushButton_7->text() == "X"){
        ui->pushButton_7->setText("O");
    }else{
        ui->pushButton_7->setText("X");
    }

    _stack.push(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    if(ui->pushButton_8->text().isEmpty()){
        ui->pushButton_8->setText("O");
        _stack.push(8);
        return;
    }

    if(ui->pushButton_8->text() == "X"){
        ui->pushButton_8->setText("O");
    }else{
        ui->pushButton_8->setText("X");
    }

    _stack.push(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    if(ui->pushButton_9->text().isEmpty()){
        ui->pushButton_9->setText("O");
        _stack.push(9);
        return;
    }

    if(ui->pushButton_9->text() == "X"){
        ui->pushButton_9->setText("O");
    }else{
        ui->pushButton_9->setText("X");
    }

    _stack.push(9);
}

void MainWindow::on_pushButton_clear_clicked()
{
    ui->pushButton_1->setText("");
    ui->pushButton_2->setText("");
    ui->pushButton_3->setText("");
    ui->pushButton_4->setText("");
    ui->pushButton_5->setText("");
    ui->pushButton_6->setText("");
    ui->pushButton_7->setText("");
    ui->pushButton_8->setText("");
    ui->pushButton_9->setText("");
}

void MainWindow::on_pushButton_undo_clicked()
{
    if(!_stack.isEmpty()){
        int popBtnNum = _stack.pop();
        switch(popBtnNum)
        {
            case 1: ui->pushButton_1->setText(""); break;
            case 2: ui->pushButton_2->setText(""); break;
            case 3: ui->pushButton_3->setText(""); break;
            case 4: ui->pushButton_4->setText(""); break;
            case 5: ui->pushButton_5->setText(""); break;
            case 6: ui->pushButton_6->setText(""); break;
            case 7: ui->pushButton_7->setText(""); break;
            case 8: ui->pushButton_8->setText(""); break;
            case 9: ui->pushButton_9->setText(""); break;
            default:break;
        }
    }
}
