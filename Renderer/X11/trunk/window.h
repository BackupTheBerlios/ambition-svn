#include <X11/Xlib.h>

#ifndef AMBITION_WINDOW

#define AMBITION_WINDOW

#include <cairo.h>

#include "renderer.h"

AWindow ambW_create(ARenderer * Renderer, char * wndTitle[], int x, int y, unsigned int height, unsigned int width);
void ambW_draw(AWindow * Wnd);
int ambW_resize(AWindow * Wnd, int width, int height);
int ambW_add_child(AWindow * Wnd, AWidget * Child);
int ambW_set_font(AWindow * Wnd, char * Font, int size);
int ambW_set_title(AWindow * Wnd, char * wndTitle[]);
int ambW_show(AWindow * Wnd);
int ambW_destroy(AWindow * Wnd);

#endif /* Window */
