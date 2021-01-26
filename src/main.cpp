#include <Arduino.h>
#include <U8g2lib.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,0);
  delay(500);
  digitalWrite(LED_BUILTIN,1);
  delay(500);
}