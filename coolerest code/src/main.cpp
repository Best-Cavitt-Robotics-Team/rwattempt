#include "main.h"
#include "rw-config.h"
#include "autoclamp.h" 

void initialize() { runPreAutonomous(); autoclampStart();}
void disabled() {}
void competition_initialize() {}
void autonomous() { runAutonomous(); }
void opcontrol() { runDriver(); }