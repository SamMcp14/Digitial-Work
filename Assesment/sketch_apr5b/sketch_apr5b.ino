#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

long myTime;


LPS25HB Sensor;
OpenLog resultStorage;

void setup() {
  Serial.begin(9600);

  Wire.begin();
  resultStorage.begin();

  Sensor.begin();

  if (Sensor.isConnected() == false) {
    Serial.println("BOARD HAS RECONECTED");

    while (1)
      ;
  }

  resultStorage.append("resultStorage.txt");
  resultStorage.println("This is recorded to resultStorage.txt");

  resultStorage.syncFile();

  Serial.println("Done!");

Serial.print("Time,Pressure,Temperature");
}

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
  delay(1000);
}
