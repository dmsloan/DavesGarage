//+--------------------------------------------------------------------------
// This is from a Youtube series by Dave's Garage
// 
//
// File:        LED Episode 03
//  
// Description:
//  OLED Graphics - Lines and Shapes - SPI & I2C
//  Draws sample effects on the intergrated OLED
//  Calculates the frame rate to draw the OLED
//
// History:     Jan-26-2021     Derek      Created
//
//---------------------------------------------------------------------------

#include <Arduino.h>    // Arduino Framework
#include <U8g2lib.h>  // For text on the little on-chip OLED

#define OLED_CLOCK 15     // Pins for OLED display
#define OLED_DATA 4
#define OLED_RESET 16

//U8G2_SSD1306_128X64_NONAME_F_SW_I2C g_oled(U8G2_R2, OLED_CLOCK, OLED_DATA, OLED_RESET); // uses Software I2C and results in a framerate of 5 FPS

//clock and data got swapped around to use hardware I2C instead of software
U8G2_SSD1306_128X64_NONAME_F_HW_I2C g_oled(U8G2_R2, OLED_RESET, OLED_CLOCK, OLED_DATA); // uses Hardware I2C and results in a framerate of 26 FPS 
int g_linehight = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);

  g_oled.begin();
  g_oled.clear(); //sets curser at 0,0. Text draws from the bottom up so you will see nothing.
  g_oled.setFont(u8g2_font_profont15_tf);
 
  g_linehight = g_oled.getFontAscent() - g_oled.getFontDescent(); // Decent is a negative number so we add it to the total
 
}


// FramePerSecond
//
// Tracks a weighted average in order to smooth out the values that it is given. Computes the FPS
// as the simple reciprocal of the amount of taken specified by the caller. So 1/3 of a second is 3 fps. 
// it takes about ten frames to sabilize.
double FramesPerSecond (double seconds){
  static double framesPerSecond;
  framesPerSecond = (framesPerSecond * 0.9) + (1.0 / seconds * 0.1);
  return framesPerSecond;
}

void DrawLinesAngGrapicaFrame(int framesPerSecond){

  g_oled.clearBuffer();
  g_oled.home();

  g_oled.drawFrame(0,0,g_oled.getWidth(),g_oled.getHeight());     // Draw a boarder around the display

  g_oled.setCursor(3,g_linehight * 2 + 2);
  g_oled.print("Hello");
  g_oled.setCursor(3,g_linehight * 3 + 2);
  g_oled.print("World");
  g_oled.setCursor(3,g_linehight * 4 + 2);
  g_oled.printf("%03d", framesPerSecond);                         // Placeholder for frame rate

  // Draw a morie pattern like its 1984

  for (int x = 0; x < g_oled.getWidth(); x += 4)
    g_oled.drawLine(x,0,g_oled.getWidth()-x,g_oled.getHeight());

  // Draw a reticle on the right hand side

  const int reticleY = g_oled.getHeight() / 2;                  // Vertical center of display
  const int reticleR = g_oled.getHeight() / 4 - 2;              // Slightly less than 1/4 screen height
  const int reticleX = g_oled.getWidth() - reticleR - 8;        // Right justified plus a margin
   
  for (int r = reticleR; r > 0; r -= 3)
    g_oled.drawCircle(reticleX, reticleY, r);                   // Draw a series of nested circles

  g_oled.drawHLine(reticleX - reticleR - 5, reticleY, 2 * reticleR + 10); // Horizontal line through center
  g_oled.drawVLine(reticleX, reticleY - reticleR -5 , 2 * reticleR + 10); // Vertical line through center

  g_oled.sendBuffer();                                            // Print it out to the OLED
}

void loop() {
  // put your main code here, to run repeatedly:
  
  static bool bLED = LOW;
  int fps = 0;

  for (;;)                                  // This is a forever loop
    {
      bLED = !bLED;                         // Toggle the LED state
      digitalWrite(LED_BUILTIN,bLED);

      double dStart = millis() / 1000.0;    // Record the start time
      DrawLinesAngGrapicaFrame(fps);
      double dEnd = millis() / 1000.0;      // Record the finish time
      fps = FramesPerSecond(dEnd - dStart); // Calculate the FPS rate
    }
}