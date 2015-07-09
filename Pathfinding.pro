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

QMAKE_CXXFLAGS += -std=c++11

HEADERS += \
    src/astar.h \
    src/comparef.h \
    src/dijkstra.h \
    src/node.h \
    src/pathfinder.h \
    src/test.h \
    src/testharness.h \
    src/testtype.h

SOURCES += \
    src/astar.cpp \
    src/dijkstra.cpp \
    src/main.cpp \
    src/node.cpp \
    src/pathfinder.cpp \
    src/test.cpp \
    src/testharness.cpp \
    src/testtype.cpp



