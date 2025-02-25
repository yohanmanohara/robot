#include <Arduino.h>
#include "./stepermotor/stepfunction.h"
#include "./loadcell/LoadCellHandler.h"
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <WebServer.h>


const char* ssid = "SLT";         
const char* password = "6CC253A5"; 
WebServer server(80); 
LoadCellHandler loadCellHandler;


const int stepDelay = 200;  

const int stepsForward = (1 * 1000000) / stepDelay;  
const int stepsBackward = (20 * 1000000) / stepDelay; 

void setup() {
  Serial.begin(9600);
   
   
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



  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "Hello World!");
  });
 
  
  server.begin(); 
  Serial.println("Web server started");
  Serial.println(WiFi.localIP());

 // motorSetup();
    // loadCellHandler.begin();
}
void loop() {
  ArduinoOTA.handle();
  server.handleClient(); 
    // moveForward(stepsForward, stepDelay);
    // delay(1000); 

 

   
}



