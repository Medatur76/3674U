/**
 * Contains all physical objects that the code will interact with
 */

//#define IMU

extern pros::MotorGroup left_motors;
extern pros::MotorGroup right_motors;

extern pros::MotorGroup cascade;
#define CASCADEMAXROTATION NULL
extern pros::Rotation cascadeSensor;

extern pros::Motor claw;
extern bool clawClosed;
extern int clawPositions[2];

#ifdef IMU
extern pros::Imu imu;
#else
extern pros::Rotation chassisL;
extern pros::Rotation chassisR;
#endif