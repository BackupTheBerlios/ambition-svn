#include <stdio.h> 
#include <unistd.h>
#include "renderer.h"
#include "window.h"
#include "types.h"
#include "ambC_button.h"
#include "ambC_label.h"

int main(int argc, char * argv[]){
	ARenderer * myRenderer;
	ambR_init(myRenderer);
	AWindow myWin;
	char * title[20];
	*title = "Window Name";
	myWin = ambW_create(myRenderer, title, 0, 0, 600, 480);
	ambR_add_child(myRenderer,&myWin);
	ambW_show(&myWin);
	char* fName = "*-helvetica-*-12-*";
	ambW_set_font(&myWin,fName);
	char * msg = "Hello, Ambition";
	//AWidget lblMain = ambC_label(msg, 10, 10);
	//ambW_add_child(&myWin,&lblMain);
	AWidget btnMain = ambC_button(msg,5,5,90,90);
	ambW_add_child(&myWin,&btnMain);	
	ambW_draw(&myWin);
	ambR_main(myRenderer);
	ambR_close(myRenderer);
	return 0;
}
