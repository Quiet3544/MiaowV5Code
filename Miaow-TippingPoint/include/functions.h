#include "motors.h"
using namespace vex;

void brakeDrive(brakeType braket =coast){
  leftB.stop(braket);
  leftF.stop(braket);
  rightF.stop(braket);
  rightB.stop(braket);
}

void brakeRt(){
  rightF.stop(brake);
  rightB.stop(brake);
}

void brakeLf(){
  leftF.stop(brake);
  leftB.stop(brake);
}


void driveFunc(){
  if(master.Axis2.value() == 0){
    brakeRt();
  }
  if(master.Axis3.value() == 0){
    brakeLf();
  }
  int lefts = master.Axis3.value();
  int rights = master.Axis2.value();
  if(master.Axis2.value() != 0){
    rightF.spin(fwd,rights,pct);
    rightB.spin(fwd,rights,pct);
  }
  if(master.Axis3.value() != 0){
    leftF.spin(fwd,lefts,pct);
    leftB.spin(fwd,lefts,pct);
  }
}
void liftFourFunc(){
  if(master.ButtonL1.pressing()){
    liftFour.spin(reverse,speed,pct);
  }
  else if(master.ButtonL2.pressing()){
    liftFour.spin(fwd,speed,pct);
  }
  else{
    liftFour.stop(brake);
  }
}
void liftBackFunc(){
  if(master.ButtonUp.pressing() && backLiftSensor.position(degrees)>5){
    liftBack.spin(fwd,speed,pct);
  }
  else if(master.ButtonDown.pressing() && backLiftSensor.position(degrees)<650){
    liftBack.spin(reverse,speed,pct);
  }
  else {
  liftBack.stop(hold);
  }
}
void clawFunc(){
  if(master.ButtonR1.pressing()){
    claw.spin(reverse,speed,pct);
  }
  else if(master.ButtonR2.pressing()){
    claw.spin(fwd,speed,pct);
  }

  else {
  claw.stop(brake);
  }
}


int go = 0;
bool toggle;
void switchh(){
  if(go == 0){
    if(toggle){
      toggle = false;
    }
    else{
      toggle = true;
    }
    go += 1;
  }
}
void bounc(){
  go = 0;
}
void conveyaMove(){
  master.ButtonRight.pressed(switchh);
  master.ButtonRight.released(bounc);
  if(toggle){
    conveya.spin(fwd,80,pct);
  }
  else if(master.ButtonLeft.pressing()){
    conveya.spin(reverse,80,pct);
  }
  else{
    conveya.stop(coast);
  }
}



void screenFunc(){
  master.Screen.clearScreen();
  while(true){
    master.Screen.clearLine();
   master.Screen.print("Angle: ");
   master.Screen.print(backLiftSensor.position(degrees));
  }
}
// autonomous functions

void driveFwd(){
  leftB.spin(fwd,speed,pct);
  leftF.spin(fwd,speed,pct);
  rightF.spin(fwd,speed,pct);
  rightB.spin(fwd,speed,pct);
}

void driveBwd(){
  leftB.spin(fwd,-speed,pct);
  leftF.spin(fwd,-speed,pct);
  rightF.spin(fwd,-speed,pct);
  rightB.spin(fwd,-speed,pct);
}
void driveTurnR(){
  leftB.spin(fwd,speed,pct);
  leftF.spin(fwd,speed,pct);
  rightF.spin(fwd,-speed,pct);
  rightB.spin(fwd,-speed,pct);
}
void driveTurnL(){
  leftB.spin(fwd,-speed,pct);
  leftF.spin(fwd,-speed,pct);
  rightF.spin(fwd,speed,pct);
  rightB.spin(fwd,speed,pct);
}

void liftBackHeight(int anglee){
  liftBack.spinToPosition(anglee, degrees, true);
}
void autonR(){
  driveFwd();
  task::sleep(1450);
  brakeDrive();
  claw.spin(fwd,80,pct);
  task::sleep(300);
  driveBwd();
  task::sleep(300);
  driveTurnL();
  task::sleep(400);
  brakeDrive(brake);
  liftBackHeight(-650);
  driveBwd();
  task::sleep(700);
  brakeDrive();
  liftBackHeight(10);
  liftFour.spin(fwd,-80,pct);
  task::sleep(500);
  conveya.spin(fwd,80,pct);
  task::sleep(5000);
  conveya.setBrake(brake);
  liftFour.spin(fwd,80,pct);
  task::sleep(3000);
  liftFour.setBrake(brake);
}
void autonL(){
  driveFwd();
  task::sleep(1550);
  brakeDrive();
  claw.spin(fwd,80,pct);
  task::sleep(300);
  driveBwd();
  task::sleep(1400);
  brakeDrive();

}
