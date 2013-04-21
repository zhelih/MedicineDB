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
    logindialog.cpp \
    translate_load.cpp \
    editdialog.cpp \
    editmodel.cpp \
    mainwindow_ext.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    translate_load.h \
    mysqlmodel.h \
    editdialog.h \
    editmodel.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    editdialog.ui

#LIBS += C:\Qt\Qt5.0.1\5.0.1\Src\qtbase\plugins\sqldrivers\libqsqldb2.a
#LIBS += C:\Qt\Qt5.0.1\5.0.1\Src\qtbase\plugins\sqldrivers\libqsqldb2d.a

OTHER_FILES += \
    translate.txt
