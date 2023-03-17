#include "main.h"


int main(){
    //driver controll functions
    void setDriverMotors(){
        FrontLeftMotor = 0;
        FrontRightMotor = 0;
        BackLeftMotor = 0;
        BackRightMotor = 0;
    }

  


    float VerticalPower;
    float StrafePower;
    float HorizontalPower;
    float speedCurve[5] = {0.1, 0.3, 0.5, 0.75,1.0};

    while (true){

        VerticalPower = MainController.get_analog(E_CONTROLLER_ANALOG_LEFT_Y);
        StrafePower = MainController.get_analog(E_CONTROLLER_ANALOG_LEFT_X);
        HorizontalPower = MainController.get_analog(E_CONTROLLER_ANALOG_RIGHT_X);

        FrontLeftMotor.move((MainController.get_analog(E_CONTROLLER_ANALOG_LEFT_Y)         );)


        pros::delay(50);
    }




}


