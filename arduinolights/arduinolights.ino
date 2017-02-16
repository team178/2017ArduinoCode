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
      if ((x%2 == 0 && i%2 == 0) || (x%2 == 1 && i%2 == 1)) {
        strip.setPixelColor(x, 229, 187, 0);
      }
      else if ((x%2 == 1 && i%2 == 0) || (x%2 == 0 && i%2 == 1)){
        strip.setPixelColor(x, 7, 16, 79);
      }
    }

      
    else if (color == "Ocean"){
      
      if ((x%3 == 0 && i%3 == 0) || (x%3 == 1 && i%3 == 1) || (x%3 == 2 && i%3 == 2)){
        strip.setPixelColor(x, 0, 0, 255);
      }
      else if ((x%3 == 0 && i%3 == 1) || (x%3 == 1 && i%3 == 2) || (x%3 == 2 && i%3 == 0)){
        strip.setPixelColor(x, 0, 200, 255);
      }
      else if ((x%3 == 0 && i%3 == 2) || (x%3 == 1 && i%3 == 0) || (x%3 == 2 && i%3 == 1)){
        strip.setPixelColor(x, 0, 0, 128);
      }
    }
    
   else if(color == "Rainbow"){
      //red
      if ((x%6 == 0 && i%6 == 0) || (x%6 == 1 && i%6 == 1)||(x%6 == 2 && i%6 == 2)|| (x%6 == 3 && i%6 == 3)||(x%6 == 4 && i%6 == 4)|| (x%6 == 5 && i%6 == 5)) {
      strip.setPixelColor(x,255,0,0);
      }
     //orange
      if ((x%6 == 0 && i%6 == 5) || (x%6 == 1 && i%6 == 0)||(x%6 == 2 && i%6 == 1)|| (x%6 == 3 && i%6 == 2)||(x%6 == 4 && i%6 == 3)|| (x%6 == 5 && i%6 == 4)) {
      strip.setPixelColor(x,255,165,0);
      }
      //yellow
      if ((x%6 == 0 && i%6 == 4) || (x%6 == 1 && i%6 == 5)||(x%6 == 2 && i%6 == 0)|| (x%6 == 3 && i%6 == 1)||(x%6 == 4 && i%6 == 2)|| (x%6 == 5 && i%6 == 3)) {
      strip.setPixelColor(x,255,255,0);
      }
      //green
      if ((x%6 == 0 && i%6 == 3) || (x%6 == 1 && i%6 == 4)||(x%6 == 2 && i%6 == 5)|| (x%6 == 3 && i%6 == 0)||(x%6 == 4 && i%6 == 1)|| (x%6 == 5 && i%6 == 2)) {
      strip.setPixelColor(x,0,255,0);
      }
      //blue
      if ((x%6 == 0 && i%6 == 2) || (x%6 == 1 && i%6 == 3)||(x%6 == 2 && i%6 == 4)|| (x%6 == 3 && i%6 == 5)||(x%6 == 4 && i%6 == 0)|| (x%6 == 5 && i%6 == 1)) {
      strip.setPixelColor(x,0,0,255);
      }
      //purple
      if ((x%6 == 0 && i%6 == 1) || (x%6 == 1 && i%6 == 2)||(x%6 == 2 && i%6 == 3)|| (x%6 == 3 && i%6 == 4)||(x%6 == 4 && i%6 == 5)|| (x%6 == 5 && i%6 == 0)) {
      strip.setPixelColor(x,255,0,255);
      }
     } 
    }
  }

void loop() {
  setSubsystemLights(2, "blue");
  setSubsystemLights(1, "red");
  setSubsystemLights(0, "Ocean");
  strip.show();
  delay(500);
  i++;
}
