// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  saySomething("red");
  saySomething("help");
  saySomething("bloop");
  saySomething("noodle noodle noodle");
  
}


void saySomething(char message[]){
  Wire.beginTransmission(1); // transmit to device #8
  Wire.write(message);        // sends five bytes
  Wire.endTransmission();    // stop transmitting
  delay(500);
}
