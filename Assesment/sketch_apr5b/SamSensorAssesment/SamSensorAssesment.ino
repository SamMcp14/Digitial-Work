#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

//TEACHER COMMENT what is this being created for?
long myTime;
const String FILE_NAME ="ResultStorage.txt";

//TEACHER COMMENT so what are these?
LPS25HB Sensor;
OpenLog resultStorage;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  resultStorage.begin();
  Sensor.begin();

  //TEACHER COMMENT what is this checking?
  if (Sensor.isConnected() == false) {
    Serial.println("SENSORBOARD HAS FAILED TO CONNECT");
    while (1)
      ;
  }

  //TEACHER COMMENT should you also check the sdcard/resultStorage?

  resultStorage.append(FILE_NAME);
  resultStorage.print("Time,Pressure,Temprature");

  resultStorage.syncFile();

  Serial.println("SETUP IS DONE");
}

//TEACHER COMMENT add a comment explaining what this is doing
void loop() {

  // if (Sensor.getPressure_hPa() >= 0) {
  //     digitalWrite(myLed, HIGH);
  //     delay(10);
  //     digitalWrite(myLed, LOW);
  // }
  // else{
  //   Serial.print("Pressure sensor not recording proper data");
  // }
  // if (Sensor.getTemperature_degC() >= 0) {
  //     digitalWrite(myLed, HIGH);
  //     delay(10);
  //     digitalWrite(myLed, LOW);
  // }
  // else{
  //   Serial.print("Temprature sensor not recording proper data");
  // }
  //   delay(1000);
  writeToSDcard(true);  //t = debugging  f = rocket lauch
}

void writeToSDcard(bool debug) {
  if (debug) {
    myTime = millis();
    Serial.print(myTime);  // prints time since program
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
  } else {
    myTime = millis();
    // Serial.print(myTime);  // prints time since program
    resultStorage.println(myTime);
    // Serial.print(",");
    resultStorage.print(",");
    // Serial.print(Sensor.getPressure_hPa());
    resultStorage.println(Sensor.getPressure_hPa());
    // Serial.print(",");
    resultStorage.print(",");
    // Serial.println(Sensor.getTemperature_degC());
    resultStorage.println(Sensor.getTemperature_degC());

    resultStorage.syncFile();
  }
}