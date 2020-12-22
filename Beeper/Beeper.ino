
 
#define SWITCH 0
#define LED 1
#define SOUND 2

 long previousMillis = 0;
 long interval = 500;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the LED pin as an output.
  pinMode(LED, OUTPUT);
  // initialize the SWITCH pin as an input with resister
  pinMode(SWITCH, INPUT);//_PULLUP);
  // initialize the SOUND pin as an output.
  pinMode(SOUND, OUTPUT);

}
 
// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = millis();
  if (digitalRead(SWITCH)) {  // if there is connectivity from 3v to pin 0
    previousMillis = currentMillis;  //set up the timer that the beep is going to go off
    
  } 
  if(currentMillis - previousMillis < interval) {
    digitalWrite(LED, HIGH);    // light up the LED
    analogWrite(SOUND, 255); 
  }
  else {
    digitalWrite(LED, LOW);     // otherwise, turn it off
    analogWrite(SOUND, 0);
  }
  delay(1); // run every ms// fastest touch is 2 ms on foil, this will catch all touches
}
