#include <stdio.h> 
#include <unistd.h>
#include "renderer.h"
#include "window.h"
#include "types.h"

int main(int argc, char * argv[]){
	ARenderer * myRenderer;
	printf("Init\n");
	// Initialize the Renderer
	ambR_init(myRenderer);
	AWindow myWin;
	char * title[12];
	*title = "Hello World";
	printf("Create Window\n");
	// Create a new window
	myWin = ambW_create(myRenderer, title, 0, 0, 100, 100);
	printf("Show Window\n");
	// Show the new window
	ambW_show(&myWin);
	ambR_draw_arc(&myWin,50,50,50,0);
	ambR_draw_arc(&myWin,50,50,50,1);
	ambR_draw_arc(&myWin,50,50,50,2);
	ambR_draw_arc(&myWin,50,50,50,3);
	/*ambR_draw_line(&myWin,90,10,10,50);
	ambR_draw_line(&myWin,90,90,10,50);
	ambR_draw_line(&myWin,50,30,50,70);
	char* fName = "*-helvetica-*-12-*";
	printf("Set Font\n");
	ambW_set_font(&myWin,fName);
	//char * tText[100];
	char *tText = "Ambition";
	printf("Draw\n");
	ambR_draw_text(&myWin,tText,100,10);*/
	printf("Main\n");
	ambR_main(myRenderer);
	printf("Close\n");
	// Close the Renderer
	ambR_close(myRenderer);
	return 0;
}
