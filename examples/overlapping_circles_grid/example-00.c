/*
 * XWin library: Overlapping circles grid - example-00.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * -mwindows a Windows app is built which doesn't produce a console window.
 * gcc example-00.c xwin.c -o example-00 -lX11 -lm
 *
 */

#include "xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int height = 0;
   int width = 0;
   int y, x, i;
   int key;

   XWinInit( argc, argv );

   XWinOpen( 800, 600, "Overlapping circles grid - example-00.c" );

   while( condition )
   {
      if( height != WindowHeight() || width != WindowWidth() )
      {
         height = WindowHeight();
         width  = WindowWidth();

         for( i = 1; i < 45; i++ )
         {
            y = cos( i ) * 100 + height / 2;
            x = sin( i ) * 100 + width / 2;
            Circle( y, x, 100, 0xffc800 );
         }
      }

      key = XWinInkey();

      switch( key )
      {
      case XK_Escape:
         condition = false;
         break;
      }
   }

   XWinClose();

   return 0;
}
