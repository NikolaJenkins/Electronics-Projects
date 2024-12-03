#include <Servo.h>

Servo yaw;
Servo pitch;
int trigPin = 11;
int echoPin = 10;
int VRX_PIN = A0;
int VRY_PIN = A1;
int buzzerPin = 8;
//include capacitors

int xValue = 0;
int yValue = 0;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  yaw.attach(5);
  pitch.attach(6);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  // digitalWrite(buzzerPin, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
  // if (distance <= 10) {
  //   digitalWrite(buzzerPin, HIGH);
  // } else {
  //   digitalWrite(buzzerPin, LOW);
  // }

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  xValue = map(xValue, 0, 1023, 0, 180);
  yValue = map(yValue, 0, 1023, 0, 180);
  // Serial.print("x value : ");
  // Serial.println(xValue);
  // Serial.print("y value : ");
  // Serial.println(yValue);

  if (xValue < 80 || xValue > 100) {
    yaw.write(xValue);
    delay(15);
  }

  if (yValue < 80 || yValue > 100) {
    pitch.write(yValue);
    delay(15);
  }
}
