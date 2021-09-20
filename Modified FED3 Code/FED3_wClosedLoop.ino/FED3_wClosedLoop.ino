       /********************************************************
  FED3
  Written by Lex Kravitz
  National Institute of Diabetes and Digestive and Kidney Disease
  April 2019

  FED is a Feeding Experimentation Device.  It is a smart pellet dispenser
  that logs the timestamp whenever a pellet is removed. These timestamps
  can be used to recreate feeding records over multiple days. FED3 also includes 
  operant pokes and stimuli for training mice to obtain pellets.

  FED was originally developed by Nguyen at al and published in 2016:
  https://www.ncbi.nlm.nih.gov/pubmed/27060385

  This code includes code from:
  *** Adafruit, who made the hardware breakout boards and associated code we used in FED ***

  Cavemoa's excellent examples of datalogging with the Adalogger:
  https://github.com/cavemoa/Feather-M0-Adalogger

  Uses Arduino Time library http://playground.arduino.cc/code/time
  Maintained by Paul Stoffregen https://github.com/PaulStoffregen/Time

  Arduino Zero RTC library https://www.arduino.cc/en/Reference/RTC
  Maintained by Arturo Guadalupi https://github.com/arduino-libraries/RTCZero

  This project is released under the terms of the Creative Commons - Attribution - ShareAlike 3.0 license:
  human readable: https://creativecommons.org/licenses/by-sa/3.0/
  legal wording: https://creativecommons.org/licenses/by-sa/3.0/legalcode
  Copyright (c) 2019 Lex Kravitz

********************************************************/

/********************************************************
  Setup code
********************************************************/
#include "a_header.h" //See "a_Header.h" for #defines and other constants 

void setup() {
  StartUpCommands();
}

/********************************************************
  Main loop
********************************************************/
void loop() {
  if (FEDmode == 12){
//      if (digitalRead(BNC_IN) == HIGH){
//        UpdateDisplay();
//      }
//      if (digitalRead(BNC_IN) == LOW){
//        UpdateDisplay();
//      }
      UpdateDisplay();
      CheckForPellet();
//      CheckPokes();
//      if (Ratio_Met == true) { 
      if (digitalRead(BNC_OUT)==HIGH){
        if(PelletAvailable == false){
          optoStim();
        }
        else{
        CheckForPellet();
        UpdateDisplay();
        digitalWrite(BNC_IN, LOW);
        }
      }
//     }
  }
  else {
  CheckForPellet();
  if (PelletAvailable && FEDmode != 5) {  // Don't sleep during extinction testing
    sleep();
  }
      else {
    CheckPokes();
    if (Ratio_Met == true) { 
      Feed();
    }
  }
  }
  //SerialOut();  
}
