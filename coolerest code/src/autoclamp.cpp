// custom/src/autoclamp.cpp
#include "main.h"
#include "autoclamp.h"
#include "rw-config.h"

static pros::Distance clampSensor(1);          // smart port 1

static const int  TRIGGER_MM    = 90;          // clamp when closer than this
static const int  CONFIRM_READS = 1;           // consecutive readings needed (3 x 10 ms)
static const bool CLAMP_VALUE   = false;        // solenoid value that closes the claw

static volatile bool enabled = false;          // off until you turn it on
static volatile bool clamped = false;

void autoclampEnable(bool on) {
  enabled = on;
  if (on) clamped = false;                     // re-arm for a fresh clamp
}

static void autoclampTask(void*) {
  int hits = 0;
  while (true) {
    if (enabled && !clamped) {
      int d = clampSensor.get();               // millimeters
      bool valid = (d != PROS_ERR && d > 0);
      if (valid && d < TRIGGER_MM) hits++;
      else hits = 0;
      if (hits >= CONFIRM_READS) {
        clamp.set_value(CLAMP_VALUE);
        clamped = true;
        hits = 0;
      }
    } else {
      hits = 0;
    }
    pros::delay(5);
  }
}

void autoclampStart() {                        // call once from initialize()
  static pros::Task t(autoclampTask, nullptr, "autoclamp");
}