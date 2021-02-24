//+--------------------------------------------------------------------------
// 
// Random flashes
//
// File:                  
//
// Description: Draws random flashes on the lED strip
//
//   
//
// History:     Feb-21-2021     Derek      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];
void RandomFlashes() {
  long randNumber1;
  long randNumber2;
  long randNumber3;
  long randNumber4;

  for (int i = 0; i < 400; i++) {
    randNumber1 = random(0, NUM_LEDS + 1);
    g_LEDs[randNumber1] = CRGB( 200, 172, 68) ;

    randNumber2 = random(0, NUM_LEDS + 1);
    g_LEDs[randNumber2] = CRGB( 200, 172, 68) ;

    randNumber3 = random(0, NUM_LEDS + 1);
    g_LEDs[randNumber3] = CRGB( 200, 172, 68) ;

    randNumber4 = random(0, NUM_LEDS + 1);
    g_LEDs[randNumber4] = CRGB( 200, 172, 68) ;

    Serial.print("I is ");
    Serial.println(i);

    FastLED.show();
    FastLED.delay(2);
    FastLED.clear();
  }
}