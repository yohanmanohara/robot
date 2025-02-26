



#include <Arduino.h>
#include "motor_control.h"

void initMotors() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(ENC, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(END, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
}

void moveMotors() {
  // Move Left Side Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100);

  // Move Right Side Forward
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 100);

  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, 100);

  Serial.println("Motors running... FORWARD");
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 0);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
  analogWrite(END, 0);

  Serial.println("Motors stopped.");
}

void moveBack() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 100);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 100);

  Serial.println("Motors running... BACKWARD");
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 100);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 100);

  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  analogWrite(ENC, 100);

  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  analogWrite(END, 100);

  Serial.println("Turning Right");
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 100);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 100);

  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  analogWrite(ENC, 100);

  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  analogWrite(END, 100);

  Serial.println("Turning Left");
}

void turnLeft90() {
  turnLeft();
  delay(1000);
  stopMotors();
  Serial.println("Turned Left 90 Degrees");
}

void turnRight90() {
  turnRight();
  delay(1000);
  stopMotors();
  Serial.println("Turned Right 90 Degrees");
}
