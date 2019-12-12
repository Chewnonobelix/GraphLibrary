QT += gui core widgets network xml xmlpatterns testlib

CONFIG += qt console warn_on depend_includepath testcase c++17
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    main.cpp \
    testgraph.cpp \
    testgraphunoriented.cpp

HEADERS += \
    testgraph.h \
    testgraphunoriented.h

INCLUDEPATH += ../GraphLib
