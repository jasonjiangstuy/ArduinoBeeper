#define interval 500;
unsigned int countdown = 0;


// the setup routine runs once when you press reset:
void setup() {

  // signaler
  pinMode(0, OUTPUT);
  // touch reciever
  pinMode(1, INPUT_PULLUP);
  // steal
  pinMode(2, INPUT_PULLUP);

}
 
// the loop routine runs over and over again forever:
void loop() {
  if (!digitalRead(1)) {  // if there is connectivity from ground to pin 0
    countdown = interval;  //set up the timer that the beep is going to go off
   
  } 
  if(countdown > 0) {
    countdown--;
    // digitalWrite(LED, HIGH);    // light up the LED
    analogWrite(0, 255); //255
  } 
  if (countdown <= 0){
    countdown = 0;
    // digitalWrite(LED, LOW);     // otherwise, turn it off
    analogWrite(0, 0);
  }
  delay(1); // run every ms// fastest touch is 2 ms on foil, this will catch all touches
}
