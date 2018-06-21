#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUM_LEDS 60
#define NUM_TUBES 7
#define NUM_LEDS_PER_TUBE 6
#define BRIGHTNESS 250

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRBW + NEO_KHZ800);

void setup() {
  
  strip.setBrightness(BRIGHTNESS);
  strip.begin();
  strip.show(); 
  
}

void loop() {

  setSweden();
  strip.show(); 

}

void setGermany(){

  setRow(0, strip.Color(255,230,0,0));
  setRow(1, strip.Color(255,230,0,0));
  setRow(2, strip.Color(255,0,0,0));
  setRow(3, strip.Color(255,0,0,0));
  setRow(4, strip.Color(0,0,0,0));
  setRow(5, strip.Color(0,0,0,0));
  
}

void setSweden(){

  setRow(5, strip.Color(0,0,255,0));
  setRow(4, strip.Color(0,0,255,0));
  setRow(3, strip.Color(255,255,0,0));
  setRow(2, strip.Color(0,0,255,0));
  setRow(1, strip.Color(0,0,255,0));
  setRow(0, strip.Color(0,0,255,0));
  setCol(1, strip.Color(255,255,0,0));
  
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


