#include "vex.h"
#include <iostream>
using namespace vex;

motor liftFour = motor(PORT1,gearSetting::ratio36_1, true);
motor claw = motor(PORT2,gearSetting::ratio36_1);
motor liftBack = motor(PORT13,gearSetting::ratio36_1);
motor rightF = motor(PORT19, true);
motor rightB = motor(PORT20, true);
motor conveya = motor(PORT14,gearSetting::ratio36_1, true);
motor leftB = motor(PORT11);
motor leftF = motor(PORT12);

rotation backLiftSensor = rotation(PORT10);

controller master = controller();
brain Brain = brain();
competition Competition;
int speed = 80;