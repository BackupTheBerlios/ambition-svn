CC=gcc
LD=ld

renderer:
	$(CC) ambR_test.c -lambR -L/usr/X11R6/lib -lX11 -o rtest -I../../Renderer/X11/trunk

types:
	$(CC) sizeof.c -o types
	chmod +x types

widget:
	$(CC) ambC_test.c  -L. -laLabel -laBtn -lambR -L/usr/X11R6/lib -lX11 -o wtest -I../../Renderer/X11/trunk

