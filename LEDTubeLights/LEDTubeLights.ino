#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_TUBES 7
#define NUM_LEDS_PER_TUBE 6
#define BRIGHTNESS 200

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_TUBES * NUM_LEDS_PER_TUBE, PIN, NEO_GRBW + NEO_KHZ800);

int gamma = 0;
boolean fadeIn = true;
String country = "deu";

byte neopix_gamma[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
    2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
    5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
   10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
   17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
   25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
   37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
   51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
   69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
   90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
  115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
  144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
  177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
  215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

  

void setup() {
  
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); 

  Serial.begin(9600);
  
}

void loop() {

  if(fadeIn) gamma++;
  else gamma--;
  
  if(gamma>254) {
    
    fadeIn = false;
    delay(5000);
    
  }
  
  if(gamma<1) {
    
    fadeIn = true;
    if(country=="deu") {

      country = "swe";
      setSweden(gamma);
      
    }else{

      country = "deu";
      setGermany(gamma);
      
    }
    
  }

  if(country=="deu") setGermany(gamma);
  if(country=="swe") setSweden(gamma);
  
  strip.show(); 
  
  delay(5);

}

void setGermany(int gamma){

  int r = neopix_gamma[gamma];
  int g = neopix_gamma[gamma*80/100];
  
  setRow(0, strip.Color(r,g,0,0));
  setRow(1, strip.Color(r,g,0,0));
  setRow(2, strip.Color(r,0,0,0));
  setRow(3, strip.Color(r,0,0,0));
  setRow(4, strip.Color(0,0,0,0));
  setRow(5, strip.Color(0,0,0,0));
  
}

void setSweden(int gamma){

  int r = neopix_gamma[gamma];
  int g = neopix_gamma[gamma];
  int b = neopix_gamma[gamma];

  setRow(5, strip.Color(0,0,b,0));
  setRow(4, strip.Color(0,0,b,0));
  setRow(3, strip.Color(r,g,0,0));
  setRow(2, strip.Color(0,0,b,0));
  setRow(1, strip.Color(0,0,b,0));
  setRow(0, strip.Color(0,0,b,0));
  setCol(1, strip.Color(r,g,0,0));
  
}

void setRow(int y, uint32_t color){

  for(int i=0; i<NUM_TUBES; i++){
    
    strip.setPixelColor(y+(i*NUM_LEDS_PER_TUBE), color);
    
  }
  
}

void setCol(int x, uint32_t color){

  for(int i=0; i<NUM_LEDS_PER_TUBE; i++){

    strip.setPixelColor(i+(x*NUM_LEDS_PER_TUBE), color);
    
  }
  
}


