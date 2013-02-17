#-------------------------------------------------
#
# Project created by QtCreator 2013-02-16T01:13:34
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MedicineDb
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    database.h

FORMS    += mainwindow.ui
