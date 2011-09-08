/*
 TUIO Demo - part of the reacTIVision project
 http://reactivision.sourceforge.net/
 
 Copyright (c) 2005-2009 Martin Kaltenbrunner <mkalten@iua.upf.edu>
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INCLUDED_TUIODEMO_H
#define INCLUDED_TUIODEMO_H

#include "TuioListener.h"
#include "TuioClient.h"
#include "TuioObject.h"
#include "TuioCursor.h"
#include "TuioPoint.h"
#include <list>
#include <math.h>

#include <SDL.h>
#include <SDL_thread.h>

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif

using namespace TUIO;

class TuioDemo : public TuioListener { 
	
public:
	TuioDemo(int port);
	~TuioDemo() {
		tuioClient->disconnect();
		delete tuioClient;
	}
	
	void addTuioObject(TuioObject *tobj);
	void updateTuioObject(TuioObject *tobj);
	void removeTuioObject(TuioObject *tobj);
	
	void addTuioCursor(TuioCursor *tcur);
	void updateTuioCursor(TuioCursor *tcur);
	void removeTuioCursor(TuioCursor *tcur);
	
	void refresh(TuioTime frameTime);
	
	void run();
	TuioClient *tuioClient;
	
private:
	void drawObjects();
	void drawString(char *str);
	void processEvents();
	void toggleFullscreen();
	SDL_Surface *window;
	bool verbose, fullscreen, running;
	
	int width, height;
	int screen_width, screen_height;
	int window_width, window_height;
};

#endif /* INCLUDED_TUIODEMO_H */
