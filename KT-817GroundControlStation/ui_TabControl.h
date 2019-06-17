/********************************************************************************
** Form generated from reading UI file 'TabControl.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABCONTROL_H
#define UI_TABCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "widgetadi.h"
#include "widgetalt.h"
#include "widgetasi.h"

QT_BEGIN_NAMESPACE

class Ui_TabControl
{
public:
    QGridLayout *gridLayout;
    WidgetALT *widgetALT;
    WidgetADI *widgetADI;
    QGroupBox *groupBox_4;
    WidgetASI *widgetASI;
    QGroupBox *groupBox_9;
    QWidget *widget;

    void setupUi(QWidget *TabControl)
    {
        if (TabControl->objectName().isEmpty())
            TabControl->setObjectName(QStringLiteral("TabControl"));
        TabControl->resize(787, 499);
        gridLayout = new QGridLayout(TabControl);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        widgetALT = new WidgetALT(TabControl);
        widgetALT->setObjectName(QStringLiteral("widgetALT"));

        gridLayout->addWidget(widgetALT, 0, 2, 1, 1);

        widgetADI = new WidgetADI(TabControl);
        widgetADI->setObjectName(QStringLiteral("widgetADI"));

        gridLayout->addWidget(widgetADI, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(TabControl);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));

        gridLayout->addWidget(groupBox_4, 3, 0, 1, 3);

        widgetASI = new WidgetASI(TabControl);
        widgetASI->setObjectName(QStringLiteral("widgetASI"));

        gridLayout->addWidget(widgetASI, 1, 2, 1, 1);

        groupBox_9 = new QGroupBox(TabControl);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));

        gridLayout->addWidget(groupBox_9, 0, 1, 1, 1);

        widget = new QWidget(TabControl);
        widget->setObjectName(QStringLiteral("widget"));

        gridLayout->addWidget(widget, 1, 0, 1, 1);


        retranslateUi(TabControl);

        QMetaObject::connectSlotsByName(TabControl);
    } // setupUi

    void retranslateUi(QWidget *TabControl)
    {
        TabControl->setWindowTitle(QApplication::translate("TabControl", "Form", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("TabControl", "GroupBox", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("TabControl", "GroupBox", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TabControl: public Ui_TabControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABCONTROL_H
