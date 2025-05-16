#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <WebServer.h>

#include "./sensors/nfc.h"
#include "./sensors/servo_motor.h"

// WiFi credentials
const char* ssid = "SLT";
const char* password = "6CC253A5";

// Firebase config
#define API_KEY "AIzaSyBk31zPSuAN5WZY3GBFGYIbC-WqDOzV7pc"
#define DATABASE_URL "https://smart-warehouse-5bcd3-default-rtdb.firebaseio.com"
#define FIRESTORE_PROJECT_ID "smart-warehouse-5bcd3"

// Buzzer config
const int buzzerPin = 14; // Change this to your connected buzzer pin


FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

WebServer server(80);

bool doorOpen = false;
String lastTagId = "";
unsigned long lastAccessTime = 0;
int invalidAttemptCount = 0;
const int maxInvalidAttempts = 3;

void setup() {
  Serial.begin(9600);


  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Firebase Auth
  config.api_key = API_KEY;
  config.database_url = DATABASE_URL;
  auth.user.email = "warushayohan80@gmail.com";
  auth.user.password = "yohanmano";

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/plain", "Smart Warehouse Door Control");
  });
  server.begin();
  Serial.println("Web server started");

  setupNFC();
  setupServo();
}

// Short beep for success feedback
void playShortBeep() {
  tone(buzzerPin, 1000); // 1 kHz tone
  delay(1000);
  noTone(buzzerPin);
}

// Long beep for alert
void playAlertBeep() {
  tone(buzzerPin, 500); // 500 Hz tone
  delay(2000);
  noTone(buzzerPin);
}


void loop() {
  server.handleClient();

  String scannedTagId = readNFCTag();

  if (scannedTagId != "" && scannedTagId != lastTagId) {
    lastTagId = scannedTagId;

    Serial.print("Scanned Tag ID: ");
    Serial.println(scannedTagId);

    String docPath = "employees/" + scannedTagId;

    // Try to get Firestore doc
    if (Firebase.Firestore.getDocument(&fbdo, FIRESTORE_PROJECT_ID, "(default)", docPath.c_str())) {
      DynamicJsonDocument doc(1024);
      DeserializationError error = deserializeJson(doc, fbdo.payload());

      if (!error) {
        if (doc.containsKey("fields") && doc["fields"]["id"].containsKey("stringValue")) {
          String empId = doc["fields"]["id"]["stringValue"].as<String>();

          if (empId == scannedTagId) {
            Serial.println("✅ Access granted.");
            setServoAngle(doorOpen ? 0 : 90);
            doorOpen = !doorOpen;
            invalidAttemptCount = 0;
          } else {
            Serial.println("❌ ID mismatch.");
            invalidAttemptCount++;
          }
        } else {
          Serial.println("❌ 'id' field missing or invalid format.");
          invalidAttemptCount++;
        }
      } else {
        Serial.println("❌ JSON parse error: ");
        Serial.println(error.c_str());
        invalidAttemptCount++;
      }
    } else {
      Serial.print("❌ Firestore fetch error: ");
      Serial.println(fbdo.errorReason());
      invalidAttemptCount++;
    }

    if (invalidAttemptCount >= maxInvalidAttempts) {
      Serial.println("🚨 Too many invalid attempts! Triggering alert...");
      playAlertBeep();
      invalidAttemptCount = 0;
      lastTagId = "";  // reset so same tag can try again later
    }
  }

  // Reset lastTagId when no tag is scanned
  if (scannedTagId == "") {
    lastTagId = "";
  }
}
