#include "main.h"

Auton::Odom::Odom() : currentPos({0, 0, 0}) {
    reset();
}

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

void Auton::Odom::toPosAbs(struct Position pos, enum Dir dir = forward, double speed = 127) {
    toPosRel({currentPos.x - pos.x, currentPos.y - pos.y, currentPos.r - pos.r}, dir, speed);
}

void Auton::Odom::toPosRel(struct Position target, enum Dir dir = forward, double speed = 127) {
    double tangle = atan(target.y/target.x) + target.x < 0 ? target.y < 0 ? -180 : 180 : 0;
    double tdistance = sqrt(pow(target.x, 2) + pow(target.y, 2));
    struct Position rdelta = {tdistance * cos(tangle), tdistance * sin(tangle), target.r};
    
}