#include <stdio.h>
#include "renderer.h"

int main(void){
	printf("Renderer: %d\n",sizeof(ARenderer));
	AWindow * tmpW;
	printf("Window: %d\n",sizeof(AWindow));
	printf("Window *: %d\n",sizeof(tmpW));
	printf("Widget: %d\n",sizeof(AWidget));
	printf("Property: %d\n",sizeof(AProperty));
	return 0;
}
