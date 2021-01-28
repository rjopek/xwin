/*
 * XWin library: Overlapping circles grid - example-03.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * gcc example-03.c xwin.c -o example-03 -lX11
 * ./example-03
 *
 */

#include "xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int height = 0;
   int width = 0;
   int i, n;
   int y, x, rady = 150, radx = 150;
   int key;

   if ( argc < 2 )
   {
      n = 45;
   }
   else
   {
      n = atoi( argv[ 1 ] );
   }

   XWinInit( argc, argv );

   XWinOpen( 800, 800, "Overlapping circles grid - example-03.c" );

   while( condition )
   {
      if( height != WindowHeight() || width != WindowWidth() )
      {
         height = WindowHeight();
         width = WindowWidth();

         for( i = 0; i < n; i++ )
         {
            y = cos( M_PI + i * 2 * M_PI / n ) * rady + height / 2;
            x = sin(        i * 2 * M_PI / n ) * radx + width / 2;

            Ellipse( y, x, height / 4, width / 4, 0x00ff00 );
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
