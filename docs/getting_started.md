---
layout: default
title: Getting Started
---

# Getting Started

## MS-Windows

Cygwin - a collection of free and open source tools that provide a Unix-like environment functionality to Windows-based programs, and a POSIX library for Windows. Cygwin consists of a Unix system call emulation library, cygwin1.dll, together with a vast set of GNU and other free software applications organized into a large number of optional packages. Among these packages are high quality compilers and other software development tools, an X11 server, a complete X11 development toolkit, and much more, including everything needed to compile and use **XWin** library under MS-Windows. The project has an easy-to-use installation program. For more info see [**Installing Cygwin/X**](https://x.cygwin.com/docs/ug/cygwin-x-ug.html).

## GNU/Linux distributions

For Debian and Debian derivatives including Ubuntu:

``` c
sudo apt-get install -y libx11-dev
```

For Fedora:

``` c
sudo yum install libx11-devel
```

For openSUSE:

``` c
zypper install libx11-devel
```

> Note: -y flag means to assume yes and silently install, without asking you questions in most cases.

## Mac OS X

Using [MacPorts](https://www.macports.org/), the port is called 'xorg-libX11', so you can just type:

``` c
sudo port install xorg-libX11
```

And to upgrade to newer versions once installed:

``` c
sudo port upgrade xorg-libX11
```

## XWin live source repository

Clone an existing repository only fetching the 10 most recent commits on the default branch (useful to save time):

``` c
git clone --depth 10 https://github.com/rjopek/xwin.git
```
