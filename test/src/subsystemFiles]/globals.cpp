#include "main.h"
//(port,pros::E_MOTOR_GEARSET(06=600rpm,18=200rpm,36=100rpm)is Reversed?(bool))
//motor encoders(counts = raw value, degress, rotations)
//both fronts should be reversed
pros::Motor FrontLeftMotor(1, pros::E_MOTOR_GEARSET_36, true,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor FrontRightMotor(2,pros::E_MOTOR_GEARSET_36, true,pros:: E_MOTOR_ENCODER_COUNTS);
//front Motors

//Back Motors
pros::Motor BackLeftMotor(3, pros::E_MOTOR_GEARSET_36, false,pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor BackRightMotor(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

//intake momemto numero uno
pros::Motor Intake(5,pros::E_MOTOR_GEARSET_36,false, pros::E_MOTOR_ENCODER_ROTATION);

//Controller?
pros::Controller MainController (pros::E_CONTROLLER_MASTER);