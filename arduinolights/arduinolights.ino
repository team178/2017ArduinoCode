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
  strip.begin();
  strip.show();
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

void setSubsystemLights(int subsystem, String color){
  for (int x = subsystem_start[subsystem]; x < subsystem_end[subsystem]+1; x+=1){
    if (color == "green"){
     strip.setPixelColor(x, 0,255,0); 
    }
    if (color == "red"){
      strip.setPixelColor(x, 255,0,0);
    }
    if (color == "blue"){
      strip.setPixelColor(x, 0, 0, 255);
    }
  }
}


void loop() {
  setSubsystemLights(2, "green");
  setSubsystemLights(1, "red");
  setSubsystemLights(0, "red");
  strip.show();
  delay(500);

}
