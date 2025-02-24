// LoadCellHandler.cpp

#include "LoadCellHandler.h"

LoadCellHandler::LoadCellHandler() : LoadCell(HX711_dout, HX711_sck), t(0), calibrationValue(197.0) {}

void LoadCellHandler::begin() {
    Serial.begin(9600);
    delay(10);
    Serial.println();
    Serial.println("Starting...");

    LoadCell.begin();
    
    // Uncomment the following lines if you want to fetch the calibration value from EEPROM
    // EEPROM.begin(512);
    EEPROM.get(calVal_eepromAdress, calibrationValue);

    unsigned long stabilizingtime = 2000;
    boolean _tare = true;
    LoadCell.start(stabilizingtime, _tare);
    if (LoadCell.getTareTimeoutFlag()) {
        Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
        while (1);
    } else {
        LoadCell.setCalFactor(calibrationValue);
        Serial.println("Startup is complete");
    }
}

void LoadCellHandler::update() {
    static boolean newDataReady = 0;
    const int serialPrintInterval = 0;

    if (LoadCell.update()) newDataReady = true;

    if (newDataReady) {
        if (millis() > t + serialPrintInterval) {
            float i = LoadCell.getData();
            Serial.print("Load_cell output val: ");
            Serial.println(i);
            newDataReady = 0;
            t = millis();
        }
    }
}

void LoadCellHandler::tare() {
    LoadCell.tareNoDelay();
    if (LoadCell.getTareStatus() == true) {
        Serial.println("Tare complete");
    }
}

float LoadCellHandler::getLoadCellData() {
    return LoadCell.getData();
}
