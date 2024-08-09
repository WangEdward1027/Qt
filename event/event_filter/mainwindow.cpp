#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    out = new Out(this);
    out->resize(500,500);  //头文件 <QWidget>
    out->setFrameStyle(QFrame::Panel | QFrame::Plain);

    mid = new Mid(out);
    mid->resize(400,400);
    mid->setFrameStyle(QFrame::Panel | QFrame::Plain);

    in = new In(mid);
    in->resize(300,300);
    in->setFrameStyle(QFrame::Panel | QFrame::Plain);

    filter = new MyFilter(this);
    out->installEventFilter(filter);
    mid->installEventFilter(filter);
    in->installEventFilter(filter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ++_times;
    ui->pushButton->setText( QString("clicked times: %1").arg(_times) );
    qDebug() << "clicked pushButton" ;
}
