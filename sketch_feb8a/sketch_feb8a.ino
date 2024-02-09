//shared with Mr Hansen successfully
#include <Servo.h>
const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
const byte LEFTEARPIN = 9;
const byte RIGHTEARPIN = 10;

Servo LeftEar;
Servo RightEar;

void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
  LeftEar.attach(LEFTEARPIN);
  RightEar.attach(RIGHTEARPIN);
}

void loop() {
  if (digitalRead(PAWPIN1) == HIGH) {
    digitalWrite(LEDPIN, HIGH);
  }

  if (digitalRead(PAWPIN2) == HIGH) {
    digitalWrite(LEDPIN, LOW);
  }

  if (digitalRead(PAWPIN3) == HIGH) {
    playMusic();
  }

  if (digitalRead(PAWPIN4) == HIGH) {
    blinkingLED();
  }
}
void playMusic() {
  //play mp3 here
}

int playGame() {
  byte score = 99;
  //play game
  return score;
}


void wagEars() {
  LeftEar.write(0);
  RightEar.write(0);
  LeftEar.write(90);
  RightEar.write(90);
  LeftEar.write(0);
  RightEar.write(0);
}

void blinkingLED() {
  byte randNumber = random(1, 3);

  for (int i = 0; i < randNumber; i++) {
    digitalWrite(LEDPIN, HIGH);
    delay(500);
    digitalWrite(LEDPIN, HIGH);
    delay(500);
  }
}