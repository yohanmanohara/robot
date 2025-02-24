#ifndef IR_ARRAY_H
#define IR_ARRAY_H

#include <Arduino.h>
// IR Sensor Pins
#define IR1_PIN 13
#define IR2_PIN 12
#define IR3_PIN 14
#define IR4_PIN 27
#define IR5_PIN 26

// #define STOP_DISTANCE 15

// Function declarations
void readIRSensors(int &ir1, int &ir2, int &ir3, int &ir4, int &ir5);
void followLine();
// void moveMotors();
// void turnLeft();
// void turnRight();
// void stopMotors();
// float getDistance();

#endif // IR_ARRAY_H
