CC=gcc
LD=ld
all: renderer.c renderer.h window.c window.h types.h
	$(CC) --version
	$(CC) -c renderer.c window.c -I/usr/include/freetype2/freetype
	$(LD) -r -o libambR.so renderer.o window.o
test: ambR_test.c all
	$(CC) ambR_test.c -L. -lambR -L/usr/X11R6/lib -lX11 -o test
	chmod +x test
# Moved to Tools/TestSuite
#widget: test_widget.c all
#	$(CC) -c ambC_label.c
#	$(LD) -r -o libaLabel.so ambC_label.o
#	$(CC) -c ambC_button.c
#	$(LD) -r -o libaBtn.so ambC_button.o
#wtest: all widget
#	$(CC) ambC_test.c  -L. -laLabel -laBtn -lambR -L/usr/X11R6/lib -lX11 -o wtest
	
