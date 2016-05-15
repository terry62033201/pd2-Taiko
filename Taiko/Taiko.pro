#-------------------------------------------------
#
# Project created by QtCreator 2016-05-11T13:11:56
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    btn.cpp \
    scene.cpp \
    ball.cpp

HEADERS  += mainwindow.h \
    btn.h \
    scene.h \
    ball.h

FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
