#include <Adafruit_NeoPixel.h>
#include <Wire.h>
/*THIS IS THE VERSION :D*/
Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, 3, NEO_BRG + NEO_KHZ800);

#define subnum 4

String myWord = "Blue Alliance";
int subsystem_start[subnum] = {0,8,11,14};
int subsystem_end[subnum] = {7,10,13,21};
int i = 0;
int s = 0;
String mode[subnum];
//hello


void setup() {
  
  // put your setup code here, to run once:
  for (int e = 0; e <= subnum; e++){
    mode[e] = "off";
  }
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
  Serial.println(mode[sub]);
  
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
    
    else if (color == "orange"){
      strip.setPixelColor(x, 255,40,0);
    }
    
    else if (color == "enforcers"){
      if ((x%2 == 0 && i%2 == 0) || (x%2 == 1 && i%2 == 1)) {
        strip.setPixelColor(x, 255,100, 0);
      }
      else if ((x%2 == 1 && i%2 == 0) || (x%2 == 0 && i%2 == 1)){
        strip.setPixelColor(x, 7, 16, 79);
      }
    }

    else if (color == "yellow"){
      strip.setPixelColor(x, 255,100,0);
    }
    
    else if (color == "off"){
      strip.setPixelColor(x,0,0,0);
    }

    else if (color == "red shot"){
        int p = i%(subsystem_end[subsystem]+1);
       if (p == 0) {
        for (int l = 0; l < (subsystem_end[subsystem]+1); l++) {
          strip.setPixelColor(l, 0,0,0);
        }
        strip.setPixelColor(p, 255,0, 0);
        }
    else {
       strip.setPixelColor(p, 255,0, 0);
        strip.setPixelColor(p-1, 0,0,0);
    }
    }

    else if (color == "blue shot"){
        int p = i%(subsystem_end[subsystem]+1);
       if (p == 0) {
        for (int l = 0; l < (subsystem_end[subsystem]+1); l++) {
          strip.setPixelColor(l, 0,0,0);
        }
        strip.setPixelColor(p, 0 ,0, 255);
        }
    else {
       strip.setPixelColor(p, 0 ,0, 255);
        strip.setPixelColor(p-1, 0,0,0);
    }
    }

    else if (color == "enforcers shot"){
        int p = i%(subsystem_end[subsystem]+1);
       if (p == 0) {
        for (int l = 0; l < (subsystem_end[subsystem]+1); l++) {
          strip.setPixelColor(l, 7, 16, 79);
        }
        strip.setPixelColor(p, 255,100, 0);
        }
    else {
       strip.setPixelColor(p, 255,100, 0);
        strip.setPixelColor(p-1, 7, 16, 79);
    }
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

    else if (color == "seaweed"){
      if ((x%3 == 0 && i%3 == 0) || (x%3 == 1 && i%3 == 1) || (x%3 == 2 && i%3 == 2)){
        strip.setPixelColor(x, 0,255,0);
      }
      else if ((x%3 == 0 && i%3 == 1) || (x%3 == 1 && i%3 == 2) || (x%3 == 2 && i%3 == 0)){
        strip.setPixelColor(x, 0,100,0);
      }
      else if ((x%3 == 0 && i%3 == 2) || (x%3 == 1 && i%3 == 0) || (x%3 == 2 && i%3 == 1)){
        strip.setPixelColor(x, 100,255,0);
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
