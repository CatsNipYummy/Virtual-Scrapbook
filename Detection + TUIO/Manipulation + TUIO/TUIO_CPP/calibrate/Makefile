#############################################################################
# Makefile for building: calibrate
# Generated by qmake (2.01a) (Qt 4.6.2) on: Tue Jul 19 00:49:34 2011
# Project:  calibrate.pro
# Template: app
# Command: /opt/qtsdk-2010.02/qt/bin/qmake -spec /opt/qtsdk-2010.02/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile calibrate.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT_LIB -DQT_QT3SUPPORT_LIB -DQT3_SUPPORT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/opt/qtsdk-2010.02/qt/mkspecs/linux-g++-64 -I. -I/opt/qtsdk-2010.02/qt/include/QtCore -I/opt/qtsdk-2010.02/qt/include/QtGui -I/opt/qtsdk-2010.02/qt/include/Qt3Support -I/opt/qtsdk-2010.02/qt/include/QtWebKit -I/opt/qtsdk-2010.02/qt/include -I/usr/local/include/opencv -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-rpath,/opt/qtsdk-2010.02/qt/lib
LIBS          = $(SUBLIBS)  -L/opt/qtsdk-2010.02/qt/lib -lcxcore -lcv -lhighgui -lcvaux -lml -lcvblob -lQtWebKit -L/opt/qtsdk-2010.02/qt/lib -L/usr/X11R6/lib64 -lphonon -L/home/berlin/dev/qt-4.6.2-opensource-shipping/this_path_is_supposed_to_be_very_long_hopefully_this_is_long_enough/qt/lib -lQtDBus -lQtXmlPatterns -lQt3Support -lQtSql -lQtXml -lQtNetwork -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /opt/qtsdk-2010.02/qt/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		widget.cpp \
		threadqt.cpp moc_widget.cpp
OBJECTS       = main.o \
		widget.o \
		threadqt.o \
		moc_widget.o
DIST          = /opt/qtsdk-2010.02/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/debug.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/include_source_dir.prf \
		calibrate.pro
QMAKE_TARGET  = calibrate
DESTDIR       = 
TARGET        = calibrate

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_widget.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: calibrate.pro  /opt/qtsdk-2010.02/qt/mkspecs/linux-g++-64/qmake.conf /opt/qtsdk-2010.02/qt/mkspecs/common/g++.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/common/unix.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/common/linux.conf \
		/opt/qtsdk-2010.02/qt/mkspecs/qconfig.pri \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt_functions.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt_config.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/exclusive_builds.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/default_pre.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/debug.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/default_post.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/warn_on.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/qt.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/unix/thread.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/moc.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/resources.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/uic.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/yacc.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/lex.prf \
		/opt/qtsdk-2010.02/qt/mkspecs/features/include_source_dir.prf \
		/opt/qtsdk-2010.02/qt/lib/libQtWebKit.prl \
		/opt/qtsdk-2010.02/qt/lib/libphonon.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtDBus.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtXml.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtCore.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtGui.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtXmlPatterns.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtNetwork.prl \
		/opt/qtsdk-2010.02/qt/lib/libQt3Support.prl \
		/opt/qtsdk-2010.02/qt/lib/libQtSql.prl
	$(QMAKE) -spec /opt/qtsdk-2010.02/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile calibrate.pro
/opt/qtsdk-2010.02/qt/mkspecs/common/g++.conf:
/opt/qtsdk-2010.02/qt/mkspecs/common/unix.conf:
/opt/qtsdk-2010.02/qt/mkspecs/common/linux.conf:
/opt/qtsdk-2010.02/qt/mkspecs/qconfig.pri:
/opt/qtsdk-2010.02/qt/mkspecs/features/qt_functions.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/qt_config.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/exclusive_builds.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/default_pre.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/debug.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/default_post.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/warn_on.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/qt.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/unix/thread.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/moc.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/resources.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/uic.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/yacc.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/lex.prf:
/opt/qtsdk-2010.02/qt/mkspecs/features/include_source_dir.prf:
/opt/qtsdk-2010.02/qt/lib/libQtWebKit.prl:
/opt/qtsdk-2010.02/qt/lib/libphonon.prl:
/opt/qtsdk-2010.02/qt/lib/libQtDBus.prl:
/opt/qtsdk-2010.02/qt/lib/libQtXml.prl:
/opt/qtsdk-2010.02/qt/lib/libQtCore.prl:
/opt/qtsdk-2010.02/qt/lib/libQtGui.prl:
/opt/qtsdk-2010.02/qt/lib/libQtXmlPatterns.prl:
/opt/qtsdk-2010.02/qt/lib/libQtNetwork.prl:
/opt/qtsdk-2010.02/qt/lib/libQt3Support.prl:
/opt/qtsdk-2010.02/qt/lib/libQtSql.prl:
qmake:  FORCE
	@$(QMAKE) -spec /opt/qtsdk-2010.02/qt/mkspecs/linux-g++-64 -unix CONFIG+=debug -o Makefile calibrate.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/calibrate1.0.0 || $(MKDIR) .tmp/calibrate1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/calibrate1.0.0/ && $(COPY_FILE) --parents widget.h threadqt.h .tmp/calibrate1.0.0/ && $(COPY_FILE) --parents main.cpp widget.cpp threadqt.cpp .tmp/calibrate1.0.0/ && $(COPY_FILE) --parents widget.ui .tmp/calibrate1.0.0/ && (cd `dirname .tmp/calibrate1.0.0` && $(TAR) calibrate1.0.0.tar calibrate1.0.0 && $(COMPRESS) calibrate1.0.0.tar) && $(MOVE) `dirname .tmp/calibrate1.0.0`/calibrate1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/calibrate1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_widget.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_widget.cpp
moc_widget.cpp: threadqt.h \
		widget.h
	/opt/qtsdk-2010.02/qt/bin/moc $(DEFINES) $(INCPATH) widget.h -o moc_widget.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_widget.h
compiler_uic_clean:
	-$(DEL_FILE) ui_widget.h
ui_widget.h: widget.ui
	/opt/qtsdk-2010.02/qt/bin/uic widget.ui -o ui_widget.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp widget.h \
		threadqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

widget.o: widget.cpp widget.h \
		threadqt.h \
		ui_widget.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o widget.o widget.cpp

threadqt.o: threadqt.cpp threadqt.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o threadqt.o threadqt.cpp

moc_widget.o: moc_widget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_widget.o moc_widget.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

