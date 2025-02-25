#include <Arduino.h>
#include "./motors/motor_control.h"
#include "./sensors/ultrasonic_sensor.h"
#include "./sensors/huminity_sensor.h"
#include "./IR_array_sensor/ir_array.h"
#include <DHT.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>

const char* ssid = "SLT";         
const char* password = "6CC253A5"; 

WebServer server(80); 

unsigned long previousMillis = 0;  
const long interval = 1000;        

void setup() {
  Serial.begin(9600);
  dht.begin();
  initMotors();

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  ArduinoOTA.onStart([]() {
    String type;
    if (ArduinoOTA.getCommand() == U_FLASH) { 
      type = "sketch";
    } else {
      type = "spiffs";
    }
    Serial.println("Start updating " + type);
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd OTA");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) {
      Serial.println("Auth Failed");
    } else if (error == OTA_BEGIN_ERROR) {
      Serial.println("Begin Failed");
    } else if (error == OTA_CONNECT_ERROR) {
      Serial.println("Connect Failed");
    } else if (error == OTA_RECEIVE_ERROR) {
      Serial.println("Receive Failed");
    } else if (error == OTA_END_ERROR) {
      Serial.println("End Failed");
    }
  });
  ArduinoOTA.begin();

  server.on("/readIRSensors", HTTP_GET, []() {
    int ir2, ir3;
    readIRSensors(ir2, ir3);
    String response = "IR2: " + String(ir2) + " IR3: " + String(ir3);
    server.send(200, "text/plain", response);
  });


  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "Hello World!");
  });
 
  
  server.begin(); 
  Serial.println("Web server started");
}

void loop() {
  ArduinoOTA.handle();
  server.handleClient(); 
  followLine ();
}


