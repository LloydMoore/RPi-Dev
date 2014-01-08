#-------------------------------------------------
#
# Project created by QtCreator 2013-11-22T08:35:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SRSBase
TEMPLATE = app


SOURCES += main.cpp\
        botmonitor.cpp \
    spi_ring.cpp \
    base_exception.cpp

HEADERS  += botmonitor.h \
    ../../Common/ringcoms.h \
    spi_ring.h \
    base_exception.h

FORMS    += botmonitor.ui

OTHER_FILES += \
    license.txt
