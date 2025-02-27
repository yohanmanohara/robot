#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

// Motor A
#define ENA 15  
#define IN1 21  
#define IN2 18  

// Motor B
#define ENB 5  
#define IN3 22  
#define IN4 19  



// Motor C (if you are using another motor, adjust as needed)
#define ENC 4  // Motor C speed (PWM)
#define IN5 33  // Motor C direction
#define IN6 25  // Motor C direction

// Motor D (if you are using another motor, adjust as needed)
#define END 32  // Motor D speed (PWM)
#define IN7 23 // Motor D direction
#define IN8 17  // Motor D direction

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