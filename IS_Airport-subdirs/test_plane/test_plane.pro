QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH += ../Aeroport
SOURCES += tst_test_plane.cpp \
    ../Aeroport/plane.cpp \
    ../Aeroport/passenger.cpp \
    ../Aeroport/ticket.cpp
