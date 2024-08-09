#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets/QtWidgets>
#include <time.h>
#include <stdlib.h>
class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *event) override{
        //srand(time(nullptr));
        if(event->x() - mosquito_x <= 40 && event->x() - mosquito_x >= 0
                && event->y() - mosquito_y <= 40 && event->y() - mosquito_y >= 0){
            emit addPoint();
            mosquito_x = rand()%560;
            mosquito_y = rand()%360;
            update(); // 强制重绘
        }
        QWidget::mousePressEvent(event);
    }
    void paintEvent(QPaintEvent *event) override{
        qDebug() << mosquito_x << "," << mosquito_y;
        QPainter painter(this);
        QPixmap pixmap(":/new/prefix1/mosquito.jpeg");
        painter.drawPixmap(mosquito_x,mosquito_y,40,40,pixmap);
        QWidget::paintEvent(event);
    }
signals:
    void addPoint();
private:
    int mosquito_x;
    int mosquito_y;
};

#endif // MYWIDGET_H
