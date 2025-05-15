  #include <Arduino.h>
  #include "./sensors/ultrasonic_sensor.h"
  #include "./sensors/huminity_sensor.h"
  #include "./sensors/nfc.h"
  #include "./sensors/servo_motor.h"
  #include <DHT.h>
  #include <WiFi.h>
  #include <ArduinoOTA.h>
  #include <WebServer.h>

  const char* ssid = "SLT";         
  const char* password = "6CC253A5"; 

  WebServer server(80); 
    

  void setup() {
    Serial.begin(9600);
    dht.begin();
  
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Connecting to WiFi...");
    
    }
    Serial.println(WiFi.localIP());
    Serial.println("Connected to WiFi");
  
    server.on("/", HTTP_GET, []() {
      server.send(200, "text/plain", "Hello World!");
    });
  
    
    server.begin(); 
    Serial.println("Web server started");
    setupNFC();
    setupServo();  // Initializes the servo motor

  }
  bool doorOpen = false;
String lastTagId = "";

void loop() {
  server.handleClient();

  String tagId = readNFCTag();

  if (tagId != "" && tagId != lastTagId) {
    Serial.print("Tag detected! UID: ");
    Serial.println(tagId);

    if (!doorOpen) {
      Serial.println("Opening door...");
      setServoAngle(90);  // Open
      doorOpen = true;
    } else {
      Serial.println("Closing door...");
      setServoAngle(0);   // Close
      doorOpen = false;
    }

    lastTagId = tagId;
    delay(1000); // Debounce
  }

  // Clear lastTagId if no tag is present anymore
  if (tagId == "") {
    lastTagId = "";
  }
}