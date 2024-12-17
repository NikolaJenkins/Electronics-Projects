int solenoidPin = 2;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(solenoidPin,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(solenoidPin,HIGH);
  delay(1000);
  digitalWrite(solenoidPin,LOW);
  delay(1000);
  // if (buttonState1 == HIGH) {
  //   Serial.println("push ball1");
  //   push1.write(0);
  //   delay(10);
  //   push1.write(180);
  //   delay(10);
  //   buttonState1 == LOW;
  // }

  // if (buttonState2 == HIGH) {
  //   Serial.println("push ball2");
  //   push2.write(180);
  //   delay(10);
  //   push2.write(0);
  //   delay(10);
  //   buttonState2 == LOW;
  // }

}
