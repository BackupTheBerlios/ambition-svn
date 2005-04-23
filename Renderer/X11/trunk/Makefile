CC=gcc
LD=ld

all: main

main: renderer.c renderer.h window.c window.h widgets.c widgets.h types.h
	$(CC) --version
	$(CC) -c renderer.c window.c widgets.c -I/usr/include/freetype2/
	$(LD) -r -o libambR.so renderer.o window.o widgets.o

test: ambR_test.c main
	$(CC) ambR_test.c -L. -lambR -L/usr/X11R6/lib -lX11 -I/usr/include/freetype2/ -o test -lcairo
	chmod +x test

sizeof: sizeof.c main
	$(CC) sizeof.c -L/usr/X11R6/lib -lX11 -I/usr/include/freetype2/ -o sizeof -lcairo
	chmod +x sizeof

install: main
	install *.h /usr/include/Ambition/
	cp libambR.so /usr/lib/

# Moved to Tools/TestSuite
#widget: test_widget.c all
#	$(CC) -c ambC_label.c
#	$(LD) -r -o libaLabel.so ambC_label.o
#	$(CC) -c ambC_button.c
#	$(LD) -r -o libaBtn.so ambC_button.o
#wtest: all widget
#	$(CC) ambC_test.c  -L. -laLabel -laBtn -lambR -L/usr/X11R6/lib -lX11 -o wtest
	
