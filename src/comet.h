//+--------------------------------------------------------------------------
//
// NightDriver - (c) 2020 Dave Plummer.  All Rights Reserved.
//
// File:                  
//
// Description:
//
//   
//
// History:     Sep-28-2020     davepl      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>
#define FASTLED_INTERNAL
#include <FastLED.h>

extern CRGB g_LEDs[];

void DrawComet()
{
    static int lNumber = 0;
    for (lNumber = 0; lNumber < NUM_LEDS * 6; lNumber++) 
    {
    const byte fadeAmt = 128;
    const int cometSize = 5;
    const int deltaHue  = 4;

    static byte hue = HUE_RED;
    static int iDirection = 1;
    static int iPos = 0;

    hue += deltaHue;

    iPos += iDirection;
    if (iPos == (NUM_LEDS - cometSize) || iPos == 0)
        iDirection *= -1;
    
    for (int i = 0; i < cometSize; i++)
//        g_LEDs[iPos + i].setColorCode(0xFFFFFF); // set to pure white via hex
          g_LEDs[iPos + 1] = CRGB( 255, 255, 255) ; // set to pure white via RGB
    // Randomly fade the LEDs
    for (int j = 0; j < NUM_LEDS; j++)
        if (random(10) > 5)
            g_LEDs[j] = g_LEDs[j].fadeToBlackBy(fadeAmt);  
    FastLED.show();
    Serial.println(lNumber);
    delay(10);
    }
}