#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "renderer.h"

int ambR_init(ARenderer * Renderer){
	// Open $DISPLAY and set rDisplay accordingly
	Renderer->rDisplay = XOpenDisplay(getenv("DISPLAY"));
	if (Renderer->rDisplay == NULL) {
		// Failed to open the display
		printf("Could not connect to X Server\n");
    		exit(-1);
	}
	// Initialise the Child Count
	Renderer->cCount = 0;
	return 0;
}

int ambR_close(ARenderer * Renderer){
	// Close $DISPLAY
	XCloseDisplay(Renderer->rDisplay);
	return 0;
}

int ambR_main(ARenderer * Renderer){
	XEvent Next;
	int i = 0;
	int j = 0;
	for(i = 0; i < Renderer->cCount; i = i +1){
		// Register for expose events on all children
		AWindow * Wnd = Renderer->Children[i];
		XSelectInput(Renderer->rDisplay, Wnd->XWindow, ExposureMask);
	}
	while (1) {
		XNextEvent(Renderer->rDisplay, &Next);
		switch (Next.type) {
			case Expose:
				if(Next.xexpose.count > 0)
					break;
				for(i = 0; i < Renderer->cCount; i = i +1){
					AWindow * Wnd = Renderer->Children[i];
					ambW_draw(Wnd);
				}
				break;
			default:
				break;
		}
		j += 1;
	}
	return 0;
}

int ambR_register(AObject * Object, int Event, void (*AFunc)(AObject*)){
	return 0;
}

int ambR_add_child(ARenderer * Renderer, AWindow * Wnd){
	Renderer->Children[Renderer->cCount] = Wnd;
	Renderer->cCount += 1;
	return 0;
}

int ambR_draw_pixel(AWindow * Wnd, int x, int y){
	XDrawPoint(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, x, y);
	return 0;
}

int ambR_draw_line(AWindow * Wnd, int xA, int yA, int xB, int yB){
	XDrawLine(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, yA, xA, yB, xB);
	return 0;
}

int ambR_draw_shape(AWindow * Wnd, int * Coords[]){
	/* int pCount = sizeof(Coords)/sizeof(XPoint);
	XDrawLines(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, Coords, pCount, CoordModeOrigin); */
	return 0;
}

/* Note to self:
   Text drawing functions work, debug client code instead if it segfaults */

int ambR_draw_text(AWindow * Wnd, char * text, int x, int y){
	XDrawString(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, y, x, text, strlen(text));
	return 0;
}

int ambR_draw_arc(AWindow * Wnd, int x, int y, int r, int Orient){
	int AStart, AEnd;
	switch(Orient){
	case 0: // Down and Left
		AStart = 270*64;
		AEnd = 180*64;
		break;
	case 1: // Down and Right
		AStart = 180*64;
		AEnd = 90*64;
		break;
	case 2: // Up and Right
		AStart = 90*64;
		AEnd = 0;
		break;
	case 3:
		// Up and Left
		AStart = 270*64;
		AEnd = 360 * 64;
		break;
	}
	XDrawArc(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, x-r, y-r, r, r, AStart, AEnd);
	return 0;
}
