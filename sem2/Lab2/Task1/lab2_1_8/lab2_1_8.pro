QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    filework.cpp \
    main.cpp \
    mainwindow.cpp \
    prodlist.cpp \
    production.cpp \
    table.cpp

HEADERS += \
    filework.h \
    mainwindow.h \
    prodlist.h \
    production.h \
    table.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    ../build-lab2_1_8-Desktop_Qt_6_4_2_MinGW_64_bit-Debug/production.txt
