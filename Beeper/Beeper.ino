#define ZERO 0
#define LED 1
#define SOUND 2
#define interval 500;
unsigned int countdown = 0;


// the setup routine runs once when you press reset:
void setup() {

  // initialize the LED pin as an output.
  pinMode(LED, OUTPUT);
  // initialize the 2th pin as an input with resister
  pinMode(ZERO, INPUT_PULLUP);
  // initialize the SOUND pin as an output.
  pinMode(SOUND, OUTPUT);

}
 
// the loop routine runs over and over again forever:
void loop() {
  if (!digitalRead(ZERO)) {  // if there is connectivity from ground to pin 0
    countdown = interval;  //set up the timer that the beep is going to go off
   
  } 
  if(countdown > 0) {
    countdown--;
    digitalWrite(LED, HIGH);    // light up the LED
    analogWrite(SOUND, 130); //255
  } 
  if (countdown <= 0){
    countdown = 0;
    digitalWrite(LED, LOW);     // otherwise, turn it off
    analogWrite(SOUND, 0);
  }
  delay(1); // run every ms// fastest touch is 2 ms on foil, this will catch all touches
}
