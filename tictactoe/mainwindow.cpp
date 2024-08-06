#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#define first_turn 'O'//O为先手
#define last_turn  'X'//X为后手

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _stack_turn.push(first_turn); //O为先手
}

MainWindow::~MainWindow()
{
    delete ui;
}

//定一个所有按钮的公有函数
//void MainWindow::public_pushButtion_clicked(QPushButton * pbtn)
//{
//    if(ui->pbtn->text().isEmpty()){ //为空才能占领
//        QChar turn;
//        if(!_stack_turn.empty()){
//            turn = _stack_turn.pop();
//            if(turn == 'O'){
//                _stack_turn.push('X');
//            }else{
//                _stack_turn.push('O');
//            }
//        }else{ //第一步:先手下
//            turn = first_turn;
//            _stack_turn.push(last_turn);
//        }

//        ui->pbtn->setText(turn);

//        _stack.push(1);
//    }
//}

void MainWindow::on_pushButton_1_clicked()
{
    if(ui->pushButton_1->text().isEmpty()){ //为空才能占领
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{ //第一步:先手下
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_1->setText(turn);

        _stack.push(1);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->pushButton_2->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_2->setText(turn);

        _stack.push(2);
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(ui->pushButton_3->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_3->setText(turn);

        _stack.push(3);
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if(ui->pushButton_4->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_4->setText(turn);

        _stack.push(4);
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_5->setText(turn);

        _stack.push(5);
    }
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_6->setText(turn);

        _stack.push(6);
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    if(ui->pushButton_7->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_7->setText(turn);

        _stack.push(7);
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if(ui->pushButton_8->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_8->setText(turn);

        _stack.push(8);
    }
}

void MainWindow::on_pushButton_9_clicked()
{
    if(ui->pushButton_9->text().isEmpty()){
        QChar turn;
        if(!_stack_turn.empty()){
            turn = _stack_turn.pop();
            if(turn == 'O'){
                _stack_turn.push('X');
            }else{
                _stack_turn.push('O');
            }
        }else{
            turn = first_turn;
            _stack_turn.push(last_turn);
        }

        ui->pushButton_9->setText(turn);

        _stack.push(9);
    }
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

    _stack_turn.clear();
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
