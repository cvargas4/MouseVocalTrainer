/********************************************************
  Conditioned stimlus
********************************************************/

void ConditionedStimulus() {
  tone (BUZZER, 4000, 200);
  colorWipe(strip.Color(0, 2, 2), 40); // Color wipe
  colorWipe(strip.Color(0, 0, 0), 20); // OFF
}

void PairedStimulus(){
  tone (BUZZER, 4000, 200);
  delay(50); //buzzer was making weird sound, probably from sharing power with neopixel this resolved some of it
  fillPixels(strip.Color(0, 2, 2), 300); // Color wipe
  fillPixels(strip.Color(0, 0, 0), 0); // OFF
}

void RConditionedStim() {
  tone (BUZZER, 4000, 200);
  RcolorWipe(strip.Color(0, 2, 2), 40); // Color wipe
  RcolorWipe(strip.Color(0, 0, 0), 20); // OFF
}

/********************************************************
  Visual tracking stimulus - left
********************************************************/
void leftStimulus() {
  strip.setPixelColor(0, strip.Color(2, 0, 2, 2) );
  strip.show();
}


/********************************************************
  Visual tracking stimulus - right
********************************************************/
void rightStimulus() {
  strip.setPixelColor(7, strip.Color(2, 0, 2, 2) );
  strip.show();
}
