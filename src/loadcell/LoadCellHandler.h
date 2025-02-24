// LoadCellHandler.h

#ifndef LOADCELLHANDLER_H
#define LOADCELLHANDLER_H

#include <HX711_ADC.h>
#include <EEPROM.h>

// Pin definitions
const int HX711_dout = 4; // MCU > HX711 dout pin
const int HX711_sck = 5;  // MCU > HX711 sck pin

class LoadCellHandler {
public:
    LoadCellHandler();
    void begin();
    void update();
    void tare();
    float getLoadCellData();

private:
    HX711_ADC LoadCell;
    unsigned long t;
    const int calVal_eepromAdress = 0;
    float calibrationValue;
};

#endif // LOADCELLHANDLER_H
