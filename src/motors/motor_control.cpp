#include <Arduino.h>
#include "motor_control.h"

void initMotors() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void moveMotors() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA,  100); // Speed control (0-255)

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Motors running... FORWARD");
}

void stopMotors() {
  // Stop Motor A
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW); // Set both inputs to LOW to stop the motor
  analogWrite(ENA, 0); // Set speed to 0 to stop

  // Stop Motor B
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); // Set both inputs to LOW to stop the motor
  analogWrite(ENB, 0); // Set speed to 0 to stop

  Serial.println("Motors stopped.");
}

void moveback() {
   // Reverse Motor A
  digitalWrite(IN1, LOW);   // Set IN1 LOW
  digitalWrite(IN2, HIGH);  // Set IN2 HIGH to go backward
  analogWrite(ENA, 100);    // Set speed (0-255)

  // Reverse Motor B
  digitalWrite(IN3, LOW);   // Set IN3 LOW
  digitalWrite(IN4, HIGH);  // Set IN4 HIGH to go backward
  analogWrite(ENB, 100);    // Set speed (0-255)

  Serial.println("Motors running... BACKWARD");
}


void turnRight() {
  // Turn Motor A forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B reverse (Right turn)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Right");
}

void turnLeft() {
  // Turn Motor A reverse (Left turn)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Left");
}

void turnLeft90() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100); 

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100); 

  Serial.println("Turning Left 90 Degrees");
  
  
  delay(1000);  

  stopMotors();
}

 void turnRight90() {
  // Turn Motor A forward (Right turn)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100); // Speed control (0-255)

  // Turn Motor B reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100); // Speed control (0-255)

  Serial.println("Turning Right 90 Degrees");
  
  // Wait for the robot to complete a 90-degree turn
  // You may need to adjust the time (in milliseconds) based on your setup
  delay(1000);  // Adjust this delay based on the robot's speed and wheel size

  // Stop the motors after the turn
  stopMotors();
}

  








// #include <Arduino.h>
// #include "motor_control.h"

// void initMotors() {
//   pinMode(ENA, OUTPUT);
//   pinMode(IN1, OUTPUT);
//   pinMode(IN2, OUTPUT);
//   pinMode(ENB, OUTPUT);
//   pinMode(IN3, OUTPUT);
//   pinMode(IN4, OUTPUT);

//   pinMode(ENC, OUTPUT);
//   pinMode(IN5, OUTPUT);
//   pinMode(IN6, OUTPUT);
//   pinMode(END, OUTPUT);
//   pinMode(IN7, OUTPUT);
//   pinMode(IN8, OUTPUT);
// }

// void moveMotors() {
//   // Move Left Side Forward
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, 100);

//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   analogWrite(ENB, 100);

//   // Move Right Side Forward
//   digitalWrite(IN5, HIGH);
//   digitalWrite(IN6, LOW);
//   analogWrite(ENC, 100);

//   digitalWrite(IN7, HIGH);
//   digitalWrite(IN8, LOW);
//   analogWrite(END, 100);

//   Serial.println("Motors running... FORWARD");
// }

// void stopMotors() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, 0);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, LOW);
//   analogWrite(ENB, 0);

//   digitalWrite(IN5, LOW);
//   digitalWrite(IN6, LOW);
//   analogWrite(ENC, 0);

//   digitalWrite(IN7, LOW);
//   digitalWrite(IN8, LOW);
//   analogWrite(END, 0);

//   Serial.println("Motors stopped.");
// }

// void moveBack() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   analogWrite(ENA, 100);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   analogWrite(ENB, 100);

//   digitalWrite(IN5, LOW);
//   digitalWrite(IN6, HIGH);
//   analogWrite(ENC, 100);

//   digitalWrite(IN7, LOW);
//   digitalWrite(IN8, HIGH);
//   analogWrite(END, 100);

//   Serial.println("Motors running... BACKWARD");
// }

// void turnRight() {
//   digitalWrite(IN1, HIGH);
//   digitalWrite(IN2, LOW);
//   analogWrite(ENA, 100);

//   digitalWrite(IN3, HIGH);
//   digitalWrite(IN4, LOW);
//   analogWrite(ENB, 100);

//   digitalWrite(IN5, LOW);
//   digitalWrite(IN6, HIGH);
//   analogWrite(ENC, 100);

//   digitalWrite(IN7, LOW);
//   digitalWrite(IN8, HIGH);
//   analogWrite(END, 100);

//   Serial.println("Turning Right");
// }

// void turnLeft() {
//   digitalWrite(IN1, LOW);
//   digitalWrite(IN2, HIGH);
//   analogWrite(ENA, 100);

//   digitalWrite(IN3, LOW);
//   digitalWrite(IN4, HIGH);
//   analogWrite(ENB, 100);

//   digitalWrite(IN5, HIGH);
//   digitalWrite(IN6, LOW);
//   analogWrite(ENC, 100);

//   digitalWrite(IN7, HIGH);
//   digitalWrite(IN8, LOW);
//   analogWrite(END, 100);

//   Serial.println("Turning Left");
// }

// void turnLeft90() {
//   turnLeft();
//   delay(1000);
//   stopMotors();
//   Serial.println("Turned Left 90 Degrees");
// }

// void turnRight90() {
//   turnRight();
//   delay(1000);
//   stopMotors();
//   Serial.println("Turned Right 90 Degrees");
// }
