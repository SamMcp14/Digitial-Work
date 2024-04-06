//TEACHER COMMENT I would make sure to have a descriptive filename so try doing a save as and calling it
// assessment or sensorPackage or SamsSensorStuff - your current name will keep you from a merit grade
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

//TEACHER COMMENT what is this being created for?
long myTime;

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
    Serial.println("BOARD HAS RECONECTED");

    while (1);
  }

  //TEACHER COMMENT should you also check the sdcard/resultStorage?

  resultStorage.append("resultStorage.txt");
  resultStorage.println("This is recorded to resultStorage.txt"); //TEACHER COMMENT maybe this and line 36 should be merged?

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
  delay(1000);
}
