# arduino-fan-control
Source code for Arduino which runs a fan connected to it in two modes:
a.)Automatic: Fan speed depends on room temperature. As room temperature increases, fan speed increases.
b.)Manual: Fan speed can be controlled with Android app using Bluetooth communication. By sending specific data to arduino, fan can be switched ON/OFF and its speed can be varied.

Sensors/Modules used with Arduino:
a.) LM35 temperature sensor is used with Arduino to monitor room temperature.
b.) HC05 module is used with Arduino to enable Bluetooth Communication with Android app.

Android app to be used to send commands: ARDUINO BLUETOOTH CONTROLLER 
PlayStore link: https://play.google.com/store/apps/details?id=com.giumig.apps.bluetoothserialmonitor

Commands to be entered on app:
1.) 'a' : Automatic mode
2.) 'b' : Manual Mode
3.) In Manual Mode:
a.) '0' : fan speed 0
b.) '1' : fan speed 1
c.) '2' : fan speed 2
d.) '3' : fan speed 3
e.) '4' : fan speed 4
f.) '5' : fan speed 5

Detaied info about the project : Arduino-fan-control.pptx
Source code about the project  : fan.ino
