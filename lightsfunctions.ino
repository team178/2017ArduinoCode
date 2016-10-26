
#include <Adafruit_NeoPixel.h>

int numPixels = 12;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPixels, 0, NEO_GRB + NEO_KHZ800);

void setup() {
  
  strip.begin();
  strip.show();
  strip.setPixelColor(0,0,0,0);
  strip.setPixelColor(1,0,0,0);
  strip.setPixelColor(2,0,0,0);
  strip.setPixelColor(3,0,0,0);
  strip.setPixelColor(4,0,0,0);
  strip.setPixelColor(5,0,0,0);
  strip.setPixelColor(6,0,0,0);
  strip.setPixelColor(7,0,0,0);
  strip.show();

}

void loop(){
  turnBlue();
}


void turnBlue() {
  // When the bumper is hit
  for (int i=7; i >= 0; i--){
    strip.setPixelColor((i+1)%8,0,0,0);
    strip.setPixelColor(i,0,0,255);
    strip.show();
    delay(100);
    }
}

//when the robot is going forward
void something(){
  
}
//backwards
void sometingelse(){
   
}
//left
void something3(){
  
}
//right
void something4(){
  
}
