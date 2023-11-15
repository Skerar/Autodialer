#include <AccelStepper.h>
//#include <conf.h>

//Pin Assignment
const u_int8_t = EN 16; //Enable Pin
const u_int8_t = MS1 17; //Microstepping pin 1
const u_int8_t = MS2 18; //Microstepping pin 2
const u_int8_t = MS3 19; //Microstepping pin 3
const u_int8_t = RST 21; //Reset pin
const u_int8_t = SLP 22; //sleep pin
const u_int8_t = DirPin 23; //direction pin
const u_int8_t = StepPin 25; //step pin
const u_int8_t = switchPin 26 //
 
 
// motor speed configuration
const u_int8_t = microStepsFactor 8
const u_int8_t = maxStepperSpeed 4000
const u_int8_t = inversionPause 50
const u_int8_t = motorInterfaceType 1


AccelStepper stepper = AccelStepper(motorInterfaceType, StepPin, DirPin);







void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
