//用sender()和qobject_cast<>自定义槽函数，减少重复槽函数

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStack>
#include <QChar>
#include <QPushButton>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    //自定义槽函数
    void do_btn_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_undo_clicked();

private:
    Ui::MainWindow *ui;
    QStack<int> _stack;      //为了undo悔棋
    QChar _turn;      //为了判断下一次该谁下棋
};
#endif // MAINWINDOW_H
