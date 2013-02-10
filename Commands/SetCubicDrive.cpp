#include "SetCubicDrive.h"
SetCubicDrive::SetCubicDrive() {}
void SetCubicDrive::Initialize() {
	ChangeMode(Robot::oi->getLeftStick());
	ChangeMode(Robot::oi->getRightStick());
}
void SetCubicDrive::Execute() {}
bool SetCubicDrive::IsFinished() {return true;}
void SetCubicDrive::End() {}
void SetCubicDrive::Interrupted() {}
void SetCubicDrive::ChangeMode(SmartJoystick* smartJoystick){
	if(smartJoystick->GetJoystickMode() != SmartJoystick::cubic) smartJoystick->SetJoystickMode(SmartJoystick::cubic);
	else smartJoystick->SetJoystickMode(SmartJoystick::normal);
}