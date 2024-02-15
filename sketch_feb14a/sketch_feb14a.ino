#include <Servo.h>

const byte MICPIN = 8;
const byte SERVOPIN = 10;
const byte LEDPIN = 5;
const byte BTNPIN = 4;

Servo boxServo;

void setup() {
  pinMode(MICPIN, INPUT);
  pinMode(SERVOPIN, OUTPUT);
  boxServo.attach(SERVOPIN);
}

void loop() {
  if (analogRead(MICPIN) >= 250) {
    digitalWrite(LEDPIN, HIGH);
    boxServo.write(90);
  }
  if (analogRead(BTNPIN) == HIGH) {
    boxServo.write(0);
    digitalWrite(LEDPIN, LOW);
  }
}
