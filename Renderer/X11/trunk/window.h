#include <X11/Xlib.h>

#ifndef AMBITION_WINDOW

#define AMBITION_WINDOW
#include "renderer.h"
AWindow ambW_create(ARenderer * Renderer, char * wndTitle[], int x, int y, unsigned int height, unsigned int width);
void ambW_draw(AWindow * Wnd);
int ambW_load_font(AWindow * Wnd, char * Font[]);
int ambW_show(AWindow * Wnd);
int ambW_destroy(AWindow * Wnd);
#endif /* Window */
