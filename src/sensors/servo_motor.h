#ifndef SERVO_MOTOR_H
#define SERVO_MOTOR_H

#include <ESP32Servo.h>

#define SERVO_PIN 13  // You can change this to any PWM-capable GPIO

void setupServo();
void setServoAngle(int angle);

#endif
