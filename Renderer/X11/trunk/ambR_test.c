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
	// Loop
	ambR_draw_line(&myWin,90,10,10,50);
	ambR_draw_line(&myWin,90,90,10,50);
	ambR_draw_line(&myWin,50,30,50,70);
	ambR_main(myRenderer);
	printf("Close\n");
	// Close the Renderer
	ambR_close(myRenderer);
	return 0;
}
