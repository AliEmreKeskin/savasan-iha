#include "mainview.h"
#include "ui_mainview.h"
#include "utils.h"
#include <QDebug>

MainView::MainView(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainView){
    init();
    setTelemetry();
    showTime();
    readSerialPort();
}

void MainView::init(){
    ui->setupUi(this);
    m_timerId = startTimer(0);
    m_time.start();

    QPixmap status_GPS;
    QPixmap status_Overspeed;
    QPixmap status_Battery;
    QPixmap status_Autopilot;
    status_GPS.load(":root/images/led_green2.png");
    status_Overspeed.load(":root/images/led_grey.fw.png");
    status_Battery.load(":root/images/led_green2.png");
    status_Autopilot.load(":root/images/led_red.png");
    ui->ledStatus_GPS->setPixmap(status_GPS);
    ui->ledStatus_Overspeed->setPixmap(status_Overspeed);
    ui->ledStatus_Battery->setPixmap(status_Battery);
    ui->ledStatus_Autopilot->setPixmap(status_Autopilot);
}

void MainView::readSerialPort(){
    m_serial = new QSerialPort(this);
    m_serial->setPortName("/dev/ttyUSB0");
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);
    m_serial->open(QIODevice::ReadOnly);
    connect(m_serial, SIGNAL(readyRead()), this, SLOT(serialReceived()));
}

void MainView::serialReceived(){
    m_readBytes = m_serial->readAll();
}

void MainView::timerEvent(QTimerEvent *event)
{
    QMainWindow::timerEvent(event);
    float timeStep = m_time.restart();

    m_realTime = m_realTime + timeStep / 1000.0f;

    float alpha     =  0.0f;
    float beta      =  0.0f;
    float roll      =  0.0f;
    float pitch     =  0.0f;
    float heading   =  0.0f;
    float slipSkid  =  0.0f;
    float turnRate  =  0.0f;
    float devH      =  0.0f;
    float devV      =  0.0f;
    float airspeed  =  0.0f;
    float altitude  =  0.0f;
    float pressure  = 28.0f;
    float climbRate =  0.0f;
    float machNo    =  0.0f;
    float adf       =  0.0f;
    float dme       =  0.0f;

    QRegExp rx("[; ]");
    QString telemetry = QString::fromLatin1(m_readBytes.data());

    //altitude = telemetry.split(rx, QString::SkipEmptyParts).at(0).toFloat();
    /*heading = telemetry.split(rx, QString::SkipEmptyParts).at(2).toFloat();
    roll = telemetry.split(rx, QString::SkipEmptyParts).at(2).toFloat();
    pitch = telemetry.split(rx, QString::SkipEmptyParts).at(2).toFloat();
    airspeed = telemetry.split(rx, QString::SkipEmptyParts).at(2).toFloat();*/

    qDebug() << telemetry;

    //altitude  = 9000.0f * sin( m_realTime /  40.0f ) + 9000.0f;
    //airspeed  =  125.0f * sin( m_realTime /  40.0f ) +  125.0f;
    //roll      =  180.0f * sin( m_realTime /  10.0f );
    //pitch     =  90.0f * sin( m_realTime /  20.0f );
    //heading   =  360.0f * sin( m_realTime /  40.0f );

    ui->le_Altitude->setText(QString::number(altitude));
    ui->le_Speed->setText(QString::number(airspeed));
    ui->le_Roll->setText(QString::number(roll));
    ui->le_Pitch->setText(QString::number(pitch));
    ui->le_Yaw->setText(QString::number(heading));

    ui->widgetPFD->setFlightPathMarker ( alpha, beta );
    ui->widgetPFD->setRoll          ( roll     );
    ui->widgetPFD->setPitch         ( pitch     );
    ui->widgetPFD->setSlipSkid      ( slipSkid  );
    ui->widgetPFD->setTurnRate      ( turnRate / 6.0f );
    ui->widgetPFD->setDevH          ( devH      );
    ui->widgetPFD->setDevV          ( devV      );
    ui->widgetPFD->setHeading       ( heading   );
    ui->widgetPFD->setAirspeed      ( airspeed  );
    ui->widgetPFD->setMachNo        ( machNo    );
    ui->widgetPFD->setAltitude      ( altitude  );
    ui->widgetPFD->setPressure      ( pressure  );
    ui->widgetPFD->setClimbRate     ( climbRate / 100.0f );
    ui->widgetPFD->setIdentifier    ( "ILAX" , true );
    ui->widgetPFD->setDistance      ( dme    , true );

    ui->widgetALT->setAltitude(altitude);
    ui->widgetASI->setAirspeed(airspeed);
    ui->widgetADI->setRoll(roll);
    ui->widgetADI->setPitch(pitch);
    ui->widgetHSI->setHeading(heading);

    ui->widgetALT->update();
    ui->widgetASI->update();
    ui->widgetADI->update();
    ui->widgetHSI->update();
    ui->widgetPFD->update();
}

void MainView::setTelemetry()
{
    QJsonObject telemetry = ReadJSONFile("telemetry.json");
//    ui->leLatitude->setText(QString::number(telemetry["latitude"].toDouble()));
//    ui->leLongitude->setText(QString::number(telemetry["longitude"].toDouble()));
//    ui->leAltitude->setText(QString::number(telemetry["altitude"].toDouble()));
//    ui->lePitch->setText(QString::number(telemetry["pitch"].toDouble()));
//    ui->leYaw->setText(QString::number(telemetry["yaw"].toDouble()));
//    ui->leRoll->setText(QString::number(telemetry["roll"].toDouble()));
//    ui->leSpeed->setText(QString::number(telemetry["speed"].toDouble()));
//    ui->leBattery->setText(QString::number(telemetry["battery"].toDouble()));

    batteryStatus(telemetry["battery"].toDouble());
}

void MainView::batteryStatus(double batteryLevel)
{
    QPixmap pix;

    if(batteryLevel > 75)
        pix.load(":/root/images/battery_full.png");
    else if(batteryLevel > 50)
        pix.load(":/root/images/battery_good.png");
    else if(batteryLevel > 15)
        pix.load(":/root/images/battery_medium.png");
    else
        pix.load(":/root/images/battery_low.png");

    ui->imgBattery->setPixmap(pix);
}

void MainView::showTime()
{
    QWidget *widget=new QWidget();
    QGridLayout *layout=new QGridLayout(widget);
    QWidget *widget2=new QWidget();
    QGridLayout *layout2=new QGridLayout(widget2);
    layout->addWidget(ui->label_9,0,0);
    layout->addWidget(ui->lbCurrentTime,0,1);
    layout2->addWidget(ui->label_10,0,0);
    layout2->addWidget(ui->lbElapsedTime,0,1);
    ui->statusBar->addPermanentWidget(widget,0); // Aligns right
    ui->statusBar->addWidget(widget2,0); // Aligns left

    QTimer *t = new QTimer(this);
    t->setInterval(1000);
    connect(t, &QTimer::timeout, [&]() {
       QString time1 = QTime::currentTime().toString();
       ui->lbCurrentTime->setText(time1);
       static int count = 0;
       if(count%60 < 10)
       {
           if(count/60 < 10)
               ui->lbElapsedTime->setText("0" + QString::number(count/60) + ":0" + QString::number(count%60));
           else
               ui->lbElapsedTime->setText(QString::number(count/60) + ":0" + QString::number(count%60));
       }
       else
       {
           if(count/60 < 10)
               ui->lbElapsedTime->setText("0" + QString::number(count/60) + ":" + QString::number(count%60));
           else
               ui->lbElapsedTime->setText(QString::number(count/60) + ":" + QString::number(count%60));
       }
       count++;
    } );
    t->start();
}

MainView::~MainView()
{
    delete ui;
}
