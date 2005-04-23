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
			case KeyPress:
				// Handle Keyboard Event
				break;
			case MotionEvent:
				// Handle Mouse Move
				break;
			case ButtonPress:
				// Handle Mouse Click
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


int ambR_draw_line(AWindow * Wnd, int xA, int yA, int xB, int yB){
	cairo_move_to(Wnd->Canvas,yA,xA);
	cairo_line_to(Wnd->Canvas,yB,xB);
	cairo_set_line_width (Wnd->Canvas, 3);
	cairo_stroke(Wnd->Canvas);
	//XDrawLine(Wnd->Renderer->rDisplay, Wnd->XWindow, Wnd->XGC, yA, xA, yB, xB);
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
	cairo_move_to(Wnd->Canvas, y, x);
	cairo_show_text(Wnd->Canvas, text);
	return 0;
}

int ambR_draw_arc(AWindow * Wnd, int xA, int yA, int radius, int Orient){
	int AStart, AEnd;
	printf("WARNING: FUNCTION INCOMPLETE\n");
	switch(Orient){
	case 0: // Up
		AStart = 1.5;
		AEnd = 0;
		break;
	case 1: // Down
		AStart = 0;
		AEnd = 1.5;
		break;
	}
	cairo_arc(Wnd->Canvas,xA,yA,radius,AStart,AEnd);
	return 0;
}

int ambR_draw_rect(AWindow * Wnd, int x, int y, int w, int h){
    ambR_draw_line(Wnd,x,y,x,(y+h));
    ambR_draw_line(Wnd,x,y,(x+w),y);
    ambR_draw_line(Wnd,(x+w),y,(x+w),(y+h));
    ambR_draw_line(Wnd,x,(y+h),(x+w),(y+h));
    return 0;
}
