#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

#include "error.h"
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
	while (1) {
		XNextEvent(Renderer->rDisplay, &Next);
		switch (Next.type) {
			case Expose:
				if(Next.xexpose.count > 0)
					break;
				break;
			default:
				printf("Default\n");
				break;
		}
	}
	return 0;
}

int ambR_register(AObject * Object, int Event, void (*AFunc)(AObject*)){
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

int ambR_draw_shape(AWindow * Wnd, XPoint * Coords){
	int pCount = sizeof(Coords)/sizeof(XPoint);
	XDrawLines(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, Coords, pCount, CoordModeOrigin);
	return 0;
}

int ambR_draw_text(AWindow * Wnd, char * text[], int x, int y){
	XDrawString(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, x, y, *text, strlen(*text));
	return 0;
}
