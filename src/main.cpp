/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\                                                 */
/*    Created:      Fri Jul 01 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "autonomous.h" // contains all previous files

vex::competition Competition;

void preAuton(){
    extension.resetPosition();
}
void auton(){
  driveFwd();
  vex::task::sleep(1000);
  brakeDrive(vex::brake); 
  rollerTurnAuton();
  vex::task::sleep(500);
  intakeAndRoller.stop(vex::coast);
}
void driver(){
  while (true){
    preAuton();
    driveFunc();
    intakeAndRollerFunc();
    extensionFunc(90,5000); /* first number is to what degree (this can stretch beyond 360 degrees),
     second number is delay period (set to milliseconds. 1000 milliseconds = 1 second).*/
  }
}

int main() {
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);
  while(true){
    vex::task::sleep(100);
  }
}