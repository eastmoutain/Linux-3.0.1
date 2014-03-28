
CONFIG += qtopiaapp 
CONFIG -= buildQuicklaunch 

TARGET = WiFiTest

# Input
HEADERS += WiFiTest.h  IPShowSet.h  passwordSet.h

INTERFACES += UI_WiFiTest.ui   UI_IPShowSet.ui  UI_Password.ui 

SOURCES += WiFiTest.cpp  IPShowSet.cpp  passwordSet.cpp main.cpp
