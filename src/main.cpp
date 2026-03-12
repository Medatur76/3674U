#include "main.h"

//Returns the smaller of the two params
int min(int x, int y) {
	return x < y ? x : y;
}

//Returns the larger of the two params
int max(int x, int y) {
	return x > y ? x : y;
}

//The index of the current selected auton in the list
int selected_auton = 0;
//A list of string representations for each auton
std::string autons[] = {"Empty Auton"};
/**
 * The required type for every auton function
 * Must:
 * 1. Return a void
 * 2. Take no params
 */
using auton_function = void(*)(void);
//A list of the auton functions that can be called come auton time
auton_function autonFuncs[] = {Auton::Empty::emptyAuton};

/**
 * Function call for when the left button is pressed on the lcd
 * 
 * Decreaments the selected_auton index while binding it to 0 as well as 
 * prints the currently selected auton to the screen again.
 */
void on_left_button() {
	pros::lcd::clear_line(2);
	//Prints the string representation located of an auton at index selected_auton - 1 or 0
	pros::lcd::set_text(2, autons[selected_auton = max(--selected_auton, 0)]);
}

/**
 * Function call for when the right button is pressed on the lcd
 * 
 * Increaments the selected_auton index while binding it to the highest 
 * possible value given the number of autons as well as prints the currently 
 * selected auton to the screen again.
 */
void on_right_button() {
	pros::lcd::clear_line(2);
	//Prints the string representation located of an auton at index selected_auton + 1 or the last object
	pros::lcd::set_text(2, autons[selected_auton = min(++selected_auton, (sizeof(autons) / sizeof(std::string)) - 1)]);
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello 3674U!");

	pros::lcd::register_btn0_cb(on_left_button);
	pros::lcd::register_btn2_cb(on_right_button);
	pros::lcd::set_text(2, selected_auton[autons]);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	autonFuncs[selected_auton]();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);


	while (true) {
		// Arcade control scheme
		int dir = master.get_analog(ANALOG_LEFT_Y);    // Gets amount forward/backward from left joystick
		int turn = master.get_analog(ANALOG_RIGHT_X);  // Gets the turn left/right from right joystick
		Hardware::left_motors.move(dir - turn);                      // Sets left motor voltage
		Hardware::right_motors.move(dir + turn);                     // Sets right motor voltage
		
		
		pros::delay(20);                               // Run for 20 ms then update
	}
}