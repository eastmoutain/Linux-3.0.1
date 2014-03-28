
CONFIG += qtopiaapp 
CONFIG -= buildQuicklaunch 
TARGET = gprs

# Input
HEADERS += gprs.h  messdialog.h  scanmes.h netdialog.h

INTERFACES += gprsform.ui   mess_dialog.ui  scanmes_dialog.ui net_dialog.ui

SOURCES += gprs.cpp  messdialog.cpp  main.cpp scanmes.cpp netdialog.cpp
