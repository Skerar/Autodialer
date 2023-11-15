#include <AccelStepper.h>
#include "conf.h"

// //Pin Assignment
// const uint8_t EN = 16; //Enable Pin
// const uint8_t MS1 = 17; //Microstepping pin 1
// const uint8_t MS2 = 18; //Microstepping pin 2
// const uint8_t MS3 = 19; //Microstepping pin 3
// const uint8_t RST = 21; //Reset pin
// const uint8_t SLP = 22; //sleep pin
// const uint8_t DirPin = 23; //direction pin
// const uint8_t StepPin = 25; //step pin
// const uint8_t switchPin = 26; //pin for zeroing switch
 
 
// // motor configuration
// const uint8_t maxStepperSpeed = 4000;
// const uint8_t inversionPause = 50;

//Runtime vars
uint8_t DialPos = 0;    //current dial postition
uint8_t DiskPos[] = {0, 0, 0};    //array of current disk positions

//initialize motor construct
AccelStepper motor = AccelStepper(1, StepPin, DirPin);








void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  motor.setMaxSpeed(maxStepperSpeed);
  motor.setAcceleration(acceleration);

}

void loop() {
  // put your main code here, to run repeatedly:

  for (uint8_t i = 0, i < 99, i++) {

    
  }

}
