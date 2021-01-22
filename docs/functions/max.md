---
layout: default
title: Max
---

# Max()

Return the larger of two numeric values

{% highlight c %}
Max( n1, n2 );
{% endhighlight %}

**Arguments**

`n1` and `n2` are the numeric values to be compared.

**Returns**

Max() returns the larger of the two arguments.

**Description**

Max() is a numeric function that ensures the value of an expression is larger than a specified minimum. The inverse of Max() is Min(), which returns the lesser of two numeric values.

**Examples**

In these examples Max() returns the greater of two numeric values:

{% highlight c linenos %}
printf( "Max( 1 - 2 ) = %d\n", Max( 1 - 2 ) );
printf( "Max( 2 - 1 ) = %d\n", Max( 2 - 1 ) );
{% endhighlight %}

Output:

{% highlight terminal %}
Max( 1 - 2 ) = 2
Max( 2 - 1 ) = 2
{% endhighlight %}
