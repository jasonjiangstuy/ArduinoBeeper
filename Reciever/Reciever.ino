#define reciever 0
#define light 1
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(light, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(reciever);
  analogWrite(light, val/4);
}
