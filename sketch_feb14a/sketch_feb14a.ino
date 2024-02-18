#include <Servo.h>

const byte MICPIN = 8;
const byte SERVOPIN = 10;
const byte LEDPIN = 5;
const byte BTNPIN = 4;
const byte LOUDENOUGH = 512;
const byte BOXOPEN = 90;
const byte BOXCLOSE = 0;

Servo boxServo;

void setup() {
  pinMode(MICPIN, INPUT);
  pinMode(SERVOPIN, OUTPUT);
  boxServo.attach(SERVOPIN);
}

void loop() {
  if (analogRead(MICPIN) >= LOUDENOUGH) {
    digitalWrite(LEDPIN, HIGH);
    boxServo.write(BOXOPEN);
    delay(100000);
    boxServo.write(BOXCLOSE);
    digitalWrite(LEDPIN, LOW);
  }
  if (analogRead(BTNPIN) == HIGH) {
    boxServo.write(BOXCLOSE);
    digitalWrite(LEDPIN, LOW);
  }
}
