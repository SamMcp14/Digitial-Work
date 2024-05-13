#include <Wire.h>
#include "SparkFun_Qwiic_OpenLog_Arduino_Library.h"
OpenLog sdCard;  //Create instance
const String FILENAME = "Joke.txt";

void setup() {
  Wire.begin();
  sdCard.begin();
  Serial.begin(9600);

  sdCard.append(FILENAME);
  sdCard.println("knock knock joke");
  sdCard.syncFile();
}

void loop() {
  sdCard.println("Knock Knock");
  Serial.println("Knock Knock");
  delay(2000);

  sdCard.println("Whos there");
  Serial.println("Whos there");
  delay(2000);

  sdCard.println("UR MOM");
  Serial.println("Ur MOM");
  delay(2000);

  sdCard.println("womp womp");
  Serial.println("womp womp");

  sdCard.println("               ");
  Serial.println("               ");

  sdCard.syncFile();
  delay(10000);
}
