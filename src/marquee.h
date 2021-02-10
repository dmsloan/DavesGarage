//+--------------------------------------------------------------------------
// This is from a Youtube series by Dave's Garage
// 
//
// File: marquee.h
//  
// Description:
//   Draws an old Movie Theatre styule marquee, but in color
//  
//  
//  
//  
//
// History:     Feb-6-2021     Derek      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>    // Arduino Framework
#define FASTLED_INTERNAL
#include <FastLED.h>

void DrawMarquee(){
    static byte j = HUE_BLUE;
    j += 4;
    byte k = j;

    // The following is roughly equilivent to fill_rainbow(g_LEDs, NUM_LEDS, j, 0)

    CRGB c;
    for (int i = 0; i < NUM_LEDS ; i++)
        g_LEDs[i] = c.setHue(k += 8);

    static int scroll = 0; // static perserves value from one funtion call to the next
        scroll++;

    for (int i = scroll %5; i < NUM_LEDS; i+=5)  //% is the modulo operator gives the remainder of a division of two values 
        g_LEDs[i] = CRGB::Black;

    delay(500);
}
