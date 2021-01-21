---
layout: default
title: Abs()
---

# Abs()

Return the absolute value of a numeric expression

``` c
Abs( arg );
```

**Arguments**

`arg` is the numeric expression to be evaluated.

**Returns**

Abs() returns a number representing the absolute value of its argument. The return value is a positive number or zero.

**Description**

Abs() is a numeric function that determines the magnitude of a numeric value independent of its sign. It lets you, for example, obtain the difference between two numbers as a positive value without knowing in advance which of the two is larger.

As a formalism, Abs( arg ) is defined in terms of its argument, `arg`, as follows: if( arg >= 0 ), Abs( arg ) returns `arg`; otherwise, Abs( arg ) returns the negation of `arg`.

**Examples**
These examples show typical results from Abs():

``` c
printf( "100 - 150 = %d\n", 100 - 150 );
printf( "Abs( 100 - 150 ) = %d\n", Abs( 100 - 150 ) );
printf( "Abs( 150 - 100 ) = %d\n", Abs( 150 - 100 ) );
printf( "Abs( -3 ) = %d\n", Abs( -3 ) );
printf( "Abs( 0 ) = %d\n", Abs( 0 ) );
```

Output:

```
100 - 150 = -50
Abs( 100 - 150 ) = 50
Abs( 150 - 100 ) = 50
Abs( -3 ) = 3
Abs( 0 ) = 0
```


