/********************************************************
  Check if food is available.  If so return TRUE.  1 second de-bounce on this function.
********************************************************/
bool CheckForPellet () {
  if (FEDmode != 5) {  // if not an extinction session
    if (FEDmode == 6 && Ratio_Met == false && PelletAvailable == false) {  // if light tracking session, display light tracking stimulus
      if (activePoke == 1) leftStimulus() ;
      if (activePoke == 0) rightStimulus() ;
    }

    if (digitalRead(PELLET_WELL) == HIGH && OutReady == true) {
      //delay (300);
      if (digitalRead(PELLET_WELL) == HIGH ) {  //if pellet is out for 300ms

        //Blink(BNC_OUT, 200, 1);
        OutReady = false;
        DateTime now = rtc.now();
        retInterval = (now.hour() * 3600) + (now.minute() * 60) + now.second() - pelletTime;

        if (PelletCount > 0) {  // This skips logging for the first trial if the FED starts with a pellet in the well
          DisplayRetrievalInt();
          logdata();
          retInterval = 0;  // reset retrieval interval after logging
        }

        //Timeout();

        /********************************************************
          Light tracking task
        ********************************************************/
        if (FEDmode == 6) activePoke = random (0, 2); // randomize Active poke in light tracking task

        UpdateDisplay();
       // colorWipe(strip.Color(0, 0, 0), 10); // OFF
      }
    }

    //ReadBatteryLevel();
    UpdateDisplay();
    PelletAvailable = false;

    if (digitalRead(PELLET_WELL) == LOW ) {
      //delay (100);
      if (digitalRead(PELLET_WELL) == LOW ) {
        DateTime now = rtc.now();
        pelletTime = (now.hour() * 3600) + (now.minute() * 60) + now.second();
        PelletAvailable = true;
        PelletJam = false;
        if (CountReady == true) {
          PelletCount++;
          CountReady = false;
          OutReady = true;
          TimeoutReady = true;
          Ratio_Met = false;
          trialCount ++;  // on Compulsivity trials increment this variable to keep track of trials between Idle and Active states

          /********************************************************
            Progressive Ratio
          ********************************************************/
          ratio = ratio + round ((5 * exp (0.2 * PelletCount)) - 5); // this is a formula from Richardson and Roberts (1996) https://www.ncbi.nlm.nih.gov/pubmed/8794935
        }
      }
    }
  }

  else {  // if it is an extinction session, trick FED into thinking a pellet was dispensed
    PelletAvailable = true;
    OutReady = true;
    TimeoutReady = true;
    Ratio_Met = false;
    UpdateDisplay();
  }
}
