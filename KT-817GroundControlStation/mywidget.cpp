#include "mywidget.h"

void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    // Altitude scheme
    painter.drawLine(490,5,490,205);
    int lineNum = 1;

    for(int i = 1; lineNum < 6; i+=10)
    {
        painter.drawLine(480,i*5,490,i*5);
        lineNum++;
    }

    lineNum = 1;
    for(int i = 6; lineNum < 5; i+=10)
    {
        painter.drawLine(485,i*5,490,i*5);
        lineNum++;
    }

    painter.drawText(460,10,"400");
    painter.drawText(460,60,"300");
    painter.drawText(460,110,"200");
    painter.drawText(460,160,"100");
    painter.drawText(470,210,"0");

}



