# -------------------------------------------------
# Project created by QtCreator 2011-03-29T23:22:12
# -------------------------------------------------
QT += webkit \
    qt3support
TARGET = calibrate
TEMPLATE = app
INCLUDEPATH += /usr/local/include/opencv
LIBS += -lcxcore \
    -lcv \
    -lhighgui \
    -lcvaux \
    -lml \
    -lcvblob
SOURCES += main.cpp \
    widget.cpp \
    threadqt.cpp
HEADERS += widget.h \
    threadqt.h
FORMS += widget.ui
