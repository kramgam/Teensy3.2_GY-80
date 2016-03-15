# Teensy3.2_GY-80
Readings from all sensors on GY-80 inertial measurement unit (IMU) board using the Arduino IDE, Teensy Loader 1.21, and a Teensy 3.2.

To use, leave all the .ino files in the Teensy3.2_GY-80 folder. Open any of the files. Upload to Teensy 3.2.

Use 4.7kohm pullup resistors for SDA and SCL. In other words, connect a 4.7k resistor between SDA->3.3v and SCL->3.3v. These are called pullup resistors since they are connected to the high 3.3v line. Pulldown would be connected from pin to ground.


Open the serial monitor to see readings from sensors. Use MegunoLink Lite to graph the readings or change the serial outputs to suit your needs.


