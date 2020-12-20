
 
#define SWITCH 0
#define LED 1
#define SOUND 2
// the setup routine runs once when you press reset:
void setup() {
  // initialize the LED pin as an output.
  pinMode(LED, OUTPUT);
  // initialize the SWITCH pin as an input with resister
  pinMode(SWITCH, INPUT_PULLUP);
  // initialize the SOUND pin as an output.
  pinMode(SOUND, OUTPUT);


}
 
// the loop routine runs over and over again forever:
void loop() {
  if (!digitalRead(SWITCH)) {  // if there is connectivity from 3v to pin 0
    digitalWrite(LED, HIGH);    // light up the LED
    analogWrite(SOUND, 255); 
  } else {
    digitalWrite(LED, LOW);     // otherwise, turn it off
    analogWrite(SOUND, 0);
  }
}
