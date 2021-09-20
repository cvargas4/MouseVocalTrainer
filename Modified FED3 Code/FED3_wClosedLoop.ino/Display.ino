/********************************************************
  Update Nosepoke and Pellet Count data
********************************************************/
void UpdateDisplay() {
  //colorWipe(strip.Color(0, 0, 0), 5); // OFF

  display.setRotation(3);
  display.setTextColor(BLACK);
  display.setTextSize(1);

  display.setCursor(5, 15);
  display.print("FED:");
  display.println(FED);
  display.setCursor(6, 15);  // this doubling is a way to do bold type
  display.print("FED:");
  display.setTextSize(1);
  display.fillRoundRect (6, 20, 200, 22, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it

  if (FEDmode == 0) {
    display.fillRoundRect (35, 24, 200, 50, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.setCursor(22, 64);
    display.print("Free Feeding");
  }

  if (FEDmode == 11) {
    display.fillRoundRect (35, 24, 200, 50, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.setCursor(22, 64);
    display.println("Timed Feeding");
    display.setCursor(22, 80);
    display.print(timedStart);
    display.print(" to ");
    display.print(timedEnd);    
  }

  if (FEDmode < 4 & FEDmode != 0 & FEDmode != 11) {
    display.setCursor(5, 36);
    display.print("FR: ");
    display.setCursor(6, 36);
    display.print("FR: ");
    display.print(FR);
  }

  if (FEDmode == 4 & LeftCount == 0) { //Prog ratio, first poke
    display.setCursor(5, 36);
    display.print("PR: ");
    display.setCursor(6, 36);
    display.print("PR: ");
    display.fillRoundRect (35, 24, 200, 55, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.print(1);
  }

  if (FEDmode == 4 & LeftCount != 0) { // Prog ratio, NOT first poke
    display.setCursor(5, 36);
    display.print("PR: ");
    display.setCursor(6, 36);
    display.print("PR: ");
    display.fillRoundRect (35, 24, 200, 55, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.print(ratio - LeftCount);
  }

  if (FEDmode == 5) {
    display.setCursor(5, 36);
    display.print("Extinction");
  }

  if (FEDmode == 6) {
    display.setCursor(5, 36);
    display.print("Light tracking");
  }

  if (FEDmode == 7) {
    display.setCursor(5, 36);
    display.print("FR1 (reversed)");
  }

  if (FEDmode == 8 & RightCount == 0) { //Prog ratio, first poke
    display.setCursor(5, 36);
    display.print("PR(R): ");
    display.setCursor(6, 36);
    display.print("PR(R): ");
    display.fillRoundRect (55, 24, 200, 55, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.print(1);
  }

  if (FEDmode == 8 & RightCount != 0) { // Prog ratio, NOT first poke
    display.setCursor(5, 36);
    display.print("PR(R): ");
    display.setCursor(6, 36);
    display.print("PR(R): ");
    display.fillRoundRect (55, 24, 200, 55, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.print(ratio - RightCount);
  }

  if (FEDmode == 9) {
    display.setCursor(5, 36);
    display.print("Stim");
  }

  if (FEDmode == 10) {
    display.setCursor(5, 36);
    display.print("Stim (R)");
  }

  if (FEDmode != 11 & FEDmode != 0  & FEDmode != 12) { // don't erase this if it's a free or timed feeding session
    display.fillRoundRect (35, 42, 130, 80, 1, WHITE);  //erase the pellet data on screen without clearing the entire screen by pasting a white box over it
  }
  display.fillRoundRect (93, 90, 60, 20, 1, WHITE);  //erase the pellet data on screen without clearing the entire screen by pasting a white box over it

  if (FEDmode > 0 & FEDmode != 11 & FEDmode != 12) {
    display.setCursor(35, 65);
    display.setTextSize(1);
    display.print("Left: ");
    display.setCursor(95, 65);
    display.print(LeftCount);

    display.setCursor(35, 85);
    display.setTextSize(1);
    display.print("Right:  ");
    display.setCursor(95, 85);
    display.print(RightCount);
  }

  if (FEDmode != 5 && FEDmode != 9 && FEDmode != 10 && FEDmode != 12) {  //don't show pellets if extinction or opto session
    display.setCursor(35, 105);
    display.setTextSize(1);
    display.print("Pellets:");
    display.setCursor(95, 105);
    display.print(PelletCount);
    //    display.print("  ");
    //    display.print(rewardedTrial);

  }
    if (FEDmode == 12) {
    display.fillRoundRect (35, 24, 200, 50, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    display.setCursor(22, 64);
    display.print("Closed--loop");
    display.setCursor(22, 64);
    display.print("");
    display.setCursor(30, 85);
    display.setTextSize(1);
    display.print("Trigger: ");
    if(digitalRead(BNC_OUT) == HIGH){
      display.fillRoundRect(95, 70, 100, 20, 1, WHITE);
      display.setCursor(95, 85);
      display.print("Input");
    }
    else{
      display.fillRoundRect(95, 70, 100, 20, 1, WHITE);
      display.setCursor(95, 85);
      display.print("Waiting");
    }
    display.setCursor(35, 105);
    display.setTextSize(1);
    display.print("Pellets:");
    display.setCursor(95, 105);
    display.print(PelletCount);
    //if(PelletCount >= pelletMax){
      //  display.setCursor(6, 36);
        //display.print("Pellet Max Reached");
    //}
    if (PelletAvailable) {
        display.fillCircle(25, 99, 5, BLACK);
        display.drawCircle(25, 99, 5, BLACK);
      }
    else{
        display.fillCircle(25, 99, 5, WHITE);
        display.drawCircle(25, 99, 5, BLACK);
    }
  }
  /********************************************************
    Battery graphic showing bars indicating voltage levels
  ********************************************************/
  display.drawRoundRect (116, 1, 42, 18, 3, BLACK);
  display.drawRoundRect (157, 6, 6, 8, 2, BLACK);

  if (measuredvbat > 3.85 & numMotorTurns == 0) {
    display.fillRoundRect (120, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (129, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (138, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (147, 4, 7, 12, 1, BLACK);
  }
  else if (measuredvbat > 3.7 & numMotorTurns == 0) {
    display.fillRoundRect (119, 3, 26, 13, 1, WHITE);
    display.fillRoundRect (120, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (129, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (138, 4, 7, 12, 1, BLACK);
  }
  else if (measuredvbat > 3.55 & numMotorTurns == 0) {
    display.fillRoundRect (119, 3, 26, 13, 1, WHITE);
    display.fillRoundRect (120, 4, 7, 12, 1, BLACK);
    display.fillRoundRect (129, 4, 7, 12, 1, BLACK);
  }
  else if (& numMotorTurns == 0) {
    display.fillRoundRect (119, 3, 26, 13, 1, WHITE);
    display.fillRoundRect (120, 4, 7, 12, 1, BLACK);
  }

  /********************************************************
    Box around data area of screen
  ********************************************************/
  display.drawRoundRect (5, 45, 158, 70, 3, BLACK);

  /********************************************************
    Print date and time at bottom of the screen
  ********************************************************/
  DateTime now = rtc.now();
  display.setCursor(10, 135);
  display.fillRoundRect (0, 123, 200, 60, 1, WHITE);
  display.print(now.month());
  display.print("/");
  display.print(now.day());
  display.print("/");
  display.print(now.year());
  display.print("    ");
  if (now.hour() < 10)
    display.print('0');      // Trick to add leading zero for formatting
  display.print(now.hour());
  display.print(":");
  if (now.minute() < 10)
    display.print('0');      // Trick to add leading zero for formatting
  display.print(now.minute());

  /********************************************************
     Poke and pellet indicator graphics
   ********************************************************/
    if (FEDmode > 0 & FEDmode < 11) {
      //poke indicators
      if (digitalRead(RIGHT_POKE) == HIGH) {
        display.fillCircle(25, 79, 5, WHITE);
        display.drawCircle(25, 79, 5, BLACK);
      }
  
      if (digitalRead(LEFT_POKE) == HIGH) {
        display.fillCircle(25, 59, 5, WHITE);
        display.drawCircle(25, 59, 5, BLACK);
      }
  
      //indicate which poke is active with a filled triangle beside it
      if (FEDmode == 7 || FEDmode == 8 || FEDmode == 10) {
        activePoke = 0;
      }
  
      if (activePoke == 0 && Ratio_Met == false) {
        display.fillTriangle (12, 55, 18, 59, 12, 63, WHITE);
        display.fillTriangle (12, 75, 18, 79, 12, 83, BLACK);
      }
  
      if (activePoke == 1 && Ratio_Met == false) {
        display.fillTriangle (12, 75, 18, 79, 12, 83, WHITE);
        display.fillTriangle (12, 55, 18, 59, 12, 63, BLACK);
      }
    }
   

  if (FEDmode != 5 && FEDmode != 9 && FEDmode != 10 && FEDmode != 12) { //no need to show pellets if extinction or opto stim sessions
    if (digitalRead(PELLET_WELL) == HIGH) {
      display.fillCircle(25, 99, 5, WHITE);
      display.drawCircle(25, 99, 5, BLACK);
    }

    if (digitalRead(PELLET_WELL) == LOW) {
      display.fillCircle(25, 99, 5, BLACK);
    }
  }
  
  display.refresh();
}

/********************************************************
  Display SD Card error
********************************************************/
void DisplaySDError() {
  display.clearDisplay();
  display.setRotation(3);
  display.setTextColor(BLACK);
  display.setCursor(20, 40);
  display.setTextSize(2);
  display.println("   Check");
  display.setCursor(10, 60);
  display.println("  SD Card!");
  display.refresh();
}

/********************************************************
  Display logging data
********************************************************/
void DisplaySDLogging() {
  display.fillRoundRect (6, 20, 200, 22, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
  display.setCursor(6, 36);
  display.print("Writing data");
  display.refresh();
}

/********************************************************
  Display jam clear
********************************************************/
void DisplayJamClear() {
  display.fillRoundRect (6, 20, 200, 22, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
  display.setCursor(6, 36);
  display.print("Clearing jam");
  display.refresh();
}

/********************************************************
  Display Dispensing Pellet
********************************************************/
void DisplayDispense() {
  display.fillRoundRect (6, 20, 200, 22, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
  display.setCursor(6, 36);
  display.print("Dispensing ");
  display.print(numMotorTurns);
  display.refresh();
}

/********************************************************
  Display Sleep
********************************************************/
void DisplaySleep() {
  display.fillRoundRect (6, 20, 200, 22, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
  display.setCursor(6, 36);
  display.print("Standby");
  display.refresh();
}

/********************************************************
  Display Retrieval Intervat
********************************************************/
void DisplayRetrievalInt() {
  display.setCursor(120, 105);
  display.print (retInterval);
  display.print("s");
  display.refresh();
}
/********************************************************
  Startup Animation
********************************************************/
//  0 Free feeding
//  1 FR1
//  2 FR3
//  3 FR5
//  4 Progressive Ratio
//  5 Extinction
//  6 Light tracking FR1 task
//  7 FR1 (reversed)
//  8 PR (reversed)
//  9 self-stim
//  10 self-stim (reversed)
//  11 time feeding
//  12 Closed--loop

void StartUpDisplay () {
  // Set FR based on FEDmode
  if (FEDmode == 0) FR = 0;  // free feeding
  if (FEDmode == 1) FR = 1;  // FR1 spatial tracking task
  if (FEDmode == 2) FR = 3;  // FR3
  if (FEDmode == 3) FR = 5; // FR5
  if (FEDmode == 4) FR = 99;  // Progressive Ratio
  if (FEDmode == 5) { // Extinction
    FR = 1;
    ReleaseMotor ();
    digitalWrite (MOTOR_ENABLE, LOW);  //Disable motor driver
  }
  if (FEDmode == 6) FR = 1;  // Light tracking
  if (FEDmode == 7) FR = 1; // FR1 (reversed)
  if (FEDmode == 8) FR = 1; // PR (reversed)
  if (FEDmode == 9) FR = 1; // self-stim
  if (FEDmode == 10) FR = 1; // self-stim (reversed)
  if (FEDmode == 12) FR = 0; //Closed--loop "free feeding"

  display.setFont(&FreeSans9pt7b);
  display.setRotation(3);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.clearDisplay();

  display.setCursor(1, 135);
  display.print (filename);

  display.setFont(&FreeSans9pt7b);
  display.setCursor(5, 20);
  display.println ("Select Program");
  display.fillRoundRect (0, 30, 160, 80, 1, WHITE);
  display.setCursor(10, 45);
  //Text to display selected FR ratio
  if (FEDmode == 0) display.print("Free feeding");
  if (FEDmode == 11) display.print("Timed feeding");
  if (FEDmode == 12) display.print("Closed--loop");
  if (FEDmode == 1 ||  FEDmode == 2 || FEDmode == 3) {
    display.print("Fixed Ratio:"); display.print(FR);
  }
  if (FEDmode == 4) display.print("Progressive Ratio");
  if (FEDmode == 5) display.print("Extinction");
  if (FEDmode == 6) display.print("Light tracking");
  if (FEDmode == 7) display.print("FR1");
  if (FEDmode == 8) display.print("Progressive Ratio");
  if (FEDmode == 9) display.print("Self-Stimulation");
  if (FEDmode == 10) display.print("Self-Stimulation");
  if (FEDmode == 8 || FEDmode == 7 || FEDmode == 10) display.setCursor(10, 65);
  if (FEDmode == 8 || FEDmode == 7 || FEDmode == 10) display.print("(reversed)");

  for (int i = -50; i < 200; i += 15) {
    display.setCursor(0, 40);
    //Draw animated mouse...
    display.fillRoundRect (i + 25, 77, 15, 10, 6, BLACK);  //head
    display.fillRoundRect (i + 22, 75, 8, 5, 3, BLACK);    //ear
    display.fillRoundRect (i + 30, 79, 1, 1, 1, WHITE);    //eye

    //movement of the mouse
    if ((i / 10) % 2 == 0) {
      display.fillRoundRect (i, 79, 32, 17, 10, BLACK);      //body
      display.drawFastHLine(i - 8, 80, 18, BLACK);        //tail
      display.drawFastHLine(i - 8, 81, 18, BLACK);
      display.drawFastHLine(i - 14, 79, 8, BLACK);
      display.drawFastHLine(i - 14, 80, 8, BLACK);

      display.fillRoundRect (i + 22, 94, 8, 4, 3, BLACK);  //front foot
      display.fillRoundRect (i , 92, 8, 6, 3, BLACK); //back foot
    }
    else {
      display.fillRoundRect (i + 2, 77, 30, 17, 10, BLACK);    //body
      display.drawFastHLine(i - 6, 86, 18, BLACK);        //tail
      display.drawFastHLine(i - 6, 85, 18, BLACK);
      display.drawFastHLine(i - 12, 87, 8, BLACK);
      display.drawFastHLine(i - 12, 86, 8, BLACK);

      display.fillRoundRect (i + 15, 94, 8, 4, 3, BLACK);  //foot
      display.fillRoundRect (i + 8, 92, 8, 6, 3, BLACK); //back foot
    }
    delay (80);
    display.refresh();
    display.fillRoundRect (i - 25, 75, 90, 35, 1, WHITE);
    previousFEDmode = FEDmode;
    previousFED = FED;
    if (digitalRead (LEFT_POKE) == LOW | digitalRead (RIGHT_POKE) == LOW) SelectMode();
  }
  //ReadBatteryLevel();
  display.clearDisplay();
  display.refresh();
}
