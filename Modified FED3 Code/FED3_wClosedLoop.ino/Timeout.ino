void Timeout () {
  if (TimeoutReady == true && PelletAvailable == true) {
    for (int k = 0; k <= timeout; k++) {
      delay (1000);
      display.fillRoundRect (5, 20, 100, 25, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
      display.setCursor(6, 36);
      display.print("Timeout: ");
      display.print(timeout - k);
      display.refresh();

      Serial.println();
      Serial.println ("Timeout:");
      Serial.print(timeout - k);
      Serial.print(" sec");
      Serial.println();
    }
    TimeoutReady = false;
    display.fillRoundRect (5, 20, 100, 25, 1, WHITE);  //erase the data on screen without clearing the entire screen by pasting a white box over it
    UpdateDisplay();
  }
}
