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
  int potB_value = analogRead(A4);
  int mapPotB_value = map(potB_value, 0, 1023, 0, 255);

  // Potentiometer for number of LED 
  int potN_value = analogRead(A5);
  int mapPotN_value = map(potN_value, 0, 1023, 0, NUMOFLEDS);

  // Sync LED brightness to PotB value
  FastLED.setBrightness(mapPotB_value);

  // Sync number of LED to lit to PotN values
  FastLED.clear();
  for (int led = 0; led < mapPotN_value; led++){
    leds[led] = CRGB::Blue;
  }
  for (int led = mapPotN_value; led > 0; led--){
    leds[led] = CRGB::Blue;
  }
  
  FastLED.show();
  delay(50);
}
