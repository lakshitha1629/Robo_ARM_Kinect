/***********************************************************************
 * Arm control code 

 * Connections:
 * Digital pin 10 - base servo signal 
 *              9 - shoulder servo signal 
 *              6 - elbow servo signal 
 *              5 - wrist servo signal 
 ***********************************************************************/

#include <Servo.h>
#include <Wire.h>
#include <math.h>

#define PI 3.14159

// Object definitions
Servo baseServo, shoulderServo, elbowServo, wristServo;

// Motor ranges hardcoded for normal arm
int basePin = 10, shoulderPin = 9, elbowPin = 6; 
int baseMin     = 10, baseMax     = 150;
int shoulderMin = 95, shoulderMax = 170;
int elbowMin    = 45, elbowMax    = 130;
int armAngles[4] = {0, 100, 60, 90}; // 0 - dummy, 1 - base, 2 - shoulder, 3 - elbow


void setup() {
  Serial.begin(9600);      

  // initialize servos
  baseServo.attach(basePin);
  baseServo.write(90);
  
  shoulderServo.attach(shoulderPin);
  shoulderServo.write(100);
  
  elbowServo.attach(elbowPin);
  elbowServo.write(130);
  
}

void loop() {
  // get data as they become available
  if(Serial.available() > 3){
    for(int i = 1; i < 4; i++){
      armAngles[i] = Serial.read();
    }  
  }
  
  // write to base motor
  if(armAngles[1] >= baseMin && armAngles[1] <= baseMax) baseServo.write(armAngles[1]);
  else if(armAngles[1] <= baseMin) baseServo.write(baseMin);
  else if(armAngles[1] >= baseMax) baseServo.write(baseMax);
  delay(10);
  
  // write to shoulder motor
  if(armAngles[2] >= shoulderMin && armAngles[2] <= shoulderMax) shoulderServo.write(armAngles[2]);
  else if(armAngles[2] <= shoulderMin) shoulderServo.write(shoulderMin);
  else if(armAngles[2] >= shoulderMax) shoulderServo.write(shoulderMax);
  delay(10);
  
  // write to elbow motor
  if(armAngles[3] >= elbowMin && armAngles[3] <= elbowMax) elbowServo.write(armAngles[3]);
  else if(armAngles[3] <= elbowMin) elbowServo.write(elbowMin);
  else if(armAngles[3] >= elbowMax) elbowServo.write(elbowMax);
  delay(10);
  
}