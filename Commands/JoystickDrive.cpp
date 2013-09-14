#include "JoystickDrive.h"
#include "../Subsystems/DriveTrain.h"
JoystickDrive::JoystickDrive() {Requires(Robot::driveTrain);}
void JoystickDrive::Initialize() {}
void JoystickDrive::Execute() {
	/*printf("axis 1 %f\n", Robot::oi->getXbox()->GetRawAxis(1));
	printf("axis 2 %f\n", Robot::oi->getXbox()->GetRawAxis(2));
	printf("axis 3 %f\n", Robot::oi->getXbox()->GetRawAxis(3));
	printf("axis 4 %f\n", Robot::oi->getXbox()->GetRawAxis(4));
	printf("axis 5 %f\n", Robot::oi->getXbox()->GetRawAxis(5));*/
	float left = Robot::oi->getLeftStick()->GetY();
	float right= Robot::oi->getRightStick()->GetY();
	Robot::driveTrain->Move(left,right);
}
bool JoystickDrive::IsFinished(){return false;}
void JoystickDrive::End() {}
void JoystickDrive::Interrupted() {}
