int sensorPin = 5;
int pirState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  pirState = digitalRead(sensorPin);
  if (pirState == HIGH) {
    Serial.println("motion detected");
  } else {
    Serial.println("no motion detected");
  }
}
