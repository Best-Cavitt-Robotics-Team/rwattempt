#include "autoclamp.h"
#include "pros/rtos.h"
#include "rw-config.h"
#include "paths.h"
#include "rw/path.h"
#include "api.h"
#include "autoclamp.h" 

// IMPORTANT: Remember to add respective function declarations to include/rw-config.h
// Then add each routine to the auton selector with addAuton() in runPreAutonomous() (src/rw-user.cpp)
// Format: returnType functionName() { code }

void cascadeUp(int time){
    leftCascade.move_velocity(600);
    rightCascade.move_velocity(-600);
    pros::delay(time);
    leftCascade.move_velocity(0);
    rightCascade.move_velocity(0);
}

void cascadeDown(int time){
    leftCascade.move_velocity(-600);
    rightCascade.move_velocity(600);
    pros::delay(time);
    leftCascade.move_velocity(0);
    rightCascade.move_velocity(0);
}

void exampleAuton() {
  // Use this for tuning linear and turn pid
  driveTo(60, 3000);
  turnToAngle(90, 2000);
  turnToAngle(135, 2000);
  turnToAngle(150, 2000);
  turnToAngle(160, 2000);
  turnToAngle(165, 2000);
  turnToAngle(0, 2000);
  driveTo(-60, 3000);
}

void exampleAuton2() {
  moveToPoint(24, 24, 1, 2000, false);
  moveToPoint(48, 48, 1, 2000, true);
  moveToPoint(24, 24, -1, 2000, true);
  moveToPoint(0, 0, 1, 2000, true);
  correct_angle = 0;
  driveTo(24, 2000, false, 8);
  turnToAngle(90, 800, false);
  turnToAngle(180, 800, true);
}

void testAuton() {

  right_chassis.set_voltage_limit(12000*0.37);
  // setPose(0,0,0);

  // driveProfiled(20.5,2000, true, 80);

  // pros::c::delay(17000);

  // Path
  Path firstL = pathFromJerryIO(L1Lemlib_txt);

  Path straightL = pathFromJerryIO(L1Straight_txt);

  Path repeat1 = pathFromJerryIO(repeatA_txt);

  Path repeat2 = pathFromJerryIO(repeatB_txt);

  setPose(-7,-62,180);

  // moveToPoint(-7,-50,-1,1500);
  // turnProfiled(90,750);
  // driveProfiled(-10,1500)

  // Path

// Path

// Path

  // Path

// Path
cascadeUp(400);

driveProfiled(-10.5, 2000);
turnProfiled(90, 1000);
driveProfiled(-17.5, 2000);

cascadeDown(200);
clamp.set_value(true);

turnProfiled(90.955, 1000);
driveProfiled(18, 2000);

pros::delay(100);

turnProfiled(134.204, 1000);

autoclampEnable(true);

driveProfiled(-25.8, 2000, true, 60);

cascadeUp(900);

autoclampEnable(false);

turnProfiled(16.592, 1000);
driveProfiled(-15.754, 2000);

cascadeDown(500);
clamp.set_value(true);

turnProfiled(0,1000);
driveProfiled(17.253, 2000);
turnProfiled(46.332, 1000);

autoclampEnable(true);
driveProfiled(-25.934, 2000, true, 40);

cascadeUp(1000);
autoclampEnable(false);

turnProfiled(285.642, 1000);
driveProfiled(-14.19, 2000);

cascadeDown(200);
clamp.set_value(true);

turnProfiled(270,1000);
driveProfiled(16.672 - 3.5, 2000, true, 80);

cascadeDown(400);

turnProfiled(180, 1000);
driveProfiled(12.024 - 3.5, 2000, true, 80);
turnProfiled(90, 1000);

autoclampEnable(true);//

driveProfiled(-18.312 + 3.5, 2000, true, 80);
turnProfiled(90, 1000);

// clamp.set_value(false);
pros::delay(100);
cascadeUp(50);
autoclampEnable(false);//
pros::delay(600);

driveProfiled(18.585 - 3.5, 2000, true, 80);
turnProfiled(180, 1000);
driveProfiled(-13.751 + 3.5, 2000, true, 80);
turnProfiled(270, 1000);

cascadeUp(1000);

driveProfiled(-16.397 + 3.5, 2000, true, 80);
turnProfiled(270, 1000);

cascadeDown(300);
clamp.set_value(true);

driveProfiled(17.217 - 3.5, 2000, true, 80);
turnProfiled(46.695, 1000);

driveProfiled(32.672 - 3.5, 2000, true, 80);
turnProfiled(133.62, 1000);

driveProfiled(32.087 - 3.5, 2000, true, 80);
turnProfiled(180, 1000);

driveProfiled(18.583 - 3.5, 2000, true, 50);
turnProfiled(180, 1000);

driveProfiled(-9.842 + 3.5, 2000, true, 80);
turnProfiled(180, 1000);

driveProfiled(10.115 - 3.5, 2000, true, 50);
turnProfiled(180, 1000);

driveProfiled(-53.017 + 3.5, 2000, true, 80);
turnProfiled(180, 1000);




  // followPath(straightL, 5000,true,true,15,8);

  // followPathRamsete(square, 15000,false,true,20);

  //REPEAT
  // setPose(-62,-58,90);

  // followPath(repeat1, 5000,false,true,15,6); //20,8

  // turnProfiled(270,1000);

  // followPath(repeat2, 5000,true,true,15,6);

  // turnToAngle(90,1000);

  // moveToPoint(0,24,1,1000);
// setPose(-37,-8,0);

// Path path2 = pathFromJerryIO(path2_text);

// followPath(path2, 5000);

}

void newSkills() {

  cascadeUp(400);
  driveProfiled(-16.67, 2000, true, 80);
  turnProfiled(90, 1000);
  driveProfiled(-16.67, 2000, true, 80);
  turnProfiled(90, 1000);
  

  driveProfiled(16.397, 2000, true, 80);
  turnProfiled(315.818, 1000);
  driveProfiled(27.056, 2000, true, 80);
  turnProfiled(315, 1000);

}
/*
 * asyncExample
 * Shows background motions: start a move, run the intake while it drives, and stop it early with a sensor.
 */
void asyncExample() {
  setPose(0, 0, 0);

  // Start driving in the background, then start the intake 12 inches into the move
  runAsync([]{ moveToPoint(0, 48, 1, 3000); });
  waitUntilTraveled(12);
  intake_motor.move_voltage(12000);

  // Stop the move early once the intake sensor sees an object
  while (isMotionRunning() && intake_distance.get() >= 50) {
    pros::delay(5);
  }
  cancelMotion();
  waitForMotion();
  intake_motor.brake();

  // Turn around and drive back
  runAsync([]{
    turnToAngle(180, 1500);
    moveToPoint(0, 0, 1, 3000);
  });
  waitForMotion();
}

/*
 * pathExample
 * Drives a smooth S-curve with pure pursuit, then backs along it with RAMSETE.
 * Paths use field coordinates, so the auton starts with setPose().
 */
void pathExample() {
  setPose(-36, -60, 0);
  Path out = pathFromPoints({{-36, -60}, {-36, -32}, {-12, -22}, {12, -30}, {34, -24}});
  followPath(out, 5000);
  Path back = pathFromPoints({{34, -24}, {12, -30}, {-12, -22}, {-36, -32}, {-36, -52}});
  followPathRamsete(back, 5000, true);
}

/*
 * profiledExample
 * Straight drives and turns with motion profiles: they speed up and slow down smoothly.
 */
void profiledExample() {
  driveProfiled(36, 3000);
  turnProfiled(90, 2000);
  driveProfiled(24, 3000);
  turnProfiled(0, 2000);
  driveProfiled(-36, 3000);
}
