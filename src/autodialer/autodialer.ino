#include <Arduino.h>
#include <AccelStepper.h>



#include "DriverControl.h"

uint8_t StepsPerDigit = 2;

//uint8_t StepsPerRev = 200;

const uint8_t MinPos = 0;             //sets minimum dial value
const uint8_t MaxPos = 99;            //sets maximum dial value

uint8_t MicroStep = 0;                //Sets microstepping setting. 0:full, 1:1/2, 2:1/4, 3:1/8, 4:1/16

uint8_t MoveSteps = 0;                //Used for storing steps for next move

uint8_t StepDelay = 700;              //Delay to use between step pulses in microseconds

uint8_t Position = 0;                 //Current position
uint8_t NextPos = 30;                 //next position to go to

uint8_t DwellTime = 0;                //time to dwell at one postition

uint8_t RunMode = 1;



bool Open = false;                    

volatile bool switchState = false;    //position switch state

uint8_t findMove (uint8_t H, uint8_t T, uint8_t M, bool R) {
  
  //calculates move from current position to another position,

  
  // H = Here
  // T = There
  // M = Max

  uint8_t move = 0;

  if (H == T) {
    return 0;
  }

  if (R == true) {

    if (H > T) {
      move = (H - T);
      
      Serial.println("moving ccw " + move);

      return move;
    }

    else if (H < T) {
      move = (M - T + H);

      Serial.println("moving ccw " + move);

      return move;
    }

  }

  if (R == false) {

    if (H > T) {
      move = (M - H + T);

      Serial.println("moving cw " + move);

      return move;
    }

    else if (H < T) {
      move = (T - H);

      Serial.println("moving cw " + move);

      return move;
    }

  }

}

void dial(uint8_t g1_min, uint8_t g2_min, uint8_t g3_min, uint8_t g1_max, uint8_t g2_max, uint8_t g3_max, uint8_t interval) {
  for (uint8_t g1 = g1_min; g1 < g1_max; g1 = g1 + interval) {

    fullTurn(3, true);

    Serial.println("Going to " + Position);

    Goto(Position, g1, MaxPos, true);

    fullTurn(2, false);

    for (uint8_t g2 = g2_min; g2 < g2_max; g2 = g2 + interval) {

      Serial.println("Going to " + Position);

      Goto(Position, g2, MaxPos, false);

      fullTurn(1, true);

      for (uint8_t g3 = g3_min; g3 < g3_max; g3 = g3 + interval) {
        
        Serial.println("Going to " + Position);

        Goto(Position, g3, MaxPos, true);
        
        Open = checkOpen();
        
        if (Open == true) {
          break;
        }

      }
    }
  }
}

bool checkOpen() {
  
  Goto(Position, 85, MaxPos, true);

  if (switchState == true) {
    delay(75);
    if (switchState == true) {
      return true;
    }
    else {
      return false;
    }
  }

  return false;

}

void Goto(uint8_t H, uint8_t T, uint8_t M, bool R){

  uint8_t move = findMove(H, T, M, R) * StepsPerDigit;
  
  setDir(R);
  step(move);

  Position = T;

}

void step(uint8_t steps) {

  for (uint8_t x = 0; x < steps; x++){

    delayMicroseconds(StepDelay);
    digitalWrite(StepPin,HIGH);
    delayMicroseconds(StepDelay);
    digitalWrite(StepPin,LOW);
  }  

}

void fullTurn(uint8_t N, bool R) {

  uint8_t steps = (N * StepsPerRev);

  setDir(R);
  step(steps);

}

void setDir(bool R) {

  if (R == true){
    digitalWrite(DirPin, HIGH);
  }

  else if (R == false) {
    digitalWrite(DirPin, LOW);
  }

}

void switchOn() {

  switchState = true;

}

void switchOff() {

  switchState = false;

}

void setup() {

  Serial.begin(115200);

  pinMode(StepPin,OUTPUT);
  pinMode(DirPin,OUTPUT);
  //pinMode(LED_BUILTIN, OUTPUT);
  pinMode(EN, OUTPUT);
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(MS3, OUTPUT);
  pinMode(RST, OUTPUT);
  pinMode(SLP, OUTPUT);

  SetMicroStepMode(MicroStep);
  
  DriverSleep(false);
  DriverReset(false);
  DriverEnable(true);
  
  // attachInterrupt(digitalPinToInterrupt(switchPin), switchOn, RISING);
  // attachInterrupt(digitalPinToInterrupt(switchPin), switchOff, FALLING);

}

void loop() {

  switch (RunMode) {
  case 0:
    //try every combination
    dial(0, 0, 0, 99, 99, 99, 1);
    break;

  case 1:
    //try every third digit
    dial(0, 0, 0, 99, 99, 99, 3);
    break;

  case 2:

    break;

  default:
  
    break;

  }


}
