#-------------------------------------------------
#
# Project created by QtCreator 2014-09-15T13:45:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = b3ui
TEMPLATE = app


SOURCES += main.cpp \
           mainwindow.cpp \
           connectdialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    connectdialog.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    connectdialog.ui \
    aboutdialog.ui