void optoStim(){
//  Blink(BNC_OUT, 25, 20);  // Set stimulation parameters, PIN/Pulse_Length/Pulse_number
    Feed();
    CheckForPellet();
    logdata();
    digitalWrite(BNC_OUT,LOW);
    UpdateDisplay();
}
