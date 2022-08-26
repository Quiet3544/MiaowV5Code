#include "variables.h"

vex::competition Competition;
vex::controller master = vex::controller();
vex::brain Brain = vex::brain();

vex::motor driveBackRight = vex::motor(vex::PORT10);
vex::motor driveFrontRight = vex::motor(vex::PORT20);
vex::motor driveBackLeft = vex::motor(vex::PORT1);
vex::motor driveFrontLeft = vex::motor(vex::PORT11);

vex::motor intakeRight = vex::motor(vex::PORT19);
vex::motor intakeLeft = vex::motor(vex::PORT12);

vex::motor shooterWheel = vex::motor(vex::PORT18);
extern vex::pneumatics shooterGate;
vex::pneumatics shooterGate = vex::pneumatics(Brain.ThreeWirePort.A);