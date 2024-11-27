#include <Servo.h>

Servo yaw;
Servo pitch;
#define trigPin 11;
#define echoPin 10;
#define VRX_PIN A0;
#define VRY_PIN A1;
#define buzzerPin 8;

int xValue = 0;
int yValue = 0;

float duration, distance;

void setup() {
  // put your setup code here, to run once:
  yaw.attach(5);
  pitch.attach(6);
  pinMode(trigPin, INPUT);
  pinMode(echoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  tone(buzzerPin, 1000, 2000);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  xValue = map(xValue, 0, 1023, 0, 180);
  yValue = map(yValue, 0, 1023, 0, 180);

  if (!(xValue < 80 || xValue > 100)) {
    yaw.attach(xValue);
    delay(15);
  }

  if (!(yValue < 80 || yValue > 100)) {
    pitch.attach(yValue);
    delay(15);
  }

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  if (distance <= 5) {
    tone(buzzerPin, 440);
  }
}
