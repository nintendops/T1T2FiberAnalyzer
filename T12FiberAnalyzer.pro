#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T13:48:16
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = T12FiberAnalyzer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tfatool.cpp \
    fibertractmodel.cpp \
    atlasmodel.cpp \
    csvbrowsemodel.cpp \
    csvbrowser.cpp \
    errorreporter.cpp

HEADERS  += mainwindow.h \
    Resources/csv.h \
    tfatool.h \
    fibertractmodel.h \
    atlasmodel.h \
    csvbrowsemodel.h \
    csvbrowser.h \
    errorreporter.h

FORMS    += mainwindow.ui \
    csvbrowser.ui

SUBDIRS += \
    Resources/analogclock.pro
