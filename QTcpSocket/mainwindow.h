#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket> //pro文件里,添加 QT += network
//#include <QWebEngineView>

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
    void on_pushButton_clicked();
    void do_status_changed(QAbstractSocket::SocketState socketState);
    void do_connected_send();
    void do_readyRead_show();
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QString content;
};
#endif // MAINWINDOW_H
