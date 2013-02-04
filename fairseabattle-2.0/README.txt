FairSeaBattle
-------------

The FairSeaBattle -- sink the computer's fleet.

You can get FairSeaBattle here:
http://fairseabattle.googlecode.com/

Building
--------

Before building, you will need to have the Qt4 library installed
on your system (http://www.trolltech.com/).

Build:

$ qmake # or qmake-qt4
$ make  # or mingw32-make or nmake or other

Test it:

$ ./fairseabattle

Install:

$ sudo cp ./fairseabattle /usr/local/bin/fairseabattle

or same
$ sudo make install

you can specify root dir of installation
if you want to prepare package or just
have reasons to do this
$ sudo make INSTALL_ROOT=/opt install

Enjoy!

Alexey Michurin
a.michurin@gmail.com
