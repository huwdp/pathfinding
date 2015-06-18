#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T18:50:36
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Pathfinding
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    node.cpp \
    astar.cpp \
    dijkstra.cpp \
    pathfinder.cpp \
    test.cpp \
    testharness.cpp \
    testtype.cpp

DISTFILES += \
    LICENSE.txt

HEADERS += \
    comparef.h \
    node.h \
    astar.h \
    dijkstra.h \
    pathfinder.h \
    test.h \
    testharness.h \
    testtype.h
