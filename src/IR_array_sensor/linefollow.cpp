#include "ir_array.h"
#include "./motors/motor_control.h"

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

   

    if (ir3 == 0) { 
        // Move forward if the middle sensor detects the line
        moveMotors();
    } else if (ir1 == 0) { 
        // Turn right if the leftmost sensor detects the line
        turnRight();    
    } else if (ir5 == 0) { 
        // Turn left if the rightmost sensor detects the line
        turnLeft();
    } else {
        // Stop motors if no line is detected
        stopMotors(); 
    }
}
