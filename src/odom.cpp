#include "main.h"

Auton::Odom::Odom(struct Position pos) : currentPos(pos) {
    reset();
}

void Auton::Odom::reset() {
#ifdef IMU
    Hardware::imu.reset(true);
#else
    Hardware::chassisL.reset();
    Hardware::chassisR.reset();
#endif
}