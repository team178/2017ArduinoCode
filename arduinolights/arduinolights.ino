#include <Adafruit_NeoPixel.h>
#include <Wire.h>
/*THIS IS THE VERSION :D*/
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, 3, NEO_GRB + NEO_KHZ800);

#define subnum 4

String myWord = "Blue Alliance";
int subsystem_start[subnum] = {0,9,18,27};
int subsystem_end[subnum] = {8,17,26,35};
int i = 0;
int s = 0;
String mode[subnum]={"off", "off", "off", "off"};
//number of "off"'s should equal subnum


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
  int sub;
  String pat;
  sub = myWord.substring(0,1).toInt();
  pat = myWord.substring(1);
  mode[sub] = pat;
  //Serial.println(mode[sub]);
  
  //go to Tools --> Serial Monitor or press Ctrl+Shift+M
}

void runSubsystemLights(int subsystem, String color){
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
    
    else if (color == "enforcers"){
      if ((x%2 == 0 && i%2 == 0) || (x%2 == 1 && i%2 == 1)) {
        strip.setPixelColor(x, 229, 187, 0);
      }
      else if ((x%2 == 1 && i%2 == 0) || (x%2 == 0 && i%2 == 1)){
        strip.setPixelColor(x, 7, 16, 79);
      }
    }
    
    else if (color == "off"){
      strip.setPixelColor(x,0,0,0);
    }
      
    else if (color == "ocean"){
      
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

    else if (color == "fire"){
      
      if ((x%3 == 0 && i%3 == 0) || (x%3 == 1 && i%3 == 1) || (x%3 == 2 && i%3 == 2)){
        strip.setPixelColor(x, 255,11,0);
      }
      else if ((x%3 == 0 && i%3 == 1) || (x%3 == 1 && i%3 == 2) || (x%3 == 2 && i%3 == 0)){
        strip.setPixelColor(x, 255,44,0);
      }
      else if ((x%3 == 0 && i%3 == 2) || (x%3 == 1 && i%3 == 0) || (x%3 == 2 && i%3 == 1)){
        strip.setPixelColor(x, 255,69,0);
      }
    }
    
   else if(color == "rainbow"){
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
  for (int s = 0; s < subnum; s++){
    runSubsystemLights(s, mode[s]);
  }
  strip.show();
  delay(100);
  i++;
}
