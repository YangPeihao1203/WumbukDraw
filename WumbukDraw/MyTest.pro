#-------------------------------------------------
#
# Project created by QtCreator 2021-06-05T09:52:12
#
#-------------------------------------------------

QT       += core gui
QT       += core gui svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyTest
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
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
    Mainpaintscene.cpp \
    Shape.cpp \
    Text.cpp \
    line.cpp \
    circular.cpp \
    ellipse.cpp \
    rect.cpp \
    penpath.cpp \
    image.cpp \
    staticimage.cpp \
    gif.cpp \
    utility.cpp \
    observer.cpp \
    getLableFactory.cpp



HEADERS += \
        mainwindow.h \
    Mainpaintscene.h \
    Shape.h \
    Text.h \
    line.h \
    circular.h \
    ellipse.h \
    rect.h \
    penpath.h \
    image.h \
    staticimage.h \
    gif.h \
    utility.h \
    observetarget.h \
    observer.h \
    getwidgetfactory.h \
    getLableFactory.h

FORMS += \
        mainwindow.ui

RESOURCES += \
    myphotos.qrc

