#include "variables.h"

//input
vex::competition Competition;
vex::controller master = vex::controller();
vex::brain Brain = vex::brain();

//drive
// to reverse motors, put "true" after port(n)
// for example: vex::motor(vex::PORT1, true);
vex::motor driveBackRight = vex::motor(vex::PORT1);
vex::motor driveMiddleRight = vex::motor(vex::PORT11);
vex::motor driveFrontRight = vex::motor(vex::PORT2);

vex::motor driveBackLeft = vex::motor(vex::PORT10);
vex::motor driveMiddleLeft = vex::motor(vex::PORT20);
vex::motor driveFrontLeft = vex::motor(vex::PORT9);

//misc
vex::motor intakeAndRoller = vex::motor(vex::PORT19);

vex::motor cata = vex::motor(vex::PORT6);
vex::motor randomPort = vex::motor(vex::PORT7);