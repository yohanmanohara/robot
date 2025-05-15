#include "servo_motor.h"

Servo myServo;

void setupServo() {
  myServo.setPeriodHertz(50); // Standard 50Hz for analog servo
  myServo.attach(SERVO_PIN, 500, 2400); // Attach with min/max pulse width
  myServo.write(0); // Initial position
}

void setServoAngle(int angle) {
  if (angle < 0) angle = 0;
  if (angle > 180) angle = 180;
  myServo.write(angle);
}
    