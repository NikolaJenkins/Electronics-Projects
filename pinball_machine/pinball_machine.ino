#define solenoid1 9
#define solenoid2 10
#define button1 0
#define button2 1 
#define buttonState1 0
#define buttonState2 0

void setup() {
  // put your setup code here, to run once:
  pinMode(solenoid1, OUTPUT);
  pinMode(solenoid2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonState1);
  buttonState2 = digitalRead(buttonState2);
  if (buttonState1 == HIGH) {
    digitalWrite(solenoid1, HIGH);
    delay(1000);
    digitalWrite(solenoid1, LOW);
    delay(1000);
  }

  if (buttonState2 == HIGH) {
    digitalWrite(solenoid2, HIGH);
    delay(1000);
    digitalWrite(solenoid2, LOW);
    delay(1000);
  }
}
