#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"
#include "../OI.h"
#include "GenericHID.h"
#define  DEBUGDRIVETRAIN 
#define WHEEL_SIZE 7
#define TICKS_PER_REV 1440
#define PI 3.14159
DriveTrain::DriveTrain() : Subsystem("DriveTrain"){
	
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotor = RobotMap::driveTrainLeftMotor;
	rightMotor = RobotMap::driveTrainRightMotor;
	gyro = RobotMap::driveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	isTurboOn = false;
	isCubicOn = false;
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	//SetDefaultCommand(new JoystickDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::TurboOnOff(bool on){
	isTurboOn = on;
}
void DriveTrain::CubicOnOff(bool on){
	isCubicOn = on;
}
bool DriveTrain::IsCubic(){
	return isCubicOn;
}
void DriveTrain::Move(float left, float right){ 
#ifdef DEBUGDRIVETRAIN
	printf("calling move\n");
#endif
	//checks for turbo mode
	if(isTurboOn){
		leftMotor->Set(left != 0 ? (left < 0 ? -1 : 1) : 0);
		rightMotor->Set(right != 0 ? (right < 0 ? -1 : 1) : 0);
	}
	if (left < .05 && left > -.05){
		left = 0;
	}
	if (right < .05 && right > -.05){
		right = 0;
	}
	//writes y-value of joystick to jag 
	leftMotor->Set(left);
	rightMotor->Set(right);
#ifdef DEBUGDRIVETRAIN	
	printf("Left Y: %f  Right Y: %f\n", left, right);
	printf("Left M: %f  Right M: %f\n", leftMotor->Get(), rightMotor->Get());
#endif
}
void DriveTrain::GetPosition(float &left,float &right){
	left=TicksToInches(leftMotor->Get());
	right=TicksToInches(rightMotor->Get());
}
float DriveTrain::TicksToInches (float ticks){
	return 2*PI*(WHEEL_SIZE/2)*ticks;
}
float DriveTrain::GetGyroAngle() {
	return gyro->GetAngle();
}
