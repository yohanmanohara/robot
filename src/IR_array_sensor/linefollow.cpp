#include "ir_array.h"
#include "./motors/motor_control.h"

void initIRSensors() {
    pinMode(IR1_PIN, INPUT);
    pinMode(IR2_PIN, INPUT);
    pinMode(IR3_PIN, INPUT);
    pinMode(IR4_PIN, INPUT);
    pinMode(IR5_PIN, INPUT);
}

void readIRSensors(int &ir1, int &ir2, int &ir3, int &ir4, int &ir5) {
    ir1 = digitalRead(IR1_PIN);
    ir2 = digitalRead(IR2_PIN);
    ir3 = digitalRead(IR3_PIN);
    ir4 = digitalRead(IR4_PIN);
    ir5 = digitalRead(IR5_PIN);
}

void followLine() {
    int ir1, ir2, ir3, ir4, ir5;
    readIRSensors(ir1, ir2, ir3, ir4, ir5);

    Serial.print("IR1: "); Serial.print(ir1);
    Serial.print(" IR2: "); Serial.print(ir2);
    Serial.print(" IR3: "); Serial.print(ir3);
    Serial.print(" IR4: "); Serial.print(ir4);
    Serial.print(" IR5: "); Serial.println(ir5);

    // **For black line tracking, the logic is reversed**
    if (ir1 == 1 && ir2 == 1 && ir3 == 0 && ir4 == 1 && ir5 == 1) {  
        moveMotors();  // Move forward when black line is centered
    
    } else if (ir1 == 1 && ir2 == 1 && ir3 == 1 && ir4 == 1 && ir5 == 0) { 
        turnRight();  // Turn right if the line is more towards the right
    
    } else if (ir1 == 0 && ir2 == 1 && ir3 == 1 && ir4 == 1 && ir5 == 1) { 
        turnLeft();  // Turn left if the line is more towards the left
    
    } else {
        stopMotors();  // Stop if no line is detected
    }
}
