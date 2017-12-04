# Arduino stuff

This repository contains some early tests with the Arduino. The final goal is to have a system that gathers info from a sensor, prepares statistics, and delivers them on-demand to a mobile phone via bluetooth.

## Setup with Visual Studio Code

First you need to install the arduino plugin (I use the one by MicroSoft).

For the different settings, Command + Shift + P opens the command console.
- Arduino: board config        --> select the arduino board.
- Arduino: select serial port  --> select the USB port where the arduino is connected.
- Arduino: open serial monitor --> link the serial port to the "output" tab.
- Arduino: change baud rate    --> select the appropriate baud rate (9600 by default).

Reference: https://qiita.com/narikei/items/847613a8f01a9e1527d7

## Bluetooth setup

### Reference pages

http://www.instructables.com/id/Add-bluetooth-to-your-Arduino-project-ArduinoHC-06/

https://mcuoneclipse.com/2013/06/19/using-the-hc-06-bluetooth-module/
