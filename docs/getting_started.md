---
layout: default
title: Getting Started
author: Rafał Jopek
---

# Getting Started

## MS-Windows

**Xming** is the leading X Window System Server for Microsoft Windows®. It is fully featured, lean, fast, simple to install and because it is standalone native Windows, easily made portable (not needing a machine-specific installation or access to the Windows registry). [**Xming X Server for Windows**](https://sourceforge.net/projects/xming/files/Xming/6.9.0.31/)


**Cygwin** - a collection of free and open source tools that provide a Unix-like environment functionality to Windows-based programs, and a POSIX library for Windows. Cygwin consists of a Unix system call emulation library, cygwin1.dll, together with a vast set of GNU and other free software applications organized into a large number of optional packages. Among these packages are high quality compilers and other software development tools, an X11 server, a complete X11 development toolkit, and much more, including everything needed to compile and use **XWin** library under MS-Windows. The project has an easy-to-use installation program. For more info see [**Installing Cygwin/X**](https://x.cygwin.com/docs/ug/cygwin-x-ug.html).

## GNU/Linux distributions

For Debian and Debian derivatives including Ubuntu:

{% highlight terminal %}
sudo apt-get install -y libx11-dev
{% endhighlight %}

For Fedora:

{% highlight terminal %}
sudo yum install libx11-devel
{% endhighlight %}

For openSUSE:

{% highlight terminal %}
zypper install libx11-devel
{% endhighlight %}

> Note: -y flag means to assume yes and silently install, without asking you questions in most cases.

## Mac OS X

Using [**MacPorts**](https://www.macports.org/), the port is called 'xorg-libX11', so you can just type:

{% highlight terminal %}
sudo port install xorg-libX11
{% endhighlight %}

And to upgrade to newer versions once installed:

{% highlight terminal %}
sudo port upgrade xorg-libX11
{% endhighlight %}

## XWin live source repository

Clone an existing repository only fetching the 10 most recent commits on the default branch (useful to save time):

{% highlight terminal %}
git clone --depth 10 https://github.com/rjopek/xwin.git
{% endhighlight %}
