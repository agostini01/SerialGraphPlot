SerialGraphPlot
===============
I was needing real time plotting over serial, so I adapted codes from QtCreator terminal example (LGPL - <http://doc.qt.io/qt-5/qtserialport-terminal-example.html>) and used the QCustomPlot library (GPL - <http://www.qcustomplot.com/>) to partially accomplish what I was looking for.

What does it do?
================

It handles up to 8 curves acquired from the serial interface in the following format.
I say "up to" because you can hide the curves you are not plotting, pressing toggle buttons.
Serial is configurable.

TIME DATA1 DATA2 DATA3 DATA4 DATA5 DATA6 DATA7 DATA8

like this:

10319727 -4940034 -4943618 -4911362 -4910082 -4913154 -4894978 -4912898 -4904960

10320725 -4937218 -4938754 -4909826 -4912642 -4916226 -4893186 -4919298 -4907520

10324715 4392449 4401153 4428545 4419329 4415489 4439041 4403969 4436736


What it does not do?
===================

* Data logger (it is simple, but not yet)
* Allocate plots dynamically. Memory efficient... I was in a hurry.
* Halts plotting processing while plot window is closed (I know, pretty bad uhh?)
* Plot different curves in different plots.
* If spikes occurs, it will resize your plot. I was too lazy to correct that.

Other delimiter?
================

I know... commas, spaces, semicolons...
you should change what is in
 “datapackagehandler.cpp”


How to use?
===========

1. Install QtCreator <https://www.qt.io/download/> (community!!) Start installation and go grab a coffee, it may take a while (15 to 30 min, depending on the Internet);
2. open project and configure it;
3. run (it should run just fine);
4. configure serial communication under gear button;
5. press connect button;
6. open graph dialog.


Should you get it?
==================

.. image:: https://raw.githubusercontent.com/agostini01/SerialGraphPlot/master/sample.png
    :alt: Sample Image
    :width: 679
    :height: 781
    :align: center


Licensing
=========
GPL!
