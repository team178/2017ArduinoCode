#include <Adafruit_NeoPixel.h>
#include <Wire.h>
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, 3, NEO_GRB + NEO_KHZ800);

String myWord = "Blue Alliance";
int subsystem_start[3]={0,12,24};
int subsystem_end[3] = {11,23,35};
int i = 0;


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
    else if (color == "red"){
      strip.setPixelColor(x, 255,0,0);
    }
    else if (color == "blue"){
      strip.setPixelColor(x, 0, 0, 255);
    }
    else if (color == "Enforcers"){
      if ((x%2 == 1 && i%2 == 1) || (x%2 == 0 && i%2 == 0)) {
        strip.setPixelColor(x, 229, 187, 0);
      }
      else if ((x%2 == 1 && i%2 == 0) || (x%2 == 0 && i%2 == 1)){
        strip.setPixelColor(x, 7, 16, 79);
      }

    }
    else if(color == "Rainbow"){
      strip.setPixelColor(x,255,0,0);
      strip.setPixelColor(x,255,165,0);
      strip.setPixelColor(x,255,255,0);
      strip.setPixelColor(x,0,255,0);
      strip.setPixelColor(x,0,0,255);
      strip.setPixelColor(x,255,0,255);
    }
  }
}


void loop() {
  setSubsystemLights(2, "green");
  setSubsystemLights(1, "red");
  setSubsystemLights(0, "Enforcers");
  strip.show();
  delay(500);
  i++;
}
