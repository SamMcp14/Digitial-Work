#include <LiquidCrystal.h>
//HAN COMMENT you are on the right track Sam, I fixed a few issues I could see
const byte BTNPIN = 1
const byte NOIPIN = A0
const byte POTPIN = A1


  Adafruit_LiquidCrystal screen(0);

void setup() {
  pinMode(BTNPIN, INPUT);
  pinMode(POTPIN, INPUT);

  randomSeed(analogRead(NOIPIN));

  Serial.begin(9600)

    if (!screen.begin(16, 2)) {
    Serial.println("check wiring didnt start"); 
    while(1);
  }
}

void loop() {
if (digitalRead(BTNPIN == HIGH) {
    Serial.println("rolling dice! YIPPEE");
    int diceType = analogRead(POTPIN);
    diceType = map(diceType, 0, 1023, 1. 6);
    rollDice(diceType);
  }
}

void rollDice(byte numSides) {
  byte diceRoll = 255;
  switch (numSides) {
    case 1:
    screen.print("roll is: ");
    diceRoll = Random(1, 4);
    break;
        case 2:
    screen.print("roll is: ");
    diceRoll = Random(1, 6);
    break;
        case 3:
    screen.print("roll is: ");
    diceRoll = Random(1, 8);
    break;
        case 4:
    screen.print("roll is: ");
    diceRoll = Random(1, 10);
    break;
        case 5:
    screen.print("roll is: ");
    diceRoll = Random(1, 12);
    break;
        case 6:
    screen.print("roll is: ");
    diceRoll = Random(1, 20);
    break;
    default:
    Serial.println("Issue with mapping potentiometer values");
    break;
  }
  screen.println(diceRoll);
}
