#-------------------------------------------------
#
# Project created by QtCreator 2011-01-21T12:14:44
#
#-------------------------------------------------

QT       += qt3support

TARGET = MiniProTrial
TEMPLATE = app


INCLUDEPATH+=/usr/local/include/opencv
LD_LIBRARY_PATH+=/usr/local/lib
SOURCES += main.cpp\
        widget.cpp
LIBS +=-lopencv_core -lopencv_highgui -lopencv_imgproc -lcvblob

HEADERS  += widget.h

FORMS    += widget.ui
