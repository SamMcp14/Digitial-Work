
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>

//
LPS25HB Sensor; // Create an object of the LPS25HB class
OpenLog resultStorage; //Create instance

void setup()
{
    Serial.begin(9600);
 
  Wire.begin();
  resultStorage.begin(); //Open connection to OpenLog (no pun intended)

  Sensor.begin(); // Begin links an I2C port and I2C address to the sensor, sets an I2C speed, begins I2C on the main board, and then sets default settings

  if (Sensor.isConnected() == false) // The library supports some different error codes such as "DISCONNECTED"
  {
    Serial.println("LPS25HB disconnected. Reset the board to try again.");     // Alert the user that the device cannot be reached
  
    while (1);
  }
 
  resultStorage.append("resultStorage.txt");
  resultStorage.println("This is recorded to resultStorage.txt");
 
  resultStorage.syncFile();

  Serial.println("Done!");
}

void loop()
{
  Serial.print("Pressure in hPa: ");
  resultStorage.print("Pressure in hPa: ");
  Serial.print(Sensor.getPressure_hPa()); // Get the pressure reading in hPa
  resultStorage.print(Sensor.getPressure_hPa()); // Get the pressure reading in hPa
  resultStorage.println("               ");
  Serial.println("               ");
  Serial.print(", Temperature (degC): ");
  resultStorage.print(", Temperature (degC): ");
  Serial.println(Sensor.getTemperature_degC()); // Get the temperature in degrees C
  resultStorage.println(Sensor.getTemperature_degC()); // Get the temperature in degrees C
  resultStorage.println("               ");
  Serial.println("               ");

  resultStorage.syncFile();
    delay(1000); // Wait - 40 ms corresponds to the maximum update rate of the sensor (25 Hz)
}
