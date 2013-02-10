#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"
#include "../OI.h"
#include "GenericHID.h"
//#define  DEBUGDRIVETRAIN 
#define WHEEL_SIZE 7
#define TICKS_PER_REV 1440
#define PI 3.14159
DriveTrain::DriveTrain() : Subsystem("DriveTrain"){
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftMotor = RobotMap::driveTrainLeftMotor;
	rightMotor = RobotMap::driveTrainRightMotor;
	gyro = RobotMap::driveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	isCubicOn = false;
}
    
void DriveTrain::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new JoystickDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
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
