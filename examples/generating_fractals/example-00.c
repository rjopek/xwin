/*
 * XWin library: Sierpinski triangle - example-00.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * cc example-00.c ../../src/xwin.c -o example-00 -lX11 -lm
 *
 */

#include "../../src/xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int height = 0;
   int width = 0;
   int key;
   int y, x, color;
   unsigned int i;

   XWinInit( argc, argv );

   XWinOpen( 800, 600, "Sierpinski triangle  - example-00.c" );

   while( condition )
   {
      if( height != WindowHeight() || width != WindowWidth() )
      {
         height = WindowHeight();
         width = WindowWidth();

         y = 0;
         x = width;

         for( i = 0; i < height * width / 2; i++ )
         {
            switch( RandomInt( 0, 2 ) )
            {
            case 0:
               y = ( y + 0 ) / 2;
               x = ( x + width / 2 ) / 2;
               color = 0x0f785b;
               break;
            case 1:
               y = ( y + height ) / 2;
               x = ( x + 0 ) / 2;
               color = 0xffcc00;
               break;
            case 2:
               y = ( y + height ) / 2;
               x = ( x + width ) / 2;
               color = 0x8a8a8a;
               break;
            }

            PutPixel( y, x, color );
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
