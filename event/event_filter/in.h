#ifndef IN_H
#define IN_H

#include <QLabel>
#include <QEvent>
#include <QDebug>
#include <QMessageBox>
#include <QMouseEvent>
#include <QString>

class Out
:public QLabel
{
    Q_OBJECT
public:
    explicit Out(QWidget *parent = nullptr);
    bool event(QEvent *ev) override
    {
        if(ev->type() == QEvent::MouseButtonPress){
            qDebug() << "Out : event" << ev->type();
        }
        return QLabel::event(ev);
    }

    //event_handler
    void mousePressEvent(QMouseEvent *ev) override
    {  //ev是子类类型
        qDebug() << "Out : event handler : mousePressEvent";
        ev->ignore();
    }
signals:
};

class Mid
:public QLabel
{
    Q_OBJECT
public:
    explicit Mid(QWidget *parent = nullptr);
    bool event(QEvent *ev) override
    {
        if(ev->type() == QEvent::MouseButtonPress){
            qDebug() << "Mid : event" << ev->type();
            return true;  // 仅拦截鼠标点击事件
        }
        return QLabel::event(ev);
    }

    void mousePressEvent(QMouseEvent *ev) override
    {  //ev是子类类型
        qDebug() << "Mid : event handler : mousePressEvent";
        ev->ignore();
    }
signals:
};

class In
: public QLabel
{
    Q_OBJECT
public:
    explicit In(QWidget *parent = nullptr);
    bool event(QEvent *ev) override
    {
        if(ev->type() == QEvent::MouseButtonPress){
            qDebug() << "In : event" << ev->type();
        }
        return QLabel::event(ev);
    }

    void mousePressEvent(QMouseEvent *ev) override //只要存在handler，这件事就默认是完成的
    {  //ev是子类类型
        qDebug() << "In : event handler : mousePressEvent";
        ev->ignore();
    }
signals:
};

#endif // A_H
