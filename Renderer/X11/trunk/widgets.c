#include "renderer.h"
#include "widgets.h"

int ambC_get_property(AWidget * Widget,int pId, AProperty * pData){
	if((sizeof(Widget->data)/sizeof(AProperty)) >= pId){
		pData = &Widget->data[pId];
		return 0;
	}else{
		return 1;
	}
}

int ambC_set_property(AWidget * Widget, int pId, AProperty * pData){
	if((sizeof(Widget->data)/sizeof(AProperty)) >= pId){
		Widget->data[pId] = *pData;
		return 0;
	}else{
		return 1;
	}
}


int ambC_has_point(AWidget * Widget, int x, int y){
	int tX,tY,tW,tH;
	tX = Widget->x;
	tY = Widget->y;
	tW = Widget->w;
	tH = Widget->h;
	if((x > tX) && (y > tY) && (x < tX + tW) && (y < tY + tH)){
		return 1;
	}else{
		return 0;
	}
}
