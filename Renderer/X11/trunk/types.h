#ifndef AMBITION_TYPES

#define AMBITION_TYPES

/* Defines the ARenderer type [Platform Dependent] */

typedef struct _Renderer{
        Display * rDisplay;	// Pointer to X11 Display
        int cCount;		// Number of child Windows
        struct _Window * Children[];	// Array of Pointers to child Windows
} ARenderer;

/* Defines the AWindow type [Platform Dependent] */

typedef struct _Window{
        ARenderer * Renderer;	// Pointer to parent Renderer
	GC XGC;			// X11 Graphics Context for Drawing
	XFontStruct XFont;	// Current X11 Font
        Window XWindow;		// Target X11 Window
        int cCount;		// Number of child Widgets
        struct _Widget * Children[];	// Array of Pointers to child Widgets
} AWindow;

/* Defines the AWidget type [Platform Independent] */

typedef struct _Widget{
        AWindow * Parent;	// Pointer to parent Window
        void (*draw)(AWindow*,int);	// Pointer to "draw" callback
} AWidget;

/* Defines a union of all types that require callbacks [Platform Independent] */

typedef union _Object{
        AWindow tWindow;	//
        AWidget tWidget;
} AObject;

#endif /* TYPES */
