#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    mosquito_x = rand()%560;
    mosquito_y = rand()%360;
    
}
