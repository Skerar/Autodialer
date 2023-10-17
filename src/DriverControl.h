#ifndef DriverControl
#define DriverControl

#include "Pins.h"

uint8_t StepsPerRev = 200;      //sets steps per revolution

void DriverSleep(bool state) {
  
  if (state == true) {
    digitalWrite(SLP,LOW);
  }
  else {
    digitalWrite(SLP,HIGH);
  }

}

void DriverReset(bool state) {
  
  if (state == true) {
    digitalWrite(RST,LOW);
  }
  else {
    digitalWrite(RST,HIGH);
  }
}

void DriverEnable(bool state) {
  
  if (state == true) {
    digitalWrite(EN,LOW);
  }
  else {
    digitalWrite(EN,HIGH);
  }
}

void SetMicroStepMode(uint8_t mode){

  switch (mode){
    case 1:
      //set pin values for half steps
      digitalWrite(MS1,HIGH);
      digitalWrite(MS2,LOW);
      digitalWrite(MS3,LOW);
      
      StepsPerRev = 400;
      
      break;
    
    case 2:
      //set pin values for quarter steps
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,HIGH);
      digitalWrite(MS3,LOW);
      
      StepsPerRev = 800;
      
      break;

    case 3:
      //set pin values for eighth steps
      digitalWrite(MS1,HIGH);
      digitalWrite(MS2,HIGH);
      digitalWrite(MS3,LOW);
      
      StepsPerRev = 1600;
      
      break;
    
    case 4:
      //set pin values for 16th steps
      digitalWrite(MS1,HIGH);
      digitalWrite(MS2,HIGH);
      digitalWrite(MS3,HIGH);
      
      StepsPerRev = 3200;
      
      break;

    default:
      //set pin values for full steps
      digitalWrite(MS1,LOW);
      digitalWrite(MS2,LOW);
      digitalWrite(MS3,LOW);
      
      StepsPerRev = 200;
      
      break;

  }
}

#endif