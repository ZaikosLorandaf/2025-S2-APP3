TEMPLATE     = vcapp
TARGET       = testGraphicusGUI
CONFIG      += warn_on qt debug windows console
HEADERS     += monInterface.h 
SOURCES     += testGraphicusGUI.cpp monInterface.cpp
INCLUDEPATH += ../GraphicusGUI ../graphicus-03
LIBS        += ../GraphicusGUI/graphicusGUI.lib
QT          += widgets
