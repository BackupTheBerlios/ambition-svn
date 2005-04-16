#include <stdio.h>
#include <stdlib.h>

#include "window.h"

AWindow ambW_create(ARenderer * Renderer, char * wndTitle[], int x, int y, unsigned int height, unsigned int width){
	AWindow tWindow;
	// Get the parent Renderer
	tWindow.Renderer = Renderer;
	// Initialize the Child Count
	tWindow.cCount = 0;
	tWindow.Canvas = cairo_create();
	// Get the Screen Number
	int screen_num = DefaultScreen(Renderer->rDisplay);
	// Create an X Window for our AWindow to use
	tWindow.XWindow = XCreateSimpleWindow(Renderer->rDisplay,
                          RootWindow(Renderer->rDisplay, screen_num),
                          x, y,
                          height, width,
                          3, BlackPixel(Renderer->rDisplay, screen_num),
                          WhitePixel(Renderer->rDisplay, screen_num));
	cairo_set_target_drawable(tWindow.Canvas, tWindow.Renderer->rDisplay, tWindow.XWindow);
	cairo_set_rgb_color(tWindow.Canvas,0.0,0.0,0.0);
	cairo_set_line_cap(tWindow.Canvas,1);
	// Set Window title
	ambW_set_title(&tWindow,wndTitle);
	// Return the AWindow object
	return tWindow;
}

void ambW_draw(AWindow * Wnd){
	int i = 0;
	for(i = 0; i < Wnd->cCount; i = i +1){
		// Make the child draw itself
		Wnd->Children[i]->draw(Wnd,i);//Wnd->Children[i]);
		XFlush(Wnd->Renderer->rDisplay);
	}
	return;
}

int ambW_resize(AWindow * Wnd, int width, int height){
	XResizeWindow(Wnd->Renderer->rDisplay, Wnd->XWindow, width, height);
	return 0;
}

int ambW_add_child(AWindow * Wnd, AWidget * Child){
	Wnd->Children[Wnd->cCount] = Child;
	Wnd->cCount = Wnd->cCount + 1;
	return 0;
}

/*int ambW_set_font(AWindow * Wnd, char * Font, int size){
	XftPattern * FName, * IName;
	XftResult * fResult;
	char* fString;
	sprintf(fString,"%s-%d:%d=%d",Font,size,XFT_ANTIALIAS,1);
	FName = XftNameParse(fString);
	IName = XftFontMatch (Wnd->Renderer->rDisplay, DefaultScreen(Wnd->Renderer->rDisplay), FName, fResult);
	Wnd->XFont = *XftFontOpenPattern (Wnd->Renderer->rDisplay, IName);
	//if (!Wnd->XFont.fid) {
	//	fprintf(stderr, "XLoadQueryFont: failed loading font '%s'\n", Font);
	//	return -1;
	//}
	//XSetFont(Wnd->Renderer->rDisplay, Wnd->XGC, Wnd->XFont.fid);
	return 0;
}*/

int ambW_set_title(AWindow * Wnd, char * wndTitle[]){
	// Set the Window Title
	XTextProperty tWndName;
	XStringListToTextProperty(wndTitle,1,&tWndName);
	XSetWMName(Wnd->Renderer->rDisplay,Wnd->XWindow,&tWndName);
	return 0;
}

int ambW_show(AWindow * Wnd){
	// Display the Window
	XMapWindow(Wnd->Renderer->rDisplay, Wnd->XWindow);
	// Synchronise X (flush events) so that the window shows
	XSync(Wnd->Renderer->rDisplay, False);
	return 0;
}

int ambW_destroy(AWindow * Wnd){
	// Insert Cleanup code here
	return 0;
}
