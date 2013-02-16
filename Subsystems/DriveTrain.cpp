#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"
#include "../OI.h"
#include "GenericHID.h"
//#define  DEBUGDRIVETRAIN 
#define WHEEL_SIZE 7
#define TICKS_PER_REV 1440
#define INCHES_PER_TICK 0.022
DriveTrain::DriveTrain() : Subsystem("DriveTrain"){
	leftMotor = RobotMap::driveTrainLeftMotor;
	rightMotor = RobotMap::driveTrainRightMotor;
	gyro = RobotMap::driveTrainGyro;
	//ConfigureJaguarEncoder(leftMotor);
	//ConfigureJaguarEncoder(rightMotor);
#ifdef ADD_SECONDARY_DRIVE 
	leftMotorSecondary = RobotMap::driveTrainLeftMotorSecondary;
	rightMotorSecondary = RobotMap::driveTrainRightMotorSecondary;
#endif
}   
void DriveTrain::InitDefaultCommand() {
	//if (Robot::GetWhichRobot() != Robot::libra)
	SetDefaultCommand(new JoystickDrive());//cant drive mecanum with this code!
}
void DriveTrain::Move(float left, float right){ 
#ifdef DEBUGDRIVETRAIN
	printf("calling move\n");
#endif
	//printf("Left: %f Right: %f\n", left, right);
	leftMotor->Set(left);
	rightMotor->Set(right);
#ifdef ADD_SECONDARY_DRIVE
	leftMotorSecondary->Set(left);
	rightMotorSecondary->Set(right);
#endif 
#ifdef DEBUGDRIVETRAIN	
	printf("Left Y: %f  Right Y: %f\n", left, right);
	printf("Left M: %f  Right M: %f\n", leftMotor->Get(), rightMotor->Get());
#endif
	SmartDashboard::PutNumber("Right Drive Encoder", rightMotor->GetSpeed());
	//printf("Right Motor Speed %f\n", rightMotor->GetSpeed());
	SmartDashboard::PutNumber("Left Drive Encoder", leftMotor->GetSpeed());
	//printf("Left Motor Speed %f\n", leftMotor->GetSpeed());
	SmartDashboard::PutNumber("Gyro Angle", gyro->GetAngle());
	//printf("Gyro Angle %f\n", GetGyroAngleDegrees());
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
