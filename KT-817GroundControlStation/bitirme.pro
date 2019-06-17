#-------------------------------------------------
#
# Project created by QtCreator 2018-11-01T08:49:38
#
#-------------------------------------------------

QT       += core gui svg widgets printsupport serialport

TARGET = bitirme
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainview.cpp \
    mywidget.cpp \
    qfi_ALT.cpp \
    WidgetALT.cpp \
    TabControl.cpp \
    WidgetASI.cpp \
    qfi_ASI.cpp \
    qfi_ADI.cpp \
    WidgetADI.cpp \
    qfi_HSI.cpp \
    WidgetHSI.cpp \
    WidgetPFD.cpp \
    qfi_PFD.cpp

HEADERS += \
        mainview.h \
    utils.h \
    mywidget.h \
    qfi_ALT.h \
    TabControl.h \
    qfi_ASI.h \
    qfi_ADI.h \
    qfi_HSI.h \
    qfi_PFD.h \
    widgetadi.h \
    widgetasi.h \
    widgethsi.h \
    widgetpfd.h \
    widgetalt.h

FORMS += \
        mainview.ui \
    WidgetALT.ui \
    TabControl.ui \
    WidgetASI.ui \
    WidgetADI.ui \
    WidgetHSI.ui \
    WidgetPFD.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
