// Include the external libaries used.
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

long myTime; // creating a variable for the amount of time passed since code started
const String FILE_NAME ="ResultStorage.txt"; // created a const for the file name

//TEACHER COMMENT so what are these?
LPS25HB Sensor; // Create the object of the presure sensor
OpenLog resultStorage; // Create instance

void setup() {
  Serial.begin(9600); // start serial monitor
  Wire.begin(); // Initalizes wire libary
  resultStorage.begin(); // Starts sd card storage
  Sensor.begin(); // starts the pressure/temprature sensor

// If sensor isnt connect print error message 
  if (Sensor.isConnected() == false) {
    Serial.println("SENSORBOARD HAS FAILED TO CONNECT");
    while (1);
  }

  //TEACHER COMMENT should you also check the sdcard/resultStorage?

  resultStorage.append(FILE_NAME); // Make the file for results on sdcard
  resultStorage.print("Time,Pressure,Temprature"); // CSV format

  resultStorage.syncFile(); 

  Serial.println("SETUP IS DONE"); // start loop
}

//TEACHER COMMENT add a comment explaining what this is doing
void loop() {
  writeToSDcard(true);  //t = debugging  f = rocket lauch
}

void writeToSDcard(bool debug) {
  if (debug) {
    myTime = millis();
    // prints time since program
    Serial.print(myTime);
    resultStorage.print(myTime);
// print comma
    Serial.print(","); 
    resultStorage.print(",");
// print pressure from sensor
    Serial.print(Sensor.getPressure_hPa());
    resultStorage.print(Sensor.getPressure_hPa());
// print comma
    Serial.print(",");
    resultStorage.print(",");
// print temprature
    Serial.println(Sensor.getTemperature_degC());
    resultStorage.println(Sensor.getTemperature_degC());

    resultStorage.syncFile();
// sink sdcard file
  } else { // if not debuging just print to resultStorage
    myTime = millis();
    resultStorage.println(myTime);
    resultStorage.print(",");
    resultStorage.println(Sensor.getPressure_hPa());
    resultStorage.print(",");
      resultStorage.println(Sensor.getTemperature_degC());

    resultStorage.syncFile();
// syncFile
  }
}