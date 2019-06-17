/********************************************************************************
** Form generated from reading UI file 'WidgetADI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETADI_H
#define UI_WIDGETADI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_ADI.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetADI
{
public:
    qfi_ADI *graphicsADI;

    void setupUi(QWidget *WidgetADI)
    {
        if (WidgetADI->objectName().isEmpty())
            WidgetADI->setObjectName(QStringLiteral("WidgetADI"));
        WidgetADI->resize(400, 300);
        WidgetADI->setStyleSheet(QStringLiteral(""));
        graphicsADI = new qfi_ADI(WidgetADI);
        graphicsADI->setObjectName(QStringLiteral("graphicsADI"));
        graphicsADI->setEnabled(false);
        graphicsADI->setGeometry(QRect(-60, -50, 256, 192));
        graphicsADI->setFrameShape(QFrame::NoFrame);
        graphicsADI->setFrameShadow(QFrame::Plain);
        graphicsADI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsADI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsADI->setInteractive(false);

        retranslateUi(WidgetADI);

        QMetaObject::connectSlotsByName(WidgetADI);
    } // setupUi

    void retranslateUi(QWidget *WidgetADI)
    {
        WidgetADI->setWindowTitle(QApplication::translate("WidgetADI", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetADI: public Ui_WidgetADI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETADI_H
