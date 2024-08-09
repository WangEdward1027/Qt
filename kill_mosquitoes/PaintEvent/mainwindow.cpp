#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(nullptr));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePoint(){
    int score = ui->score->text().toInt();
    score += 10;
    ui->score->setText(QString("%1").arg(score));
}
