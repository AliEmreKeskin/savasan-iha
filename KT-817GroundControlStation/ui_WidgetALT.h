/********************************************************************************
** Form generated from reading UI file 'WidgetALT.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETALT_H
#define UI_WIDGETALT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_ALT.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetALT
{
public:
    qfi_ALT *graphicsALT;

    void setupUi(QWidget *WidgetALT)
    {
        if (WidgetALT->objectName().isEmpty())
            WidgetALT->setObjectName(QStringLiteral("WidgetALT"));
        WidgetALT->resize(330, 262);
        WidgetALT->setStyleSheet(QStringLiteral(""));
        graphicsALT = new qfi_ALT(WidgetALT);
        graphicsALT->setObjectName(QStringLiteral("graphicsALT"));
        graphicsALT->setEnabled(false);
        graphicsALT->setGeometry(QRect(-60, -50, 256, 192));
        graphicsALT->setFrameShape(QFrame::NoFrame);
        graphicsALT->setFrameShadow(QFrame::Plain);
        graphicsALT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsALT->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsALT->setInteractive(false);

        retranslateUi(WidgetALT);

        QMetaObject::connectSlotsByName(WidgetALT);
    } // setupUi

    void retranslateUi(QWidget *WidgetALT)
    {
        WidgetALT->setWindowTitle(QApplication::translate("WidgetALT", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetALT: public Ui_WidgetALT {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETALT_H
