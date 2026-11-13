/**
 * This file holds all auton related code that needs to be spread across multiple files.
 * This includes but is not limited to:
 * 1. Chassis objects
 * 2. Odometry objects
 * 3. Auton functions
 */

enum Dir {
    reverse = -1,
    forward = 1
};

class Odom {
    struct Position {
        double x;
        double y;
        double r;
    };

    private:
        struct Position currentPos;

    public:
        Odom();
        Odom(struct Position);

        void reset();

        void toPosAbs(struct Position, enum Dir = forward, double = 127);
        void toPosRel(struct Position, enum Dir = forward, double = 127);
    
        void spin(double, double = 127);
        void spinTo(double, double = 127);
};

//Example of how an auton should be defined
class Empty {
    private:
        //Any auton-specific variables can be placed here
        //Keep in mind that these have to be static
    public:
        static void emptyAuton();
};

class Rush {
    public:
        static void right();
        static void left();
};