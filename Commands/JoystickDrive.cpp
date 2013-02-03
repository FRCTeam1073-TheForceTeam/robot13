#include "JoystickDrive.h"
#include "../Subsystems/DriveTrain.h"
JoystickDrive::JoystickDrive() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	cubicConst = .1;
}
// Called just before this Command runs the first time
void JoystickDrive::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void JoystickDrive::Execute() {
	float left = Robot::oi->getLeftStick()->GetY(GenericHID::kLeftHand);
	float right = -1* Robot::oi->getRightStick()->GetY(GenericHID::kRightHand);
	if (Robot::driveTrain->IsCubic()){ //cubic scale
		//printf("IsCubic true in Joystick Drive\n");
		left = (cubicConst*left)+(1-cubicConst)*(left*left*left);
		right = (cubicConst*right)+(1-cubicConst)*(right*right*right);
	}
		
	Robot::driveTrain->Move(left,right);
}
// Make this return true when this Command no longer needs to run execute()"
bool JoystickDrive::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void JoystickDrive::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickDrive::Interrupted() {
}
