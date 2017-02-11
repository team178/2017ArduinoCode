#include <Adafruit_NeoPixel.h>
#include <Wire.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, 3, NEO_GRB + NEO_KHZ800);

String myWord = "Blue Alliance";
int subsystem_start[3]={0,12,24};
int subsystem_end[3] = {11,23,35};

void setup() {
  
  // put your setup code here, to run once:
 Wire.begin(8);               
  Wire.onReceive(readRoborioMessage); 
  Serial.begin(9600);
  Serial.println("I got it!");
}

void readRoborioMessage(int howMany) {
  myWord = "";
  while (0 < Wire.available()) {
    char c = Wire.read();
    myWord = myWord + c;
  }
  Serial.println("hello");
  Serial.println(myWord);
  //go to Tools --> Serial Monitor or press Ctrl+Shift+M
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0 is red
  strip.setPixelColor(subsystem_start[0],0,255,0,0);
  // 1 is green
  strip.setPixelColor(subsystem_start[1],0,255,0);
  // 2 is blue
  strip.setPixelColor(subsystem_start[2],0,0,255);
  //show for 500ms
  strip.show();
  delay(500);
  // 0 is green
  // 1 is blue
  // 2 is red
  //show for 500ms
  

}
