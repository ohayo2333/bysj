#-------------------------------------------------
#
# Project created by QtCreator 2025-02-02T15:23:59
#
#-------------------------------------------------

QT       += core gui sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = class2
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    register.cpp \
    forgotpassworddialog.cpp \
    airconditioner.cpp \
    curtain.cpp \
    light.cpp \
    environment.cpp \
    lock.cpp \
    powersystem.cpp \
    gps.cpp \
    security.cpp \
    dashboard.cpp \
    curtainwidget.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    register.h \
    forgotpassworddialog.h \
    airconditioner.h \
    curtain.h \
    light.h \
    environment.h \
    lock.h \
    powersystem.h \
    gps.h \
    security.h \
    dashboard.h \
    curtainwidget.h

FORMS += \
        mainwindow.ui \
    login.ui \
    register.ui \
    forgotpassworddialog.ui \
    airconditioner.ui \
    curtain.ui \
    light.ui \
    environment.ui \
    lock.ui \
    powersystem.ui \
    gps.ui \
    security.ui \
    dashboard.ui

RESOURCES += \
    pic.qrc
