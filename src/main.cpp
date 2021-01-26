//+--------------------------------------------------------------------------
// This is from a Youtube series by Dave's Garage
// 
//
// File:        LED Episode 02
//
// Description:
//
// Draws sample effects on the intergrated OLED
//
// History:     Jan-25-2021     Derek      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>    // Arduino Framework
#include <U8g2lib.h>  // For text on the little on-chip OLED

#define OLED_CLOCK 15     // Pins for OLED display
#define OLED_DATA 4
#define OLED_RESET 16

U8G2_SSD1306_128X64_NONAME_F_SW_I2C g_oled(U8G2_R2, OLED_CLOCK, OLED_DATA, OLED_RESET);
int g_linehight = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);

  g_oled.begin();
  g_oled.clear(); //sets curser at 0,0. Text draws from the bottom up so you will see nothing.
  g_oled.setFont(u8g2_font_profont15_tf);
  g_linehight = g_oled.getFontAscent() - g_oled.getFontDescent(); // Decent is a negative number so we add it to the total
  g_oled.setCursor(0,g_linehight);                                // Place cursor at bottom of first line of text
  g_oled.print("Dave's Garage");
  g_oled.setCursor(0,g_linehight*2);                              // Place cursor at bottom of second line of text
    g_oled.printf("Line height: %d", g_linehight);
  g_oled.sendBuffer();                                            // Print it out to the OLED
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,0);
  delay(500);
  digitalWrite(LED_BUILTIN,1);
  delay(500);
}