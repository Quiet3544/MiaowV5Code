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

// to change motors colour/ration, put ",vex::gearSetting::ratio[desired rato]"
// for example: vex::motor(vex::PORT1,,vex::gearSetting::ratio6_1);
vex::motor driveBackRight = vex::motor(vex::PORT1,vex::gearSetting::ratio6_1,true);
vex::motor driveMiddleRight = vex::motor(vex::PORT11,vex::gearSetting::ratio6_1,true);
vex::motor driveFrontRight = vex::motor(vex::PORT2,vex::gearSetting::ratio6_1,true);

vex::motor driveBackLeft = vex::motor(vex::PORT10,vex::gearSetting::ratio6_1);
vex::motor driveMiddleLeft = vex::motor(vex::PORT20,vex::gearSetting::ratio6_1);
vex::motor driveFrontLeft = vex::motor(vex::PORT9,vex::gearSetting::ratio6_1);

//misc
vex::motor intakeAndRoller = vex::motor(vex::PORT12);

vex::motor expansion = vex::motor(vex::PORT13,vex::gearSetting::ratio36_1);