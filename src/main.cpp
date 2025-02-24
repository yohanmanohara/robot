#include <Arduino.h>
#include "./motors/motor_control.h"
#include "./sensors/ultrasonic_sensor.h"
#include "./sensors/huminity_sensor.h"
#include "./IR_array_sensor/ir_array.h"
#include <DHT.h>
#include <WiFi.h>


unsigned long previousMillis = 0;  // Stores the last time data was collected
const long interval = 1000;         // Interval to collect data (in milliseconds)

void setup() {
  Serial.begin(9600); 
  dht.begin(); 
//   initUltrasonicSensor();
  initMotors();


}

void loop() {
//   unsigned long currentMillis = millis();  

//   float distance = measureDistance();
 
//   if (distance <= 16.0) {
//     Serial.println("Object detected! Stopping motors.");
//     Serial.println(distance);
//     stopMotors();
//   } else {
    followLine();
//   }

//   // Collect and display data at intervals
//   if (currentMillis - previousMillis >= interval) {
//     previousMillis = currentMillis;  // Update the last time we collected data
//     collectAndDisplayData();         // Call the data collection function
//   }






}
