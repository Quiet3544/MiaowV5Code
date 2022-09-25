#include "autonomous.h"


void driveFwd(){
  driveBackLeft.spin(vex::fwd,autonVelocity,vex::pct);
  driveBackLeft.spin(vex::fwd,autonVelocity,vex::pct);
  driveFrontRight.spin(vex::fwd,autonVelocity,vex::pct);
  driveBackRight.spin(vex::fwd,autonVelocity,vex::pct);
}
void driveBwd(){
  driveBackLeft.spin(vex::fwd,-autonVelocity,vex::pct);
  driveBackLeft.spin(vex::fwd,-autonVelocity,vex::pct);
  driveFrontRight.spin(vex::fwd,-autonVelocity,vex::pct);
  driveBackRight.spin(vex::fwd,-autonVelocity,vex::pct);
}
void driveTurnR(){
  driveBackLeft.spin(vex::fwd,autonVelocity,vex::pct);
  driveBackLeft.spin(vex::fwd,autonVelocity,vex::pct);
  driveFrontRight.spin(vex::fwd,-autonVelocity,vex::pct);
  driveBackRight.spin(vex::fwd,-autonVelocity,vex::pct);
}
void driveTurnL(){
  driveBackLeft.spin(vex::fwd,-autonVelocity,vex::pct);
  driveBackLeft.spin(vex::fwd,-autonVelocity,vex::pct);
  driveFrontRight.spin(vex::fwd,autonVelocity,vex::pct);
  driveBackRight.spin(vex::fwd,autonVelocity,vex::pct);
}
void rollerTurnAuton(){
  intakeAndRoller.spin(vex::fwd,autonVelocity,vex::pct);
}