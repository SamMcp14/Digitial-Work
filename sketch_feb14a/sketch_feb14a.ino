#include <Servo.h>

const byte MICPIN = 8;
const byte SERVOPIN = 10;
const byte LEDPIN = 5;

Servo boxServo;
void setup() {
pinMode(MICPIN, INPUT)
pinMode(SERVOPIN, OUTPUT)
lock.attach(SERVOPIN);
}

void loop() {
if analogRead(MICPIN) <= 250) [
digitalWrite(LEDPIN, HIGH)

]
}

