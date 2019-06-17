/********************************************************************************
** Form generated from reading UI file 'mainview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVIEW_H
#define UI_MAINVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "widgetadi.h"
#include "widgetalt.h"
#include "widgetasi.h"
#include "widgethsi.h"
#include "widgetpfd.h"

QT_BEGIN_NAMESPACE

class Ui_MainView
{
public:
    QWidget *centralWidget;
    WidgetASI *widgetASI;
    QLabel *label;
    QLabel *label_9;
    QLabel *lbCurrentTime;
    QLabel *label_10;
    QLabel *lbElapsedTime;
    QLineEdit *le_Speed;
    QLineEdit *le_Altitude;
    QLabel *label_3;
    WidgetALT *widgetALT;
    QLineEdit *le_Yaw;
    QLabel *label_4;
    WidgetADI *widgetADI;
    QLineEdit *le_Roll;
    QLabel *label_5;
    WidgetHSI *widgetHSI;
    QLineEdit *le_Pitch;
    QGroupBox *groupBox;
    QLabel *imgBattery;
    QLabel *label_13;
    WidgetPFD *widgetPFD;
    QGroupBox *groupBox_2;
    QLabel *ledStatus_GPS;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QLabel *ledStatus_Overspeed;
    QLabel *label_8;
    QLabel *label_11;
    QLabel *ledStatus_Battery;
    QLabel *label_12;
    QLabel *ledStatus_Autopilot;
    QGroupBox *groupBox_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_14;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainView)
    {
        if (MainView->objectName().isEmpty())
            MainView->setObjectName(QStringLiteral("MainView"));
        MainView->resize(1023, 595);
        QIcon icon;
        icon.addFile(QStringLiteral(":/root/images/Logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainView->setWindowIcon(icon);
        centralWidget = new QWidget(MainView);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widgetASI = new WidgetASI(centralWidget);
        widgetASI->setObjectName(QStringLiteral("widgetASI"));
        widgetASI->setGeometry(QRect(10, 40, 141, 91));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 61, 16));
        label->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(880, 550, 67, 16));
        lbCurrentTime = new QLabel(centralWidget);
        lbCurrentTime->setObjectName(QStringLiteral("lbCurrentTime"));
        lbCurrentTime->setGeometry(QRect(950, 550, 62, 16));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(30, 560, 67, 16));
        lbElapsedTime = new QLabel(centralWidget);
        lbElapsedTime->setObjectName(QStringLiteral("lbElapsedTime"));
        lbElapsedTime->setGeometry(QRect(100, 560, 47, 16));
        le_Speed = new QLineEdit(centralWidget);
        le_Speed->setObjectName(QStringLiteral("le_Speed"));
        le_Speed->setGeometry(QRect(30, 140, 101, 20));
        le_Altitude = new QLineEdit(centralWidget);
        le_Altitude->setObjectName(QStringLiteral("le_Altitude"));
        le_Altitude->setGeometry(QRect(200, 140, 101, 20));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(220, 20, 61, 16));
        label_3->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        widgetALT = new WidgetALT(centralWidget);
        widgetALT->setObjectName(QStringLiteral("widgetALT"));
        widgetALT->setGeometry(QRect(180, 40, 141, 91));
        le_Yaw = new QLineEdit(centralWidget);
        le_Yaw->setObjectName(QStringLiteral("le_Yaw"));
        le_Yaw->setGeometry(QRect(200, 310, 101, 20));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(230, 190, 61, 16));
        label_4->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        widgetADI = new WidgetADI(centralWidget);
        widgetADI->setObjectName(QStringLiteral("widgetADI"));
        widgetADI->setGeometry(QRect(10, 210, 141, 91));
        le_Roll = new QLineEdit(centralWidget);
        le_Roll->setObjectName(QStringLiteral("le_Roll"));
        le_Roll->setGeometry(QRect(30, 310, 101, 20));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 190, 91, 16));
        label_5->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        widgetHSI = new WidgetHSI(centralWidget);
        widgetHSI->setObjectName(QStringLiteral("widgetHSI"));
        widgetHSI->setGeometry(QRect(180, 210, 141, 91));
        le_Pitch = new QLineEdit(centralWidget);
        le_Pitch->setObjectName(QStringLiteral("le_Pitch"));
        le_Pitch->setGeometry(QRect(30, 340, 101, 20));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(730, 380, 271, 171));
        groupBox->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        imgBattery = new QLabel(groupBox);
        imgBattery->setObjectName(QStringLiteral("imgBattery"));
        imgBattery->setGeometry(QRect(150, 30, 101, 111));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(70, 60, 61, 51));
        label_13->setStyleSheet(QStringLiteral("font: 75 20pt \"Arial\";"));
        widgetPFD = new WidgetPFD(centralWidget);
        widgetPFD->setObjectName(QStringLiteral("widgetPFD"));
        widgetPFD->setGeometry(QRect(340, 40, 421, 311));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 380, 681, 171));
        groupBox_2->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        ledStatus_GPS = new QLabel(groupBox_2);
        ledStatus_GPS->setObjectName(QStringLiteral("ledStatus_GPS"));
        ledStatus_GPS->setGeometry(QRect(20, 30, 21, 21));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 30, 91, 21));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(22, 112, 78, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(140, 112, 88, 16));
        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(22, 134, 91, 22));
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(140, 134, 91, 22));
        ledStatus_Overspeed = new QLabel(groupBox_2);
        ledStatus_Overspeed->setObjectName(QStringLiteral("ledStatus_Overspeed"));
        ledStatus_Overspeed->setGeometry(QRect(20, 60, 21, 21));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(40, 60, 91, 21));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(180, 30, 91, 21));
        ledStatus_Battery = new QLabel(groupBox_2);
        ledStatus_Battery->setObjectName(QStringLiteral("ledStatus_Battery"));
        ledStatus_Battery->setGeometry(QRect(160, 30, 21, 21));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(180, 60, 91, 21));
        ledStatus_Autopilot = new QLabel(groupBox_2);
        ledStatus_Autopilot->setObjectName(QStringLiteral("ledStatus_Autopilot"));
        ledStatus_Autopilot->setGeometry(QRect(160, 60, 21, 21));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(730, 30, 271, 321));
        groupBox_3->setStyleSheet(QStringLiteral("font: 10pt \"Arial\";"));
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 80, 101, 31));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(151, 36, 101, 31));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(440, 560, 21, 16));
        MainView->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainView);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1023, 22));
        MainView->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainView);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainView->setStatusBar(statusBar);

        retranslateUi(MainView);

        QMetaObject::connectSlotsByName(MainView);
    } // setupUi

    void retranslateUi(QMainWindow *MainView)
    {
        MainView->setWindowTitle(QApplication::translate("MainView", "KT-817 Ground Control Station", Q_NULLPTR));
        label->setText(QApplication::translate("MainView", "Air Speed", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainView", "Current time: ", Q_NULLPTR));
        lbCurrentTime->setText(QApplication::translate("MainView", "Current Time", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainView", "Elapsed time: ", Q_NULLPTR));
        lbElapsedTime->setText(QApplication::translate("MainView", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainView", "Altitude", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainView", "Yaw", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainView", "Roll and Pitch", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainView", "Battery", Q_NULLPTR));
        imgBattery->setText(QApplication::translate("MainView", "TextLabel", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainView", "75%", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainView", "Status", Q_NULLPTR));
        ledStatus_GPS->setText(QApplication::translate("MainView", "162", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainView", "GPS ENABLE", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainView", "GPS Latitude", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainView", "GPS Longitude", Q_NULLPTR));
        ledStatus_Overspeed->setText(QApplication::translate("MainView", "163", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainView", "OVERSPEED", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainView", "BATTERY", Q_NULLPTR));
        ledStatus_Battery->setText(QApplication::translate("MainView", "163", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainView", "AUTOPILOT", Q_NULLPTR));
        ledStatus_Autopilot->setText(QApplication::translate("MainView", "163", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainView", "Control", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainView", "Start Capture", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainView", "Autopilot", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainView", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainView: public Ui_MainView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVIEW_H
