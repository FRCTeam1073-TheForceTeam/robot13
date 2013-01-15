#include "DriveTrain.h"
#include "../Robotmap.h"
#include "../Commands/JoystickDrive.h"
#include "../OI.h"
#include "GenericHID.h"
//#define  DEBUG 
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
	left = Robot::oi->getLeftStick();
	right = Robot::oi->getRightStick();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftDriveMotor = RobotMap::driveTrainLeftDriveMotor;
	rightDriveMotor = RobotMap::driveTrainRightDriveMotor;
	driveTrainGyro = RobotMap::driveTrainDriveTrainGyro;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new JoystickDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveTrain::Move(){ 
#ifdef DEBUG
	printf("calling move\n");
#endif
	//writes y-value of joystick to jag 
	leftDriveMotor->Set(left->GetY(GenericHID::kLeftHand));
	rightDriveMotor->Set(-1 * right->GetY(GenericHID::kRightHand));
#ifdef DEBUG	
	printf("Left Y: %f  Right Y: %f\n", left->GetY(GenericHID::kLeftHand), right->GetY(GenericHID::kLeftHand));
	printf("Left M: %f  Right M: %f\n", leftDriveMotor->Get(), rightDriveMotor->Get());
#endif
}
float DriveTrain::GetDriveVoltage(bool left){return left ? leftDriveMotor->GetBusVoltage() : rightDriveMotor->GetBusVoltage();}
float DriveTrain::GetDriveCurrent(bool left){return left ? leftDriveMotor->GetOutputCurrent() : rightDriveMotor->GetOutputCurrent();}
float DriveTrain::GetDriveSpeed(bool left){return left ? leftDriveMotor->GetSpeed() : rightDriveMotor->GetSpeed();}
float DriveTrain::GetGyroAngle() {return driveTrainGyro->GetAngle();}