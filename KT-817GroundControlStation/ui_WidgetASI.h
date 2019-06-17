/********************************************************************************
** Form generated from reading UI file 'WidgetASI.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGETASI_H
#define UI_WIDGETASI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include "qfi_ASI.h"

QT_BEGIN_NAMESPACE

class Ui_WidgetASI
{
public:
    qfi_ASI *graphicsASI;

    void setupUi(QWidget *WidgetASI)
    {
        if (WidgetASI->objectName().isEmpty())
            WidgetASI->setObjectName(QStringLiteral("WidgetASI"));
        WidgetASI->resize(361, 265);
        WidgetASI->setStyleSheet(QStringLiteral(""));
        graphicsASI = new qfi_ASI(WidgetASI);
        graphicsASI->setObjectName(QStringLiteral("graphicsASI"));
        graphicsASI->setEnabled(false);
        graphicsASI->setGeometry(QRect(-60, -50, 256, 192));
        graphicsASI->setFrameShape(QFrame::NoFrame);
        graphicsASI->setFrameShadow(QFrame::Plain);
        graphicsASI->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsASI->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsASI->setInteractive(false);

        retranslateUi(WidgetASI);

        QMetaObject::connectSlotsByName(WidgetASI);
    } // setupUi

    void retranslateUi(QWidget *WidgetASI)
    {
        WidgetASI->setWindowTitle(QApplication::translate("WidgetASI", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class WidgetASI: public Ui_WidgetASI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGETASI_H
