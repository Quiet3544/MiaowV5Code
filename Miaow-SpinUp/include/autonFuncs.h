#include "variables.h"
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