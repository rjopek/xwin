/*
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 */

#include "xwin.h"

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

Display* display;
Window   window;
GC       gc;
Colormap colormap;
Pixmap   pixmap;

int      screen_number;
int      depth;
int      ncolors;
int      event_xkey_x = 0;
int      event_xkey_y = 0;

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void XWinInit( int argc, char* argv[] )
{
   char* display_name = getenv( "DISPLAY" );                                  /* address of the X display. */

   if( ( display = XOpenDisplay( display_name ) ) == NULL )                   /* open connection with the X server. */
   {
      fprintf( stderr, "%s: Cannot connect to X server %s\n", argv[ 0 ], display_name );
      exit( 1 );
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void XWinOpen( unsigned int width, unsigned int height, const char* window_name )
{
   unsigned long foreground;
   unsigned long background;
   unsigned int border_width = 2;
   XSetWindowAttributes set_window_attributes;
   Visual* visual;

   screen_number = DefaultScreen( display );
   foreground = WhitePixel( display, screen_number );
   background = BlackPixel( display, screen_number );

   window = XCreateSimpleWindow( display, DefaultRootWindow( display ), 0, 0, width, height, border_width, foreground, background );

   XSelectInput( display, window, EVENT_MASK );

   XMapWindow( display, window );

   XFlush(display);

   gc = XCreateGC( display, window, 0, 0 );

   visual = DefaultVisual( display, screen_number );

   colormap = DefaultColormap( display, screen_number );

   depth = DisplayPlanes( display, screen_number );

   ncolors = DisplayCells( display, screen_number );

   pixmap = XCreatePixmap( display, window, DisplayWidth( display, screen_number ), DisplayHeight( display, screen_number ), depth );

   XDefineCursor( display, window, None );

   set_window_attributes.backing_store = Always;

   XChangeWindowAttributes( display, window, CWBackingStore, &set_window_attributes );

   XStoreName( display, window, window_name );

   while( 1 )
   {
      XEvent event;

      XNextEvent( display, &event );

      if( event.type == MapNotify )
         break;
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void XWinClose()
{
   XFreeGC( display, gc );
   XDestroyWindow( display, window );
   XCloseDisplay( display );
   exit( 1 );
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

int XWinInkey()
{
   XFlush( display );

   while( 1 )
   {
      XEvent event;
      XNextEvent( display, &event );

      switch( event.type )
      {
      case KeyPress:
         event_xkey_x = event.xkey.x;
         event_xkey_y = event.xkey.y;
         return XLookupKeysym( &event.xkey, 0 );

      case MotionNotify:
         event_xkey_x = event.xkey.x;
         event_xkey_y = event.xkey.y;
         return event.xbutton.button;

      case ButtonPress:
         event_xkey_x = event.xkey.x;
         event_xkey_y = event.xkey.y;
         return event.xbutton.button;

      case ConfigureNotify:
         event_xkey_x = event.xkey.x;
         event_xkey_y = event.xkey.y;
         return event.xbutton.button;

      default:
         return 0;
      }
   }
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

int XWinInt( TYPE_INT type, int top, int left, int bottom, int right, int foreground )
{
   int result = 1;
   XColor color;
   Cursor cursor;
   XImage* image;
   XRectangle ClipRect;
   XSetWindowAttributes set_window_attributes;
   XWindowAttributes window_attributes;

   switch( type )
   {
   case BACKGROUND: /* <-- */
      color.pixel = 0;
      color.red = top << 8;
      color.green = left << 8;
      color.blue = bottom << 8 ;
      color.flags = DoRed | DoGreen | DoBlue;
      Lock( display );
      XAllocColor( display, colormap, &color );
      set_window_attributes.background_pixel = color.pixel;
      XChangeWindowAttributes( display, window, CWBackPixel, &set_window_attributes );
      XClearWindow( display, window ); /* <-- */
      Unlock( display );
      break;

   case BACKGROUNDHEX:
      color.pixel = 0;
      color.red   = ( ( top >> 16 ) & 0xff ) << 8;
      color.green = ( ( top >> 8) & 0xff ) << 8;
      color.blue  = ( ( top ) & 0xff ) << 8;
      color.flags = DoRed | DoGreen | DoBlue;
      Lock( display );
      XAllocColor( display, colormap, &color );
      set_window_attributes.background_pixel = color.pixel;
      XChangeWindowAttributes( display, window, CWBackPixel, &set_window_attributes );
      XClearWindow( display, window ); /* <-- */
      Unlock( display );
      break;

   case CIRCLE:
      top -= bottom;
      left -= bottom;
      bottom <<= 1;
      Lock( display );
      XSetForeground( display, gc, right );
      XDrawArc( display, window, gc, left, top, bottom, bottom, 0, 360 * 64 );
      Unlock( display );
      break;

   case CLEAR:
      Lock( display );
      XClearWindow( display, window );
      Unlock( display );
      break;

   case CLEARAREA:
      Lock( display );
      XClearArea( display, window, left, top, right - left, bottom - top, true );
      Unlock( display );
      break;

   case CLIPBOTTOM:
      result = ClipRect.y + ClipRect.height - 1;
      break;

   case CLIPLEFT:
      result = ClipRect.x;
      break;

   case CLIPRIGHT:
      result = ClipRect.x + ClipRect.width - 1;
      break;

   case CLIPTOP:
      result = ClipRect.y;
      break;

   case ELLIPSE:
      top -= bottom;
      left -= right;
      bottom <<= 1;
      right <<= 1;
      Lock( display );
      XSetForeground( display, gc, foreground );
      XDrawArc( display, window, gc, left, top, right, bottom, 0, 360 * 64 );
      Unlock( display );
      break;

   case FILLEDCIRCLE:
      top -= bottom;
      left -= bottom;
      bottom <<= 1;
      Lock( display );
      XSetForeground( display, gc, right );
      XFillArc( display, window, gc, left, top, bottom, bottom, 0, 360 * 64 );
      Unlock( display );
      break;

   case FILLEDELLIPSE:
      top -= bottom;
      left -= right;
      bottom <<= 1;
      right <<= 1;
      Lock( display );
      XSetForeground( display, gc, foreground );
      XFillArc( display, window, gc, left, top, right, bottom, 0, 360 * 64 );
      Unlock( display );
      break;

   case FILLEDRECT:
      Lock( display );
      XSetForeground( display, gc, foreground );
      XFillRectangle( display, window, gc, left, top, right - left, bottom - top );
      Unlock( display );
      break;

   case FLOODFILL:
       break;

   case GETPIXEL:
      Lock( display );
      image = XGetImage( display, window, left, top, 1, 1, AllPlanes, XYPixmap );
      if( image )
      {
         color.pixel = XGetPixel( image, 0, 0 );
         XQueryColor( display, colormap, &color );
         result = ( ( color.red >> 8 ) & 0xFF ) << 16 | ( ( color.green >> 8 ) & 0xFF ) << 8 | ( ( color.blue >> 8 ) & 0xFF );
         XDestroyImage( image );
      }
      else
      {
         result = 0;
      }
      Unlock( display );
      break;

   case LINE:
      Lock( display );
      XSetForeground( display, gc, foreground );
      XDrawLine( display, window, gc, left, top, right, bottom );
      Unlock( display );
      break;

   case MAKECOLOR:
      color.red = top << 8;
      color.green = left << 8;
      color.blue = bottom << 8;
      color.flags = DoRed | DoGreen | DoBlue;
      Lock( display );
      XSetForeground( display, gc, color.pixel );
      XAllocColor( display, colormap, &color );
      Unlock( display );
      result = color.pixel;
      break;

   case MOUSEPOS_X:
      result = event_xkey_x;
      break;

   case MOUSEPOS_Y:
      result = event_xkey_y;
      break;

   case PUTPIXEL:
      Lock( display );
      XSetForeground( display, gc, bottom );
      XDrawPoint( display, window, gc, left, top );
      Unlock( display );
      break;

   case RECT:
      Lock( display );
      XSetForeground( display, gc, foreground );
      XDrawRectangle( display, window, gc, left, top, right - left, bottom - top );
      Unlock( display );
      break;

   case SCREENHEIGHT:
      result = XDisplayHeight( display, screen_number );
      break;

   case SCREENWIDTH:
      result = XDisplayWidth( display, screen_number );
      break;

   case SETCURSOR:
      cursor = XCreateFontCursor( display, top );
      XDefineCursor( display, window, cursor );
      XSync( display, false );
      break;

   case WINDOW_X:
      XGetWindowAttributes( display, window, &window_attributes );
      result = window_attributes.x;
      break;

   case WINDOW_Y:
      XGetWindowAttributes( display, window, &window_attributes );
      result = window_attributes.y;
      break;

   case WINDOWHEIGHT:
      XGetWindowAttributes( display, window, &window_attributes );
      result = window_attributes.height;
      break;

   case WINDOWWIDTH:
      XGetWindowAttributes( display, window, &window_attributes );
      result = window_attributes.width;
      break;

   case SETCLIP:
      ClipRect.y = top;
      ClipRect.x = left;
      ClipRect.width = bottom;
      ClipRect.height = right;
      Lock( display );
      XSetClipRectangles( display, gc, 0, 0, &ClipRect, 1, YXBanded );
      Unlock( display );
      break;

   default:
      return 0;
   }
   return result;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

const char* XWinChr( TYPE_CHR type, const char* window_name )
{
   const char* result;

   switch( type )
   {
   case GETWINDOWNAME:
      break;

   case SETWINDOWNAME:

      if( window_name && * window_name )
      {
         XTextProperty text;

         text.value = ( unsigned char * ) window_name;
         text.encoding = XInternAtom( display, "UTF8_STRING", false );
         text.format = 8;
         text.nitems = strlen( window_name );
         XSetWMName( display, window, &text );
      }
      else
      {
         XStoreName( display, window, window_name );
      }
      break;

   default:
      return NULL;
   }
   return result;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

unsigned long MilliSeconds( void )
{
   struct timeval tv;

   if( gettimeofday( &tv, NULL ) < 0 )
   {
      return 0;
   }

   return ( ( unsigned long ) tv.tv_sec + ( unsigned long ) 2440588 * 86400 ) * 1000 + tv.tv_usec / 1000;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

unsigned long TimerGet( void )
{
   struct timeval tv;

   if( gettimeofday( &tv, NULL ) < 0 )
   {
      return 0;
   }

   return ( unsigned long ) tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */

void ReleaseCPU( long microseconds )
{
   struct timeval tv;

   tv.tv_sec = 0;

   tv.tv_usec = microseconds;

   select( 0, NULL, NULL, NULL, &tv );
}

/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */
