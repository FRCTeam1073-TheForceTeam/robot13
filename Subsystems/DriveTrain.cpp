#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"
#include "../OI.h"
#include "GenericHID.h"
#define WHEEL_SIZE 7
#define TICKS_PER_REV 1440
#define INCHES_PER_TICK 0.022

//#define DEBUG_DATA

DriveTrain::DriveTrain() : Subsystem("DriveTrain"){
	leftMotor = RobotMap::driveTrainLeftMotor;
	rightMotor = RobotMap::driveTrainRightMotor;
	gyro = RobotMap::driveTrainGyro;
#ifdef ADD_SECONDARY_DRIVE 
	secondaryLeftMotor = RobotMap::driveTrainSecondaryLeftMotor;
	secondaryRightMotor = RobotMap::driveTrainSecondaryRightMotor;
#endif
}   
void DriveTrain::InitDefaultCommand() {
	if (Robot::GetWhichRobot() != Robot::libra)
	SetDefaultCommand(new JoystickDrive());//cant drive mecanum with this code!
}
void DriveTrain::Move(float left, float right){ 
	//printf("Left: %f Right: %f\n", left, right);
	leftMotor->Set(left);
	rightMotor->Set(right);
#ifdef ADD_SECONDARY_DRIVE
	secondaryLeftMotor->Set(left);
	secondaryRightMotor->Set(right);
#endif
	
#ifdef DEBUG_DATA
	SmartDashboard::PutNumber("Right Drive Encoder", rightMotor->GetSpeed());
	SmartDashboard::PutNumber("Left Drive Encoder", leftMotor->GetSpeed());
	SmartDashboard::PutNumber("Gyro Angle", gyro->GetAngle());
	//printf("Gyro Angle %f\n", gyro->GetAngle());
#endif 
}
void DriveTrain::Stop() {Move(0.0f, 0.0f);}
void DriveTrain::GetPosition(float &left,float &right){
	left = TicksToInches(leftMotor->GetSpeed());
	right = TicksToInches(rightMotor->GetSpeed());
}
float DriveTrain::TicksToInches (float ticks){
//	return 2*PI*(WHEEL_SIZE/2)*ticks;
	return ticks*INCHES_PER_TICK;
}
