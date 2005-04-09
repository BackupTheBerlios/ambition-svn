#include <X11/Xlib.h>

#ifdef AMBITION_WIDGETS

#include "renderer.h"

int ambC_get_property(AWidget * Widget, int pId, AProperty * pData);
int ambC_set_property(AWidget * Widget, int pId, AProperty * pData);
int ambC_has_point(AWidget * Widget, int x, int y);

#endif
