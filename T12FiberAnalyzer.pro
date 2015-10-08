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

# adding python scripts to build location
copyfiles.commands = cp $$PWD/version.py $$OUT_PWD/
QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles


SOURCES += main.cpp\
    tfatool.cpp \
    fibertractmodel.cpp \
    atlasmodel.cpp \
    csvbrowsemodel.cpp \
    csvbrowser.cpp \
    errorreporter.cpp \
    T1T2FiberAnalyzer.cpp

HEADERS  += \
    Resources/csv.h \
    tfatool.h \
    fibertractmodel.h \
    atlasmodel.h \
    csvbrowsemodel.h \
    csvbrowser.h \
    errorreporter.h \
    stacktrace.h \
    T1T2FiberAnalyzer.h

FORMS    += mainwindow.ui \
    csvbrowser.ui

SUBDIRS += \
    Resources/analogclock.pro

OTHER_FILES += \
    version.py
