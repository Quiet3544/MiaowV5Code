#include "functions.h"
#include <vex.h>
#include <iostream>

// braking functions
void brakeDrive(vex::brakeType braket){
  driveBackRight.stop(braket);
  driveMiddleRight.stop(braket);
  driveFrontRight.stop(braket);

  driveBackLeft.stop(braket);
  driveMiddleLeft.stop(braket); 
  driveFrontLeft.stop(braket);
}
void brakeRight(){
  driveBackRight.stop(vex::brake);
  driveMiddleRight.stop(vex::brake);
  driveFrontRight.stop(vex::brake);
}
void brakeLeft(){
  driveBackLeft.stop(vex::brake);
  driveMiddleLeft.stop(vex::brake); 
  driveFrontLeft.stop(vex::brake);
}

void driveFunc(){
  if(master.Axis2.value() == 0){ // telling it to break if joystick is still
    brakeRight();
  }
  if(master.Axis3.value() == 0){
    brakeLeft();
  }
  double lefts = (master.Axis3.position()/100.0)*12.0; // using joystick function to make voltage value by getting it's position and diving by 100 then multiply by 12(maximum voltage) 
  double rights = (master.Axis2.position()/100.0)*12.0;

  if(master.Axis2.value() != 0){ // if joystick moves, then spin motors according to joystick's position.
    driveBackRight.spin(vex::fwd,rights,vex::volt);
    driveMiddleRight.spin(vex::fwd,rights,vex::volt);
    driveFrontRight.spin(vex::fwd,rights,vex::volt);
  }
  if(master.Axis3.value() != 0){
    driveBackLeft.spin(vex::fwd,lefts,vex::volt);
    driveMiddleLeft.spin(vex::fwd,lefts,vex::volt);
    driveFrontLeft.spin(vex::fwd,lefts,vex::volt);
  }
}

void intakeAndRollerFunc(){
  if(master.ButtonL1.pressing()){
    intakeAndRoller.spin(vex::fwd,80,vex::pct);    
  }else{
    intakeAndRoller.stop(vex::coast);
  }
  if(master.ButtonL2.pressing()){
  intakeAndRoller.spin(vex::fwd,-80,vex::pct);
  }else{
    intakeAndRoller.stop(vex::coast);
  }
}
//doing same thing but for the random port
bool extensionOnOff;
void extensionSwitch(){
  if(extensionOnOff){
    extensionOnOff = false;
  }else{
    extensionOnOff = true;
  }
}
void extensionFunc(float anglee, float delayPeriod){
  master.ButtonX.pressed(extensionSwitch);
  float originalPosition = extension.position(vex::deg);
  
  while(extensionOnOff){
    extension.spinToPosition(anglee, vex::deg,true);
    vex::task::sleep(5000);
    extension.spinToPosition(originalPosition, vex::deg,true);
  }
}