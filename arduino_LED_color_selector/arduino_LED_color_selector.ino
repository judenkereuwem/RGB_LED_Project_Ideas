// Arduino with WS2812B LED Ring Light
// Control LED brightness and number of LED to turn on with potentiometer
// October 2023

#include <FastLED.h>
#define LEDPIN 3 
#define NUMOFLEDS 16 

CRGB leds[NUMOFLEDS]; 

void setup() {
  FastLED.addLeds<WS2812, LEDPIN, GRB>(leds, NUMOFLEDS);
}

void loop() {

  // Potentiometer for brightness
  int potR = analogRead(A4);
  int potG = analogRead(A5);
  int potB = analogRead(A6);
  delay(50);


  // Sync number of LED to lit to PotN values
  FastLED.clear();
  
  for (int led = 0; led <= 15; led++){
    leds[led] = CRGB(potR, potG, potB);  
    FastLED.show();
  }
}
