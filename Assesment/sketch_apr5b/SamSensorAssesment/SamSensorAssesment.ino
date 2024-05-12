#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

//TEACHER COMMENT what is this being created for?
long myTime;
int myLed = 13;

//TEACHER COMMENT so what are these?
LPS25HB Sensor;
OpenLog resultStorage;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  resultStorage.begin();
  Sensor.begin();
  pinMode(myLed, OUTPUT);

  //TEACHER COMMENT what is this checking?
  if (Sensor.isConnected() == false) {
    Serial.println("SENSORBOARD HAS FAILED TO CONNECT");

    while (1);
  }

  //TEACHER COMMENT should you also check the sdcard/resultStorage?

  resultStorage.append("resultStorage.txt");
resultStorage.print("Time,Pressure,Temprature");

  resultStorage.syncFile();

  Serial.println("Done!");

Serial.print("Time,Pressure,Temperature");
}

//TEACHER COMMENT add a comment explaining what this is doing
void loop() {
  myTime = millis();
  Serial.print(myTime); // prints time since program 
  resultStorage.print(myTime);
  Serial.print(",");
  resultStorage.print(",");
  Serial.print(Sensor.getPressure_hPa());
  resultStorage.print(Sensor.getPressure_hPa());
  Serial.print(",");
  resultStorage.print(",");
  Serial.println(Sensor.getTemperature_degC());
  resultStorage.println(Sensor.getTemperature_degC());

  resultStorage.syncFile();
if (Sensor.getPressure_hPa() >= 0) {
    digitalWrite(myLed, HIGH);
    delay(10);
    digitalWrite(myLed, LOW);
}
else{
  Serial.print("Pressure sensor not recording proper data");
}
if (Sensor.getTemperature_degC() >= 0) {
    digitalWrite(myLed, HIGH);
    delay(10);
    digitalWrite(myLed, LOW);
}
else{
  Serial.print("Temprature sensor not recording proper data");
}
  delay(1000);
}
