#-------------------------------------------------
#
# Project created by QtCreator 2015-05-02T16:38:34
#
#-------------------------------------------------

QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HeroQuest_v1
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    room.cpp \
    portal.cpp \
    player.cpp \
    board.cpp \
    arrow.cpp \
    boss.cpp \
    switch.cpp \
    fireball.cpp \
    wall.cpp \
    no_arrow_boss.cpp \
    fire_wall.cpp \
    slime.cpp \
    minion_boss.cpp

HEADERS  += mainwindow.h \
    room.h \
    portal.h \
    player.h \
    board.h \
    arrow.h \
    boss.h \
    switch.h \
    fireball.h \
    wall.h \
    no_arrow_boss.h \
    fire_wall.h \
    slime.h \
    minion_boss.h \
    documentation.h

RESOURCES += \
    resources.qrc
