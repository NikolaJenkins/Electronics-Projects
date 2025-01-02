#include <Servo.h>

Servo yaw;
Servo pitch;
int trigPin = 11;
int echoPin = 10;
int VRX_PIN = A0;
int VRY_PIN = A1;
int buzzerPin = 8;

int xValue = 0;
int yValue = 0;
float duration, distance;

void setup() {
  yaw.attach(5);
  pitch.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
  if (distance <= 10) {
    tone(buzzerPin, 440, 500);
  }

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  xValue = map(xValue, 0, 1023, 0, 180);
  yValue = map(yValue, 0, 1023, 0, 180);

  if (xValue < 80 || xValue > 100) {
    yaw.write(xValue);
    delay(15);
  }

  if (yValue < 80 || yValue > 100) {
    pitch.write(yValue);
    delay(15);
  }
}
