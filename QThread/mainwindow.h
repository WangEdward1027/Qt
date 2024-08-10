#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

class Worker: public QObject {
    Q_OBJECT
public:
    Worker(){}
signals:
    void childSignal();
public slots:
    void childSlot(){    //子线程槽函数
        qDebug() << "before I am child";
        QThread::sleep(5);  //模拟任务执行
        qDebug() << "after I am child";
        emit childSignal(); //任务完成,发射信号
    }
};

#endif // MAINWINDOW_H
