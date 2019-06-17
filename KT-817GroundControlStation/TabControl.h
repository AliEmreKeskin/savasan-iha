#ifndef TABCONTROL_H
#define TABCONTROL_H

#include <QWidget>
#include <QTime>

namespace Ui {
class TabControl;
}

class TabControl : public QWidget
{
    Q_OBJECT

public:
    explicit TabControl(QWidget *parent = nullptr);
    ~TabControl();

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::TabControl *ui;
    QTime m_time;
    float m_realTime;
    int m_timerId;
};
#endif // TABCONTROL_H
