#include "ambC_label.h"

void _label_draw(AWindow * Wnd, int id){
	AWidget * this = Wnd->Children[id];
	AProperty * text;
	*text = this->data[0];
	int x = this->x;
	int y = this->y;
	ambR_draw_text(Wnd,text->tString,x,y);
}

AWidget ambC_label(char * txt, int x, int y){
	AWidget tWidget;
	tWidget.x = x;
	tWidget.y = y;
	size_t tS = sizeof(AProperty);
	tWidget.data = (AProperty *) malloc(tS);
	AProperty tP;
	tP.tString = txt;
	tWidget.data[0] = tP;
	tWidget.draw = _label_draw;
	return tWidget;
}
