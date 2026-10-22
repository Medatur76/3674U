/**
 * This file fixes a multi-definition error somehow some ima just roll with it
 */

#include "main.h"

pros::MotorGroup Hardware::left_motors({1, 2});
pros::MotorGroup Hardware::right_motors({3, 4});
pros::MotorGroup Hardware::cascade({5, -6});
pros::Rotation Hardware::cascadeSensor(7);
pros::Motor Hardware::claw(8);
bool Hardware::clawClosed = 0;
int Hardware::clawPositions[] = {-1,-1};