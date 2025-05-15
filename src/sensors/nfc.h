#ifndef NFC_H
#define NFC_H

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 21      // Default SS pin for ESP32
#define RST_PIN 22     // Default RST pin for ESP32

extern MFRC522 mfrc522;  // Declare mfrc522 as an external object to be defined in .cpp file

void setupNFC();
String readNFCTag();

#endif // NFC_H     