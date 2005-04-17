CC=gcc
LD=ld

all: label

label:
	$(CC) -c ambC_label.c -I/usr/include/freetype2/
	$(LD) -r -o libaLabel.so ambC_label.o

wtest: all
	$(CC) ambC_test.c  -L. -laLabel -lambR -L/usr/X11R6/lib -lcairo -lX11 -o wtest -I/usr/include/freetype2/



