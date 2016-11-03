#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(36, 0, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  turnAllOff();
  
}


void loop() {
  String message = "I'm gonna hurl";

  if (message == "I'm gonna jump") {
    turnEnforcers();
  } else if (message == "I bumped into a thing") {
    turnRed();
  } else if (message == "I'ma turn left") {
    turnPeenk();
  } else if (message == "It's Christmas tiiiiiime") {
    turnChristmas();
  } else if (message == "I'm gonna swim with the mermaids") {
    turnBlue();
  } else if (message == "I'm gonna hurl myself into the sun") {
    turnYellow();
  } else if (message == "I'm gonna hurl") {
    turnGreen();
  }
}


void turnAllOff() {
  for (int i=0; i<=36; i++){
  strip.setPixelColor(i,0,0,0);
}
  strip.show();
}



void turnRed() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=3){
      strip.setPixelColor(i+x,255,0,0);
      strip.setPixelColor(i+(x-1),255,0,0);
      strip.setPixelColor(i+(x-2),255,44,0);
  
      strip.setPixelColor(i-x,255,0,0);
      strip.setPixelColor(i-(x+1),255,0,0);
      strip.setPixelColor(i-(x+2),255,44,0);
    } 
    strip.show();
    delay(100);
  }

}

void turnYellow() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=3){
      strip.setPixelColor(i+x,255,255,0);
      strip.setPixelColor(i+(x-1),255,255,0);
      strip.setPixelColor(i+(x-2),255,215,0);
  
      strip.setPixelColor(i-x,255,255,0);
      strip.setPixelColor(i-(x+1),255,255,0);
      strip.setPixelColor(i-(x+2),255,215,0);
    } 
    strip.show();
    delay(100);
  }

}

void turnGreen() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=3){
      strip.setPixelColor(i+x,0,255,0);
      strip.setPixelColor(i+(x-1),0,255,0);
      strip.setPixelColor(i+(x-2),100,255,0);
  
      strip.setPixelColor(i-x,0,255,0);
      strip.setPixelColor(i-(x+1),0,255,0);
      strip.setPixelColor(i-(x+2),100,255,0);
    } 
    strip.show();
    delay(100);
  }

}

void turnBlue() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=3){
      strip.setPixelColor(i+x,0,0,255);
      strip.setPixelColor(i+(x-1),0,0,255);
      strip.setPixelColor(i+(x-2),0,255,255);
  
      strip.setPixelColor(i-x,0,0,255);
      strip.setPixelColor(i-(x+1),0,0,255);
      strip.setPixelColor(i-(x+2),0,255,255);
    } 
    strip.show();
    delay(100);
  }

}

void turnPeenk() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=3){
      strip.setPixelColor(i+x,255,0,255);
      strip.setPixelColor(i+(x-1),255,0,255);
      strip.setPixelColor(i+(x-2),255,0,100);
  
      strip.setPixelColor(i-x,255,0,255);
      strip.setPixelColor(i-(x+1),255,0,255);
      strip.setPixelColor(i-(x+2),255,0,100);
    } 
    strip.show();
    delay(100);
  }

}

void turnChristmas() {
  for (int i=36; i > 0; i--){
    for(int x= 0; x <=36; x+=4){
      strip.setPixelColor(i+x,255,0,0);
      strip.setPixelColor(i+(x-1),255,0,0);
      strip.setPixelColor(i+(x-2),255,0,0);
      strip.setPixelColor(i+(x-3),0,255,0);
      
      strip.setPixelColor(i-x,255,0,0);
      strip.setPixelColor(i-(x+1),255,0,0);
      strip.setPixelColor(i-(x+2),0,255,0);
      strip.setPixelColor(i-(x+3),0,255,0);
    }  
  strip.show();
  delay(125);
  }
}

void turnEnforcers() {
  // enforcers Colors:
 for (int i=36; i > 0; i--){
   for(int x= 0; x <=36; x+=4){
      strip.setPixelColor(i+x,229,187,0);
      strip.setPixelColor(i+(x-1),229,187,0);
      strip.setPixelColor(i+(x-2),7,16,79);
      strip.setPixelColor(i+(x-3),7,16,79);
  
      strip.setPixelColor(i-x,229,187,0);
      strip.setPixelColor(i-(x+1),229,187,0);
      strip.setPixelColor(i-(x+2),7,16,99);
      strip.setPixelColor(i-(x+3),7,16,99);
   }
   
  strip.show();
  delay(125);
  }
}
