#include <Servo.h>

Servo push1;
Servo push2;

int button1 = 2;
int button2 = 4;
int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  // put your setup code here, to run once:
  push1.attach(5);
  push2.attach(6);
  push1.write(0);
  push2.write(0);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  if (buttonState1 == HIGH) {
    Serial.println("push ball");
    push1.write(180);
    delay(10);
    push1.write(0);
    delay(10);
    buttonState1 == LOW;
  }

  if (buttonState2 == HIGH) {
    Serial.println("push ball");
    push2.write(180);
    delay(10);
    push2.write(0);
    delay(10);
    buttonState2 == LOW;
  }

  // if (buttonState2 == HIGH) {
  //   digitalWrite(solenoid2, HIGH);
  //   delay(1000);
  //   digitalWrite(solenoid2, LOW);
  //   delay(1000);
  // }
}
