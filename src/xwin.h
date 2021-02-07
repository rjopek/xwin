/*
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#ifndef XWIN_H_
#define XWIN_H_

#include <math.h>           /* cos(), sin(), etc.        */
#include <stdarg.h>         /* va_list, va_start(), etc. */
#include <stdbool.h>        /* true, false, etc.         */
#include <stdio.h>          /* fprintf(), etc.           */
#include <stdlib.h>         /* exit(), getenv(), etc.    */
#include <string.h>         /* strlen(), etc.            */
#include <time.h>           /* time(), etc.              */
#include <sys/time.h>       /* gettimeofday(), etc.      */

#include <X11/cursorfont.h>
#include <X11/keysymdef.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

#define EVENT_MASK ( ExposureMask | StructureNotifyMask | FocusChangeMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask | KeyPressMask | KeyReleaseMask | VisibilityChangeMask )

#define Lock( pDisplay )   do { XLockDisplay( pDisplay )
#define Unlock( pDisplay ) XUnlockDisplay( pDisplay ); } while( 0 )

#define Abs( a )    ( ( ( a ) <  0 ) ? - ( a ) : ( a ) )
#define Len( a )    ( sizeof( a ) / sizeof( a ) [ 0 ] )
#define Max( a, b ) ( ( a ) < ( b ) ? ( b ) : ( a ) )
#define Min( a, b ) ( ( a ) < ( b ) ? ( a ) : ( b ) )
#define RandomInt( min, max ) ( ( rand() % ( int ) ( ( ( max ) + 1u ) - ( min ) ) ) + ( min ) )
#define Unused( a ) ( void ) a

typedef enum
{
   /* reserved = 0 */
   BACKGROUND = 1,
   BACKGROUNDHEX,
   CIRCLE,
   CLEAR,
   CLEARAREA,
   CLIPBOTTOM,
   CLIPLEFT,
   CLIPRIGHT,
   CLIPTOP,
   ELLIPSE,
   FILLEDCIRCLE,
   FILLEDELLIPSE,
   FILLEDRECT,
   FLOODFILL,
   GETPIXEL,
   LINE,
   MAKECOLOR,
   MOUSEPOS_X,
   MOUSEPOS_Y,
   PUTPIXEL,
   RECT,
   SCREENHEIGHT,
   SCREENWIDTH,
   SETCLIP,
   SETCURSOR,
   WINDOW_X,
   WINDOW_Y,
   WINDOWHEIGHT,
   WINDOWWIDTH,
   SIZE_OF_TYPE_INT
} TYPE_INT;

#define Background( red, green, blue ) XWinInt( BACKGROUND, red, green, blue )
#define BackgroundHex( hex ) XWinInt( BACKGROUNDHEX, hex )
#define Circle( y, x, radius, color ) XWinInt( CIRCLE, y, x, radius, color )
#define Clear() XWinInt( CLEAR )
#define ClearArea( top, left, bottom, right ) XWinInt( CLEARAREA, top, left, bottom, right )
#define ClipBottom() XWinInt( CLIPBOTTOM )
#define ClipLeft() XWinInt( CLIPLEFT )
#define ClipRight() XWinInt( CLIPRIGHT )
#define ClipTop() XWinInt( CLIPTOP )
#define Ellipse( y, x, rady, radx, color ) XWinInt( ELLIPSE, y, x, rady, radx, color )
#define FilledCircle( y, x, radius, color ) XWinInt( FILLEDCIRCLE, y, x, radius, color )
#define FilledEllipse( y, x, rady, radx, color ) XWinInt( FILLEDELLIPSE, y, x, rady, radx, color )
#define FilledRect( top, left, bottom, right, color ) XWinInt( FILLEDRECT, top, left, bottom, right, color )
#define FloodFill( y, x, color ) XWinInt( FLOODFILL, y, x, color )
#define GetClip( top, left, bottom, right ) top = XWinInt( CLIPTOP ); left = XWinInt( CLIPLEFT ); bottom = XWinInt( CLIPBOTTOM ); right = XWinInt( CLIPRIGHT )
#define GetPixel( y, x ) XWinInt( GETPIXEL, y, x )
#define Line( top, left, bottom, right, color ) XWinInt( LINE, top, left, bottom, right, color )
#define MakeColor( red, green, blue ) XWinInt( MAKECOLOR, red, green, blue )
#define MousePosX() XWinInt( MOUSEPOS_X )
#define MousePosY() XWinInt( MOUSEPOS_y )
#define PutPixel( y, x, color ) XWinInt( PUTPIXEL, y, x, color )
#define Rect( top, left, bottom, right, color ) XWinInt( RECT, top, left, bottom, right, color )
#define ScreenHeight() XWinInt( SCREENHEIGHT )
#define ScreenWidth() XWinInt( SCREENWIDTH )
#define SetClip( top, left, bottom, right ) XWinInt( SETCLIP, top, left, bottom, right )
#define SetCursor( shape ) XWinInt( SETCURSOR, shape )
#define WindowHeight() XWinInt( WINDOWHEIGHT )
#define WindowWidth() XWinInt( WINDOWWIDTH )
#define WindowX() XWinInt( WINDOW_X )
#define WindowY() XWinInt( WINDOW_Y )

typedef enum
{
   /* reserved = 0 */
   GETWINDOWNAME = 1,
   SETWINDOWNAME,
   SIZE_OF_TYPE_CHR
} TYPE_CHR;

#define GetWindowName()       XWinChr( GETWINDOWNAME )
#define SetWindowName( name ) XWinChr( SETWINDOWNAME, name )

const char* XWinChr();
int  XWinInkey( void );
int  XWinInt();
unsigned long MilliSeconds( void );
unsigned long TimerGet( void );
void ReleaseCPU( long microseconds );
void XWinClose( void );
void XWinInit( int argc, char* argv[] );
void XWinOpen( unsigned int width, unsigned int height, const char* window_name );

#endif /* --- End XWIN_H_ --- */
