// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.

#include <Adafruit_NeoPixel.h>
#include <Wire.h>

int pin = 8;
String myWord;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  strip.begin();
  strip.setBrightness(50);
  strip.show(); 
  Serial.println("setup");
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  myWord = "";
  while (0 < Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    myWord = myWord + c;
  }
  Serial.println("hello");
  Serial.println(myWord);

  if (myWord == "red") {
    strip.setPixelColor (0, 255, 0, 0);
    strip.setPixelColor (1, 0, 0, 255);
    strip.setPixelColor (2, 0, 255, 0);
    strip.setPixelColor (3, 255, 0, 255);
    strip.setPixelColor (4, 0, 255, 255);
    strip.setPixelColor (5, 255, 255, 0);
    strip.setPixelColor (6, 255, 255, 255);
    strip.setPixelColor (7, 255, 0, 0);
    strip.show();
  }
  else if (myWord == "bloop") {
    strip.setPixelColor (0, 0, 0, 255);
    strip.setPixelColor (1, 255, 0, 0);
    strip.setPixelColor (2, 0, 255, 0);
    strip.setPixelColor (3, 255, 0, 255);
    strip.setPixelColor (4, 0, 255, 255);
    strip.setPixelColor (5, 255, 255, 0);
    strip.setPixelColor (6, 255, 255, 255);
    strip.setPixelColor (7, 0, 0, 255);
    strip.show();
  }
  else if (myWord == "help") {
    strip.setPixelColor (0, 255, 0, 0);
    strip.setPixelColor (1, 255, 0, 0);
    strip.setPixelColor (2, 255, 0, 0);
    strip.setPixelColor (3, 255, 0, 0);
    strip.setPixelColor (4, 255, 0, 0);
    strip.setPixelColor (5, 255, 0, 0);
    strip.setPixelColor (6, 255, 0, 0);
    strip.setPixelColor (7, 255, 0, 0);
    strip.show();
  }
  else if (myWord == "noodle noodle noodle") {
    strip.setPixelColor (0, 0, 255, 0);
    strip.setPixelColor (1, 255, 0, 0);
    strip.setPixelColor (2, 0, 0, 255);
    strip.setPixelColor (3, 255, 0, 255);
    strip.setPixelColor (4, 0, 255, 255);
    strip.setPixelColor (5, 255, 255, 0);
    strip.setPixelColor (6, 255, 255, 255);
    strip.setPixelColor (7, 0, 255, 0); 
    strip.show();
  }
  else if (myWord == "rainbow") {
    strip.setPixelColor (0, 255, 0, 0);
    strip.setPixelColor (1, 255, 100, 0);
    strip.setPixelColor (2, 255, 255, 0);
    strip.setPixelColor (3, 0, 255, 0);
    strip.setPixelColor (4, 0, 255, 255);
    strip.setPixelColor (5, 0, 0, 255);
    strip.setPixelColor (6, 100, 0, 255);
    strip.setPixelColor (7, 255, 0, 255); 
    strip.show();

  }
  else {
     strip.setPixelColor (0, 0, 0, 0);
     strip.setPixelColor (1, 0, 0, 0);
     strip.setPixelColor (2, 0, 0, 0);
     strip.setPixelColor (3, 0, 0, 0);
     strip.setPixelColor (4, 0, 0, 0);
     strip.setPixelColor (5, 0, 0, 0);
     strip.setPixelColor (6, 0, 0, 0);
     strip.setPixelColor (7, 0, 0, 0);
     strip.show();
  }
/*    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }*/
}
