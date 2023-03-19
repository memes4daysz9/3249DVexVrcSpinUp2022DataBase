#include "main.h"
#include "drive.hpp"
#include "drive.cpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
float curve = 0.3;

void on_center_button() {
	int howManyPressed
	static bool pressed = false;
	pressed = !pressed;
	if (pressed && howManyPressed == 1) {
		curve = 0.5;
		pros::lcd::set_text(2, "curve now at 0.5");
		howManyPressed + 1;
	} else if (pressed && howManyPressed == 2){
		curve = 0.7;
		pros::lcd::set_text(2, "curve now at 0.7"); // the cylcling system that whenever you touch the screen or button, itll change the curve for imeadiate curve change to see what the driver likes
		howManyPressed + 1;
	} else if (pressed && howManyPressed == 3){
		curve = 1;
		pros::lcd::set_text(2, "curve now at 1");
		howManyPressed + 1;
	} else if (pressed && howManyPressed == 4){
		curve = 0.3;
		pros::lcd::set_text(2, "curve now at 0.3");
		howManyPressed = 1;
	}
	
	
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hi! tap the screen to get different curves! (base is at 0.3)");

	pros::lcd::register_btn1_cb(on_center_button);
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
void autonomous() {}

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

	
	float VerticalPower;
    float StrafePower;
    float HorizontalPower;
    
	float PowerCurveVertical;
	float PowerCurveStrafe;
	float PowerCurveRotation;

    while (true){
		
		int cycle = 1

		if (MainController.get_digital_new_press(X) && Cycle = 1){
			MainController.clear;
			curve = 0.5;
			MainController.set_text(0,0, "curve is now 0.5");
			cycle + 1;
		} else if (MainController.get_digital_new_press(X) && Cycle = 2){
			MainController.clear;
			curve = 0.7;
			MainController.set_text(0,0, "curve is now 0.7");
			cycle + 1;
		} else if (MainController.get_digital_new_press(X) && Cycle = 3){ // same thing as above but this is for the controller, making it faster to  compare two modes
			MainController.clear;
			curve = 1;
			MainController.set_text(0,0, "curve is now 1");
			cycle + 1;
		} else if (MainController.get_digital_new_press(X) && Cycle = 4){
			MainController.clear;
			curve = 0.3;
			MainController.set_text(0,0, "curve is now 0.3");
			cycle = 1;
		}


        VerticalPower = MainController.get_analog(E_CONTROLLER_ANALOG_LEFT_Y) * PowerCurveVertical;
        StrafePower = MainController.get_analog(E_CONTROLLER_ANALOG_LEFT_X) * PowerCurveStrafe; // the way i did this might start up delayed at first movement but will stop imeadiatly after controller stops giving input
        HorizontalPower = MainController.get_analog(E_CONTROLLER_ANALOG_RIGHT_X)* PowerCurveRotation;

		PowerCurveVertical =  100((1-curve)VerticalPower / 100 + curve (VerticalPower/100)5);
		PowerCurveStrafe =  100((1-curve)StrafePower / 100 + curve (StrafePower/100)5); // sets a curve for all the joystick axises.... makes the robot move smoother 
		PowerCurveRotation = 100((1-curve)HorizontalPower / 100 + curve (HorizontalPower/100)5); 

		


        FrontLeftMotor.move(VerticalPower + StrafePower + HorizontalPower);
        BackLeftMotor.move(VerticalPower - StrafePower + HorizontalPower);
        FrontRightMotor.move(VerticalPower - StrafePower - HorizontalPower);
        BackRightMotor.move(VerticalPower + StrafePower - HorizontalPower);


        pros::delay(50);
    }
		
		

		pros::delay(10);


		//this controlls all motors
	
	
}
