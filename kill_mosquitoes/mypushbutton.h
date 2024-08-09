#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class MyPushButton : public QLabel
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev) override
    {
        emit mySignal();
    }
signals:
    void mySignal();
public slots:
    void mySlot(){
        int randomX = std::rand() % 600;
        int randomY = std::rand() % 400;

        this->move(randomX, randomY);
        qDebug() << "kill mosquito";
    }
};

#endif // MYPUSHBUTTON_H
