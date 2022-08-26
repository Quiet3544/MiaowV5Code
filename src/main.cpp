/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\18awdaha                                         */
/*    Created:      Fri Jul 01 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "functions.h"

void auton(){

}
void driver(){
  while (true){
    driveFunc();
    intakeFunc();
    shooterWheelFunc();
  }
}

int main() {
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);
  while(true){
    vex::task::sleep(100);
  }
}
