#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_0_clicked();

    void on_pushButton_plus_clicked();
    void on_pushButton_subtract_clicked();
    void on_pushButton_multiply_clicked();
    void on_pushButton_divide_clicked();
    void on_pushButton_equal_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_AC_clicked();

private:
    Ui::MainWindow *ui;
    QString _str;
};
#endif // MAINWINDOW_H
