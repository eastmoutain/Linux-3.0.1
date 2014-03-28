
CONFIG += qtopiaapp 
CONFIG -= buildQuicklaunch 
TARGET = 3GDialup

# Input
HEADERS += 3GTest.h  connect.h

INTERFACES += UI_3GTest.ui   UI_Connect.ui

SOURCES += 3GTest.cpp  connect.cpp  main.cpp
