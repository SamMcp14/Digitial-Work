//shared with Mr Hansen successfully 
const byte LEDPIN = 13;
const byte PAWPIN1 = 1;
const byte PAWPIN2 = 2;
const byte PAWPIN3 = 3;
const byte PAWPIN4 = 4;
void setup() {
  pinMode(LEDPIN, OUTPUT);
  pinMode(PAWPIN1, INPUT);
  pinMode(PAWPIN2, INPUT);
  pinMode(PAWPIN3, INPUT);
  pinMode(PAWPIN4, INPUT);
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
  int score = playGame();

}

void playMusic(){
  //play mp3 here
}

int playGame(){
  byte score = 99;
  //play game
  return score;
  }
}
