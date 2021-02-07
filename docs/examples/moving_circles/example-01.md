---
layout: default
title: example-01
---

# example-01.c

{% highlight c linenos %}
/*
 * XWin library: Moving circles - example-01.c
 *
 * Copyright 2020-2021 Rafał Jopek ( rafaljopek at hotmail com )
 *
 * cc example-01.c ../../src/xwin.c -o example-01 -lX11 -lm
 *
 */

#include "../../src/xwin.h"

int main( int argc, char* argv[] )
{
   bool condition = true;
   int circle[ 2 ];
   int height = 0;
   int width = 0;
   int i, n;
   int y, x, radius = 100;
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

   XWinOpen( 800, 600, "Moving circles - example-01.c" );

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

      for( i = 0; i < n; i++ )
      {
         y = cos( M_PI + i * 2 * M_PI / n ) * radius + circle[ 0 ];
         x = sin(        i * 2 * M_PI / n ) * radius + circle[ 1 ];

         Circle( y, x, radius, 0x0f785b );
      }

      key = XWinInkey();

      switch( key )
      {
      case XK_Escape:
         condition = false;
         break;

      case XK_Up:
         if( circle[ 0 ] <= 0 )
         {
            circle[ 0 ] = height;
         }
         else
         {
            circle[ 0 ]--;
         }
         break;

      case XK_Left:
         if( circle[ 1 ] <= 0 )
         {
            circle[ 1 ] = width;
         }
         else
         {
            circle[ 1 ]--;
         }
         break;

      case XK_Down:
         if( circle[ 0 ] >= height )
         {
            circle[ 0 ] = 0;
         }
         else
         {
            circle[ 0 ]++;
         }
         break;

      case XK_Right:
         if( circle[ 1 ] >= width )
         {
            circle[ 1 ] = 0;
         }
         else
         {
            circle[ 1 ]++;
         }
         break;
      }
   }

   XWinClose();

   return 0;
}

{% endhighlight %}
