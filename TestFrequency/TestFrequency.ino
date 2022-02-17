#define TestPin 0
#define LED 1

void setup() {
  // put your setup code here, to run once:
  pinMode(TestPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(TestPin)){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
