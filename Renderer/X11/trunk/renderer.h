#ifndef AMBITION_RENDERER

#define AMBITION_RENDERER
#include <X11/Xlib.h>
#include <X11/Xutil.h>
// Xft Include causes parse error
// #include <X11/Xft/Xft.h>

#include "types.h"

// Core Renderer Functions

int ambR_init(ARenderer * Renderer);
int ambR_close(ARenderer * Renderer);
int ambR_main(ARenderer * Renderer);
int ambR_register(AObject * Object, int Event, void (*AFunc)(AObject*));

// INTERNAL USE ONLY!
int _X11_flush(ARenderer * Renderer);

// Drawing Functions

int ambR_draw_pixel(AWindow * Wnd, int x, int y);
int ambR_draw_line(AWindow * Wnd, int xA, int yA, int xB, int yB);
int ambR_draw_shape(AWindow * Wnd, int * Coords[]);
int ambR_draw_text(AWindow * Wnd, char * text[], int x, int y);

#endif /* Renderer */
