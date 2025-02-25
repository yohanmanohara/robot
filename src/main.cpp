#include <Arduino.h>
#include "./stepermotor/stepfunction.h"
#include "./loadcell/LoadCellHandler.h"
LoadCellHandler loadCellHandler;


const int stepDelay = 200;  

const int stepsForward = (1 * 1000000) / stepDelay;  
const int stepsBackward = (20 * 1000000) / stepDelay; 

void setup() {
    motorSetup();
    loadCellHandler.begin();
}
void loop() {
    moveForward(stepsForward, stepDelay);
    delay(1000); 

 

   
}



