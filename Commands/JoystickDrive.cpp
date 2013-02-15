#include "JoystickDrive.h"
#include "../Subsystems/DriveTrain.h"
JoystickDrive::JoystickDrive() {Requires(Robot::driveTrain);}
void JoystickDrive::Initialize() {}
void JoystickDrive::Execute() {
	float left = Robot::oi->getLeftStick()->GetY();
	float right= Robot::oi->getRightStick()->GetY();
	Robot::driveTrain->Move(left,right);
}
bool JoystickDrive::IsFinished(){return false;}
void JoystickDrive::End() {}
void JoystickDrive::Interrupted() {}
