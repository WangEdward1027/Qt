#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //model
    model = new QStandardItemModel(2, 5, this);

    //view
    view = new QTableView(this);
    view->setModel(model);  //接下来,view的内容,由model决定

    btn = new QPushButton("add row", this);
    layout = new QHBoxLayout;
    layout->addWidget(view);
    layout->addWidget(btn);
    ui->centralwidget->setLayout(layout);

    QStringList headers = {"birth", "name", "age", "job", "image"};
    model->setHorizontalHeaderLabels(headers);

    //第一行
    QStandardItem *birth= new QStandardItem("1027");
    QStandardItem *name = new QStandardItem("Edward");
    QStandardItem *age = new QStandardItem("25");
    QStandardItem *job = new QStandardItem("Research & Development");
    QStandardItem *image = new QStandardItem(QIcon(":/new/prefix1/images/photo1.jpg"), "pthot1");
    model->setItem(0, 0, birth);
    model->setItem(0, 1, name);
    model->setItem(0, 2, age);
    model->setItem(0, 3, job);
    model->setItem(0, 4, image);

    //第二行
    birth = new QStandardItem("1202");
    name = new QStandardItem("Amber");
    age = new QStandardItem("25");
    job = new QStandardItem("Product Manager");
    image = new QStandardItem(QIcon(":/new/prefix1/images/photo2.jpg"), "photo2");
    model->setItem(1, 0, birth);
    model->setItem(1, 1, name);
    model->setItem(1, 2, age);
    model->setItem(1, 3, job);
    model->setItem(1, 4, image);

    QObject::connect(btn ,&QPushButton::clicked, this, &MainWindow::addRow);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addRow()
{
    QStandardItem *birth = new QStandardItem("0811");
    QStandardItem *name = new QStandardItem("Sam");
    QStandardItem *age = new QStandardItem("25");
    QStandardItem *job = new QStandardItem("Quality Assurance");
    QStandardItem *image = new QStandardItem(QIcon(":/new/prefix1/images/photo3.jpg"),"photo3");
    QList<QStandardItem *> list;
    list << birth << name << age << job << image;
    model->appendRow(list);
}
