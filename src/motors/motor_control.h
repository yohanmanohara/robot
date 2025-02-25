#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor A
#define ENA 15  // Motor A speed (PWM)
#define IN1 21 // Motor A direction
#define IN2 18 // Motor A direction

// Motor B
#define ENB 5  // Motor B speed (PWM)
#define IN3 22 // Motor B direction
#define IN4 19 // Motor B direction

void initMotors();
void moveMotors();
void stopMotors();
void moveback();
void turnLeft();
void turnRight();
void initIRSensors();
void turnRight90();
void turnLeft90();
#endif
