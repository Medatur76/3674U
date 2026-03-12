/**
 * This file fixes a multi-definition error somehow some ima just roll with it
 */

#include "main.h"

pros::MotorGroup Hardware::left_motors({1, 2, 3});
pros::MotorGroup Hardware::right_motors({4, 5, 6});