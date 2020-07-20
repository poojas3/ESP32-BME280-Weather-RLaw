// This is the master version of this project
// This is another test of gits pull
// this is robbins change
#include <Arduino.h>
#include "sensor_readings.h"
#include "settings.h"    // The order is important!

void refresh_readings();  // Declare in the header so that the compiler knows about it before it is called in loop()

#ifndef LED_BUILTIN
#define LED_BUILTIN 2   // This is valid for the nodemcu-32S
#endif

#define SEALEVELPRESSURE_HPA (1013.25)

// bme is global to this file only
Adafruit_BME280 bme; // I2C
Adafruit_BME280 bme;

void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(9600);
  bool status;

  // (you can also pass in a Wire library object like &Wire2)
  status = bme.begin(0x76);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);  // Infinite loop
  }
}

void loop() {
<<<<<<< HEAD
  refresh_readings();
  delay(4000);
}

void refresh_readings() {
  float f_temperature;
  float f_humidity;
  float f_pressure;
  float f_altitude;

  digitalWrite(LED_BUILTIN, HIGH);
  f_temperature = bme.readTemperature();
  f_humidity = bme.readHumidity();
  f_pressure = bme.readPressure() / 100.0F;
  f_altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);

  // Temperature
  Serial.print(f_temperature);
  Serial.println(" °C");

  // Humidity
  Serial.print(f_humidity);
  Serial.println(" %");

  // Pressure
  Serial.print(f_pressure);
  Serial.println(" hPa");

  // Appx altitude
  Serial.print(f_altitude);
  Serial.println(" m");   
  
  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("-----v1-----");   
=======
  refresh_readings(bme);  // Passing the bme object to the function as bme is only "global" in this file.
  delay(2000);
>>>>>>> 68bdcb933f3d7bf8d3e3b748f0c79047a29b1d52
}