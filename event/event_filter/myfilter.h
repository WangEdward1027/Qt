#ifndef MYFILTER_H
#define MYFILTER_H

#include <QObject>
#include <QEvent>
#include <QDebug>

class MyFilter : public QObject
{
    Q_OBJECT
public:
    explicit MyFilter(QObject *parent = nullptr);
    bool eventFilter(QObject *watched, QEvent *ev) override
    {
        if(ev->type() == QEvent::MouseButtonPress){
            qDebug() << watched << "filter is pressed!";
        }
        return false;
    }
signals:

};

#endif // MYFILTER_H
