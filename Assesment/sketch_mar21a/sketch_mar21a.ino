
#include <Wire.h>
#include <SparkFun_Qwiic_OpenLog_Arduino_Library.h>
#include <SparkFun_LPS25HB_Arduino_Library.h>


//,, 
LPS25HB Sensor;
OpenLog resultStorage;

void setup()
{
  Serial.begin(9600);

  Wire.begin();
  resultStorage.begin();

  Sensor.begin();

  if (Sensor.isConnected() == false)
  {
    Serial.println("BOARD HAS RECONECTED");

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
  Serial.print(Sensor.getPressure_hPa());
  resultStorage.print(Sensor.getPressure_hPa());
  resultStorage.println("               ");
  Serial.println("               ");
  Serial.print(", Temperature (degC): ");
  resultStorage.print(", Temperature (degC): ");
  Serial.println(Sensor.getTemperature_degC()); 
  resultStorage.println(Sensor.getTemperature_degC()); 
  resultStorage.println("               ");
  Serial.println("               ");

  resultStorage.syncFile();
  delay(1000);
}
