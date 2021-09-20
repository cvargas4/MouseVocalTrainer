void SerialOut() {
  DateTime now = rtc.now();

  /********************************************************
     Print to Serial monitor
   ********************************************************/
  Serial.println("*** Operant FED ***");
  Serial.print ("RTC set to: ");
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  Serial.print(" (");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  Serial.print("LeftCount: ");
  Serial.println(LeftCount);
  Serial.print("RightCount: ");
  Serial.println(RightCount);
  Serial.print("PelletCount: ");
  Serial.println(PelletCount);
//  Serial.print("VocalCount: ");
//  Serial.println(VocalCount);
  Serial.print("numMotorTurns: ");
  Serial.println(numMotorTurns);
  Serial.print("numJamClears: ");
  Serial.println(numJamClears);
  Serial.print("Ratio_Met: ");
  Serial.println(Ratio_Met);
  Serial.println();
  Serial.println();
  Serial.println();
}
