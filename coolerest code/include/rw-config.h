#pragma once
#include "rw/api.h"
#include "api.h"

// Your own devices (besides the ones RW uses, which are in rw/devices.h), defined in src/rw-config.cpp
extern pros::Motor intake_motor;
extern pros::Distance intake_distance;
extern pros::Motor leftCascade;
extern pros::Motor rightCascade;

extern pros::adi::DigitalOut clamp;

// Your autonomous routines (src/rw-autons.cpp). Add each one to the selector in src/rw-user.cpp
void exampleAuton();
void exampleAuton2();
void asyncExample();
void pathExample();
void profiledExample();
void testAuton();
void newSkills();

// Called from src/main.cpp (src/rw-user.cpp)
void runPreAutonomous();
void runAutonomous();
void runDriver();
