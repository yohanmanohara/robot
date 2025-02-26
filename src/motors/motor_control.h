#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor A
#define ENA 15  // Motor A speed (PWM)
#define IN1 21  // Motor A direction
#define IN2 18  // Motor A direction

// Motor B
#define ENB 5   // Motor B speed (PWM)
#define IN3 22  // Motor B direction
#define IN4 19  // Motor B direction



// Motor C (if you are using another motor, adjust as needed)
#define ENC 23  // Motor C speed (PWM)
#define IN5 25  // Motor C direction
#define IN6 33  // Motor C direction

// Motor D (if you are using another motor, adjust as needed)
#define END 32  // Motor D speed (PWM)
#define IN7 35 // Motor D direction
#define IN8 34  // Motor D direction

void initMotors();
void moveMotors();
void stopMotors();
void moveBack();
void turnLeft();
void turnRight();
void turnLeft90();
void turnRight90();
void initIRSensors();

#endif
