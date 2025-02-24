#include <Arduino.h>
#include "./stepermotor/stepfunction.h"

// Configuration settings
const int stepDelay = 20;  // Delay for each step (in microseconds)

// Calculate the number of steps based on the desired movement time
const int stepsForward = (1 * 1000000) / stepDelay;  // Steps to move forward in 40 seconds
const int stepsBackward = (20 * 1000000) / stepDelay; // Steps to move backward in 50 seconds

void setup() {
    motorSetup(); // Initialize motor pins
}

void loop() {
    // Move forward for 40 seconds
    moveForward(stepsForward, stepDelay); // Adjust final delay as needed
    delay(1000); // Optional delay after moving forward

    // Move backward for 50 seconds
    moveBackward(stepsBackward, stepDelay); // Adjust final delay as needed
    delay(1000); // Optional delay after moving backward
}
