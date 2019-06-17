#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>
#include <QObject>
#include <QGridLayout>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtMath>

namespace Ui {
class MainView;
}

class MainView : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();

private slots:
    void serialReceived();

protected:
    void timerEvent(QTimerEvent *event);

private:
    Ui::MainView *ui;
    float m_realTime;
    int m_timerId;
    QTime m_time;
    QSerialPort *m_serial;
    QSerialPortInfo m_serialPortInfo;
    QByteArray m_readBytes;
    void showTime();
    void batteryStatus(double);
    void setTelemetry();
    void readSerialPort();
    void init();
};

#endif // MAINVIEW_H
