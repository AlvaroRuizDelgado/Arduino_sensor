## How to connect a MacBook to the HC-06

The connection to an HC-06 requires a few steps:
1) First cable it properly (don't forget to connect the Rx of the arduino to the bluetooth's Tx, and viceversa).
2) Pair it to your computer (default password is '1234'). However, the HC-06 will keep blinking, it is not truly connected yet.
3) Open a terminal, find the bluetooth device in the /dev/ folder, and open a stream to it.
```shell
cat -v /dev/tty.HC-06-DevB
```
Now the bluetooth's LED should stop blinking. This terminal will show the bluetooth's output.
4) Send text to the HC-06 through another terminal.
```shell
echo -n -e "hello bluetooth" > /dev/tty.HC-06-DevB
```

You can see the process in the video below, which was pretty helpful to get this going.
https://www.youtube.com/watch?v=0TzYDOIaDYA

This page is very edifying about how to interact with the bluetooth module.
http://forcetronic.blogspot.jp/2014/08/getting-started-with-hc-06-bluetooth.html
