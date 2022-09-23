#include "functions.h"
#include <vex.h>

// braking functions
void brakeDrive(vex::brakeType braket = vex::coast){
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
  double lefts = (master.Axis3.position()/100)*12.0; // using joystick function to make voltage value by getting it's position and diving by 100 then multiply by 12(maximum voltage) 
  double rights = (master.Axis2.position()/100)*12.0;

  if(master.Axis2.value() != 0){ // if joystick moves, then spin motors according to joystick's position.
    driveBackRight.vex::motor::spin(vex::fwd,rights,vex::volt);
    driveMiddleRight.vex::motor::spin(vex::fwd,rights,vex::volt);
    driveFrontRight.vex::motor::spin(vex::fwd,rights,vex::volt);
  }
  if(master.Axis3.value() != 0){
    driveBackLeft.vex::motor::spin(vex::fwd,lefts,vex::volt);
    driveMiddleLeft.vex::motor::spin(vex::fwd,lefts,vex::volt);
    driveFrontLeft.vex::motor::spin(vex::fwd,lefts,vex::volt);
  }
}
// creating a toggle function for the intake
bool intakeOnOff = false;
void intakeAndRollerSwitch(){
  if(intakeOnOff){
    intakeOnOff = false;
  }else{
    intakeOnOff = true;
  }
}
void intakeAndRollerFunc(){
  master.ButtonRight.pressed(intakeAndRollerSwitch); // when the button is pressed it checks intakeToggle() and based on that stop or spin motors
  if(intakeOnOff == true){
    intakeAndRoller.vex::motor::spin(vex::fwd,80,vex::pct);
  }else{
    intakeAndRoller.stop(vex::coast);
  }
}
//doing same thing but for the random port
bool randomPortOnOff;
void RandomPortSwitch(){
  if(randomPortOnOff){
    randomPortOnOff = false;
  }else{
    randomPortOnOff = true;
  }
}
void randomPortFunc(float anglee, float delayPeriod){
  master.ButtonX.pressed(RandomPortSwitch);
  randomPort.vex::motor::resetRotation();
  float originalPosition = randomPort.vex::motor::position(vex::deg);
  
  if(randomPortOnOff == true){
    randomPort.spinToPosition(anglee, vex::deg,true);
    vex::task::sleep(delayPeriod);
    randomPort.spinToPosition(originalPosition, vex::deg,true);
  }else{
    randomPort.stop(vex::coast);
  }
}

///////////////////////////////////////////
// auton functions
void driveFwd(){
  driveBackLeft.spin(vex::fwd,80,vex::pct);
  driveBackLeft.spin(vex::fwd,80,vex::pct);
  driveFrontRight.spin(vex::fwd,80,vex::pct);
  driveBackRight.spin(vex::fwd,80,vex::pct);
}

void driveBwd(){
  driveBackLeft.spin(vex::fwd,-80,vex::pct);
  driveBackLeft.spin(vex::fwd,-80,vex::pct);
  driveFrontRight.spin(vex::fwd,-80,vex::pct);
  driveBackRight.spin(vex::fwd,-80,vex::pct);
}
void driveTurnR(){
  driveBackLeft.spin(vex::fwd,80,vex::pct);
  driveBackLeft.spin(vex::fwd,80,vex::pct);
  driveFrontRight.spin(vex::fwd,-80,vex::pct);
  driveBackRight.spin(vex::fwd,-80,vex::pct);
}
void driveTurnL(){
  driveBackLeft.spin(vex::fwd,-80,vex::pct);
  driveBackLeft.spin(vex::fwd,-80,vex::pct);
  driveFrontRight.spin(vex::fwd,80,vex::pct);
  driveBackRight.spin(vex::fwd,80,vex::pct);
}
///////////////////////////////////////////