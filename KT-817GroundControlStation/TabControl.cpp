#include "TabControl.h"
#include "ui_TabControl.h"

TabControl::TabControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TabControl)
{
    ui->setupUi(this);
    m_timerId = startTimer(0);
    m_time.start();
}

void TabControl::timerEvent(QTimerEvent *event)
{
    QWidget::timerEvent(event);
    float timeStep = m_time.restart();

    m_realTime = m_realTime + timeStep / 1000.0f;

    float altitude = 0.0f;
    float airspeed = 0.0f;
    float roll = 0.0f;
    float pitch = 0.0f;

//    altitude  = 9000.0f * sin( m_realTime /  40.0f ) + 9000.0f;
//    airspeed  =  125.0f * sin( m_realTime /  40.0f ) +  125.0f;
//    roll      =  180.0f * sin( m_realTime /  10.0f );
//    pitch     =  90.0f * sin( m_realTime /  20.0f );

    ui->widgetALT->setAltitude(altitude);
    ui->widgetASI->setAirspeed(airspeed);
    ui->widgetADI->setRoll(roll);
    ui->widgetADI->setPitch(pitch);
    ui->widgetALT->update();
    ui->widgetASI->update();
    ui->widgetADI->update();
}

TabControl::~TabControl()
{
    delete ui;
}
