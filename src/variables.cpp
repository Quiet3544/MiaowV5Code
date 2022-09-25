#include "variables.h"

//globals
float driveVelocity = 80; // velocity used for driver controller functions
float autonVelocity = 80; // velocity used for auton functions
//input
vex::controller master = vex::controller();
vex::brain Brain = vex::brain();

//drive
// to reverse motors, put "true" after port(n)
// for example: vex::motor(vex::PORT1, true);
vex::motor driveBackRight = vex::motor(vex::PORT1,true);
vex::motor driveMiddleRight = vex::motor(vex::PORT11,true);
vex::motor driveFrontRight = vex::motor(vex::PORT2,true);

vex::motor driveBackLeft = vex::motor(vex::PORT10);
vex::motor driveMiddleLeft = vex::motor(vex::PORT20);
vex::motor driveFrontLeft = vex::motor(vex::PORT9);

//misc
vex::motor intakeAndRoller = vex::motor(vex::PORT12);

vex::motor cata = vex::motor(vex::PORT6);
vex::motor extension = vex::motor(vex::PORT13);