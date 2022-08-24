#include "autonFuncs.h"

///////////////////////////////////////////
//Brake functions
void brakeDrive(vex::brakeType braket = vex::coast){
  driveBackRight.stop(braket);
  driveFrontRight.stop(braket);
  driveBackLeft.stop(braket);
  driveFrontLeft.stop(braket);
}

void brakeRight(){
  driveBackRight.stop(vex::brake);
  driveFrontRight.stop(vex::brake);
}

void brakeLeft(){
  driveBackLeft.stop(vex::brake);
  driveFrontLeft.stop(vex::brake);
}
///////////////////////////////////////////

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
    driveFrontRight.vex::motor::spin(vex::fwd,rights,vex::volt);
    driveBackRight.vex::motor::spin(vex::fwd,rights,vex::volt);
  }
  if(master.Axis3.value() != 0){
    driveFrontLeft.vex::motor::spin(vex::fwd,lefts,vex::volt);
    driveBackLeft.vex::motor::spin(vex::fwd,lefts,vex::volt);
  }
}

bool intakeOnOff; // creating a toggle function for the intake
void intakeToggle(){
  if(intakeOnOff == false){
    intakeOnOff = true;
  }else{
    intakeOnOff = false;
  }
}
void intakeFunc(){
  master.ButtonRight.pressed(intakeToggle); // when the button is pressed it checks intakeToggle() and based on that stop or spin motors
  if(intakeOnOff == false){
    intakeRight.vex::motor::spin(vex::fwd,80,vex::pct);
    intakeLeft.vex::motor::spin(vex::fwd,80,vex::pct);
  }else{
    intakeRight.stop(vex::coast);
    intakeLeft.stop(vex::coast);
  }
}

//doing same thing but for the shooter
bool shooterWheelOnOff;
void shooterWheelToggle(){
  if(shooterWheelOnOff == false){
    shooterWheelOnOff = true;
  }else{
    shooterWheelOnOff = false;
  }
}

void shooterWheelFunc(){
  master.ButtonX.pressed(shooterWheelToggle);
  if(shooterWheelOnOff == true){
    shooterWheel.vex::motor::spin(vex::fwd,80,vex::pct);
  }else{
    shooterWheel.stop(vex::coast);
  }
}

