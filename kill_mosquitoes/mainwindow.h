#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mypushbutton.h"
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void addScores(); //加分
private:
    Ui::MainWindow *ui;
    MyPushButton *mybtn;
    int _scores = 0;
};

#endif // MAINWINDOW_H
