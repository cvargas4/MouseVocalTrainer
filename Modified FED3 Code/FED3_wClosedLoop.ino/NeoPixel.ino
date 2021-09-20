/********************************************************
// Fill the dots one after the other with a color
 ********************************************************/
void colorWipe(uint32_t c, uint8_t wait) {
  digitalWrite (MOTOR_ENABLE, HIGH);  //ENABLE RGB/motor driver
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
  digitalWrite (MOTOR_ENABLE, LOW);  //DISABLE RGB/motor driver
}

void RcolorWipe(uint32_t c, uint8_t wait) {  //reverse color wipe
  digitalWrite (MOTOR_ENABLE, HIGH);  //ENABLE RGB/motor driver
  for(uint16_t j=0; j<strip.numPixels(); j++) {
    strip.setPixelColor(7-j, c);
    strip.show();
    delay(wait);
    digitalWrite (MOTOR_ENABLE, LOW);  //DISABLE RGB/motor driver
  }
}

void fillPixels(uint32_t c, uint8_t wait) {
  digitalWrite (MOTOR_ENABLE, HIGH);  //ENABLE RGB/motor driver
  strip.fill(c);
  strip.show();
  delay(wait);
  digitalWrite (MOTOR_ENABLE, LOW);  //DISABLE RGB/motor driver
}
/********************************************************
   HELPER FUNCTION FOR BLINKING ONBOARD LEDS ON FEATHER
 ********************************************************/
void Blink(byte PIN, byte DELAY_MS, byte loops) {
  for (byte i = 0; i < loops; i++)  {
    digitalWrite(PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(PIN, LOW);
    delay(DELAY_MS);
  }
}
