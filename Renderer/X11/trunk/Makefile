CC=gcc
LD=ld
all: renderer.c renderer.h window.c window.h types.h
	$(CC) --version
	$(CC) -c renderer.c window.c 
	$(LD) -r -o libambR.so renderer.o window.o
test: ambR_test.c all
	$(CC) ambR_test.c -L. -lambR -L/usr/X11R6/lib -lX11 -o test
	chmod +x test
