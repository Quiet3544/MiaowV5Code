// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// ---- END VEXCODE CONFIGURED DEVICES ----
#include "functions.h"
using namespace vex;

void preauton(){
  backLiftSensor.setPosition(10, degrees);
  liftBack.setRotation(backLiftSensor.position(degrees),degrees);
  screenFunc();
}
void auton(){
  autonR();
}
void driver(){
  while (true){
    driveFunc();
    liftFourFunc();
    clawFunc();
    liftBackFunc();
    conveyaMove();
  }
}
int main() {
  Competition.autonomous(auton);
  Competition.drivercontrol(driver);
  preauton();
  while(true){
    task::sleep(100);
  }
}
