#define interval 500;
unsigned int countdown = 0;

// LED: pin 1: output: lights up when you get a valid touch, this signal gets
// transmitted to the transistor which opens current vout to buzzer
//
// STEAL: pin 2: output small current: connected to guard: Used to redirect flow from the opposing
// this turns the input pu to registor as high while open (as it connects to own guard) and when circut is made with opponents' guard
//
//recieve: pin 0: INPUT_PULLUP: connects to internal wire: normally in high state as it interacts with voltage, when grounded
// it signmals a touches

// ground: connected to internal wire: connects with receieve when epee touches


// the setup routine runs once when you press reset:
void setup() {
  // touch reciever
  // maybe just input (that way the steal from the other microcontroller will block touch)
  pinMode(0, INPUT_PULLUP);

  // signaler / LED
  pinMode(1, OUTPUT);

  // steal // no touch for you!!
  pinMode(2, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  if (!digitalRead(1)) {  // if there is connectivity from ground to pin 0
    countdown = interval;  //set up the timer that the beep is going to go off
  }
  if(countdown > 0) {
    countdown--;
    digitalWrite(LED, HIGH);    // light up the LED
    analogWrite(0, 255); //255
  }
  if (countdown <= 0){
    countdown = 0;
    // digitalWrite(LED, LOW);     // otherwise, turn it off
    analogWrite(0, 0);
  }
  delay(1); // run every ms// fastest touch is 2 ms on foil, this will catch all touches
}
