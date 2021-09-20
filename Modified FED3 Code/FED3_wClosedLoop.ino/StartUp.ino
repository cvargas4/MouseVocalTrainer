/********************************************************
  Start Up Commands
********************************************************/
void StartUpCommands () {
  Serial.begin(115200);

  /********************************************************
    These commands are associated with the low power sleep states
  ********************************************************/
  SYSCTRL->VREG.bit.RUNSTDBY = 1;
  SYSCTRL->DFLLCTRL.bit.RUNSTDBY = 1;
  USBDevice.detach();  // Detach USB or it will keep waking the FED up from sleep.  Comment this out to use Serial Output.
  for (byte i = 0; i <= 20; i++) {
    pinMode(i, INPUT_PULLDOWN);
  }

  /********************************************************
     Start RTC
   ********************************************************/
  rtc.begin(); // initialize RTC

  /********************************************************
    Setting digital pin modes
  ********************************************************/
  pinMode(PELLET_WELL, INPUT);
  pinMode(LEFT_POKE, INPUT);
  pinMode(RIGHT_POKE, INPUT);
  pinMode (MOTOR_ENABLE, OUTPUT);
  pinMode (GREEN_LED, OUTPUT);
  pinMode (BUZZER, OUTPUT);
  pinMode (A2, OUTPUT);
  pinMode (A3, OUTPUT);
  pinMode (A4, OUTPUT);
  pinMode (A5, OUTPUT);
  pinMode(BNC_OUT, INPUT);
  pinMode(BNC_IN, INPUT);


  /********************************************************
    Attach interrupts to wake from sleep
  ********************************************************/
  attachInterrupt(PELLET_WELL, wake, CHANGE);
  attachInterrupt(LEFT_POKE, wake, CHANGE);
  attachInterrupt(RIGHT_POKE, wake, CHANGE);
  attachInterrupt(BNC_IN, checkInput, RISING);
  digitalWrite(BNC_OUT,LOW);
  /********************************************************
    Start neopixel library
  ********************************************************/
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  /********************************************************
    Set up stepper
  ********************************************************/
  stepper.setSpeed(60);

  /********************************************************
     Start, clear, and setup the Sharp Memory display
   ********************************************************/
  display.begin();
  display.clearDisplay();
  const int minorHalfSize = min(display.width(), display.height()) / 2;

  /********************************************************
    Create Device and Config files
  ********************************************************/
  CreateFile();

  /********************************************************
    Startup Animation
  ********************************************************/
  StartUpDisplay ();

  /********************************************************
    Create Data File for current session
  ********************************************************/
  CreateDataFile();
  writeHeader();
  EndTime = 0;

}
