/*
 * XWin library: Moving circles - example-00.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * gcc example-00.c xwin.c -o example-00 -lX11
 *
 */

#include "xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int circle[ 5 ];
   int height = 0;
   int width = 0;
   int i, n;
   int y, x, radius = 100;

   if ( argc < 2 )
   {
      n = 45;
   }
   else
   {
      n = atoi( argv[ 1 ] );
   }

   XWinInit( argc, argv );

   XWinOpen( 800, 600, "Moving circles - example-00.c" );

   srand( time( NULL ) );

   circle[ 2 ] =  1;
   circle[ 3 ] = -1;
   circle[ 4 ] = RandomInt( 0x0, 0xffffff );

   while( condition )
   {
      if( height != WindowHeight() || width != WindowWidth() )
      {
         height = WindowHeight();
         width = WindowWidth();
         circle[ 0 ] = height / 2;
         circle[ 1 ] = width / 2;
      }

      Clear();

      if( circle[ 0 ] < radius * 2 )
      {
         circle[ 2 ] = - circle[ 2 ];
         circle[ 4 ] = RandomInt( 0x0, 0xffffff );
      }

      if( circle[ 1 ] < radius * 2 )
      {
         circle[ 3 ] = - circle[ 3 ];
         circle[ 4 ] = RandomInt( 0x0, 0xffffff );
      }

      if( circle[ 0 ] > height - radius * 2 )
      {
         circle[ 2 ] = - circle[ 2 ];
         circle[ 4 ] = RandomInt( 0x0, 0xffffff );
      }

      if( circle[ 1 ] > width - radius * 2 )
      {
         circle[ 3 ] = - circle[ 3 ];
         circle[ 4 ] = RandomInt( 0x0, 0xffffff );
      }

      circle[ 0 ] += circle[ 2 ];
      circle[ 1 ] += circle[ 3 ];

      for( i = 0; i < n; i++ )
      {
         y = cos( M_PI + i * 2 * M_PI / n ) * radius + circle[ 0 ];
         x = sin(        i * 2 * M_PI / n ) * radius + circle[ 1 ];

         Circle( y, x, radius, circle[ 4 ] );
      }
   }

   XWinClose();

   return 0;
}
