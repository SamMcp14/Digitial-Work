const byte BTNPIN = 1
const byte POTPIN = A1
void setup() {
pinMode(BTNPIN, INPUT);
pinMode(POTPIN, INPUT);

Serial.begin(9600)
}

void loop() {
if (digitalRead(BTNPIN == HIGH) {
  Serial.println("rolling dice! YIPPEE");
  int diceType = analogRead(POTPIN);
diceType = map(diceType, 0, 1023, 1. 6);
rollDice(diceType);
}
}
