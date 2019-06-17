#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QPixmap>
#include <QVector>

class MyWidget : public QWidget
{
    Q_OBJECT
public:

protected:
    void paintEvent(QPaintEvent *event);
signals:

public slots:
};

#endif // MYWIDGET_H
