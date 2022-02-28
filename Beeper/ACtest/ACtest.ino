#define ControlACPin 2
int state = 0; 

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
  // signaler / LED
  pinMode(ControlACPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
//  state += 1;

  if (state >= 1){
    state = 0;
    digitalWrite(ControlACPin, HIGH);
    
  }else{
    state = 1;
    digitalWrite(ControlACPin, LOW);
  }
//   if (state > 20){
//    state = 0;
//  }
}
