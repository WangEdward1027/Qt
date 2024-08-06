//用sender()和qobject_cast<>自定义槽函数，减少重复槽函数

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>

#define first_turn 'O' //O为先手

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _turn = first_turn;
    QObject::connect(ui->pushButton_1, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
    QObject::connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::do_btn_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//自定义槽函数: 9个转到槽生成的槽函数，变为一个自定义槽函数
void MainWindow::do_btn_clicked()
{
    QPushButton * pbtn = qobject_cast<QPushButton *> (sender()); //QObject *向下转型为QPushButton *

    if(!pbtn->text().isEmpty())  return; //为空才能占领
    pbtn->setText(_turn);

    //修改下次下棋的顺序
    if(_turn == 'O'){
        _turn = 'X';
    }else{
        _turn = 'O';
    }

    QString buttonName = pbtn->objectName();  //按钮名
    QString strnum = buttonName.right(1);     //按钮名最后一个数字
    int num = strnum.toInt();                 //转数字

    _stack.push(num);                         //压栈
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

    _turn = first_turn;
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
