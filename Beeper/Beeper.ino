#define interval 500
#define LED 1
unsigned int countdown = 0;
boolean current_state = false;
boolean first = true;
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

  pinMode(0, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(2, INPUT_PULLUP);

}

// the loop routine runs over and over again forever:
void loop() {
  if (first){
    first = false;
    current_state = digitalRead(2);
    digitalWrite(LED, LOW); // inital beep
    digitalWrite(0, LOW);
  }
  if (current_state != digitalRead(2)) {  // if there is change in connectivity from ground and pin 2
    current_state = digitalRead(2);
    countdown = interval;  //set up the timer that the beep is going to go off
  }
  if(countdown > 0) {
    countdown--;
    digitalWrite(LED, HIGH);    // Beep if there is time left for the beep sound
     digitalWrite(0, HIGH);
  }
  if (countdown <= 0){
    countdown = 0;
    digitalWrite(LED, LOW);     // otherwise, turn off beep
     digitalWrite(0, LOW);
  }
  delay(1); // run every ms// fastest touch is 2 ms on foil, this will catch all touches
}
