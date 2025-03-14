int solenoidPin = 7;
const int buttonPin = 4;

int buttonState = 0;
boolean pushed = false;

void setup() {
  pinMode(solenoidPin,OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && !pushed) {
    digitalWrite(solenoidPin, HIGH);
    delay(100);
    digitalWrite(solenoidPin, LOW);
    delay(100);
    pushed = true;
  } else if (buttonState == LOW) {
    pushed = false;
  }
}
