#-------------------------------------------------
#
# Project created by QtCreator 2019-06-11T03:36:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LuaTool
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

INCLUDEPATH += /home/bairuo/QScintilla_gpl-2.11.1/Qt4Qt5/

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    codeedit.cpp

HEADERS += \
        mainwindow.h \
    codeedit.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../QScintilla_gpl-2.11.1/build-qscintilla-Desktop_Qt_5_12_1_GCC_64bit-Release/release/ -lqscintilla2_qt5
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../QScintilla_gpl-2.11.1/build-qscintilla-Desktop_Qt_5_12_1_GCC_64bit-Release/debug/ -lqscintilla2_qt5
else:unix: LIBS += -L$$PWD/../QScintilla_gpl-2.11.1/build-qscintilla-Desktop_Qt_5_12_1_GCC_64bit-Release/ -lqscintilla2_qt5

INCLUDEPATH += $$PWD/../QScintilla_gpl-2.11.1/build-qscintilla-Desktop_Qt_5_12_1_GCC_64bit-Release
DEPENDPATH += $$PWD/../QScintilla_gpl-2.11.1/build-qscintilla-Desktop_Qt_5_12_1_GCC_64bit-Release
