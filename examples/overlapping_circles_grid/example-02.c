/*
 * XWin library: Overlapping circles grid - example-02.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * -mwindows a Windows app is built which doesn't produce a console window.
 * gcc example-02.c xwin.c -o example-02 -lX11 -lm
 *
 */

#include "xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int height = 0;
   int width = 0;
   int y, x, radius = 100, color;
   int key;

   XWinInit( argc, argv );

   XWinOpen( 800, 600, "Overlapping circles grid - example-02.c" );

   while( condition )
   {
      if( height != WindowHeight() || width != WindowWidth() )
      {
         height = WindowHeight();
         width = WindowWidth();

         for( x = -50; x < width + radius; x += 50 )
         {
            for( y = -50; y < height + radius; y += 50 )
            {
               Circle( y, x, radius, 0x5b0f78 );
            }
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
