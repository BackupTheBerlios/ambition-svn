#include <stdio.h>
#include <stdlib.h>
#include "renderer.h"

AWindow ambW_create(ARenderer * Renderer, char * wndTitle[], int x, int y, unsigned int height, unsigned int width){
	AWindow tWindow;
	// Get the parent Renderer
	tWindow.Renderer = Renderer;
	// Initialize the Child Count
	tWindow.cCount = 0;
	// Get the Screen Number
	int screen_num = DefaultScreen(Renderer->rDisplay);
	// Create an X Window for our AWindow to use
	tWindow.XWindow = XCreateSimpleWindow(Renderer->rDisplay,
                          RootWindow(Renderer->rDisplay, screen_num),
                          x, y,
                          width, height,
                          3, BlackPixel(Renderer->rDisplay, screen_num),
                          WhitePixel(Renderer->rDisplay, screen_num));
	// Define the defaults for a new Graphics Context
	XGCValues gVals;
	// gVals = CapButt | JoinBevel;
	// gVals = 0;
	// Set the bitmask for the Graphics Context
	unsigned long gMask = 0;
	// Get a Graphics Context for the window
	printf("Create GC\n");
	tWindow.XGC = XCreateGC(Renderer->rDisplay, tWindow.XWindow, gMask, &gVals);
	if (tWindow.XGC < 0) {
		fprintf(stderr, "XCreateGC: \n"); // Couldn't create a graphics context
		exit(-1); // Can't go on, since we need a GC for the rest of the app :-)
	}
	printf("Set bg\n");
	// Set foreground to black
	XSetForeground(Renderer->rDisplay, tWindow.XGC, BlackPixel(Renderer->rDisplay, screen_num));
	printf("Set fg\n");
	// Set background to white
	XSetBackground(Renderer->rDisplay, tWindow.XGC, WhitePixel(Renderer->rDisplay, screen_num));
	printf("Set fill size");
	// Set fill to solid
	XSetFillStyle(Renderer->rDisplay, tWindow.XGC, FillSolid);
	printf("Set line width/style\n");
	// Set line width and style
	XSetLineAttributes(Renderer->rDisplay, tWindow.XGC, 3, LineSolid, CapRound, JoinRound);
	printf("Return\n");
	// Return the AWindow object
	return tWindow;
}

void ambW_draw(AWindow * Wnd){
	int i = 0;
	for(i = 0; i < Wnd->cCount; i++){
		// Make the child draw itself
		Wnd->Children[i]->draw(Wnd,i);//Wnd->Children[i]);
		XFlush(Wnd->Renderer->rDisplay);
	}
	return;
}

int ambW_load_font(AWindow * Wnd, char * Font){
	printf("Load\n");
	Wnd->XFont = (*XLoadQueryFont(Wnd->Renderer->rDisplay, Font));
	if (!Wnd->XFont.fid) {
		fprintf(stderr, "XLoadQueryFont: failed loading font '%s'\n", Font);
		return -1;
	}
	printf("Set\n");
	XSetFont(Wnd->Renderer->rDisplay, Wnd->XGC, Wnd->XFont.fid);
	return 0;
}

int ambW_show(AWindow * Wnd){
	// Display the Window
	printf("Map Window\n");
	XMapWindow(Wnd->Renderer->rDisplay, Wnd->XWindow);
	// Synchronise X (flush events) so that the window shows
	printf("Flush Events\n");
	XSync(Wnd->Renderer->rDisplay, False);
	printf("Return\n");
	return 0;
}

int ambW_destroy(AWindow * Wnd){
	// Insert Cleanup code here
	return 0;
}
