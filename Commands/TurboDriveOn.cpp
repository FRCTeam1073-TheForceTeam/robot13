#include "TurboDriveOn.h"
TurboDriveOn::TurboDriveOn() {}
void TurboDriveOn::Initialize() {
	Robot::oi->getLeftStick()->SetJoystickMode(SmartJoystick::extreme);
	Robot::oi->getRightStick()->SetJoystickMode(SmartJoystick::extreme);
}
void TurboDriveOn::Execute() {}
bool TurboDriveOn::IsFinished() {return false;}
void TurboDriveOn::End() {}
void TurboDriveOn::Interrupted() {
	Robot::oi->getLeftStick()->SetJoystickMode(SmartJoystick::normal);
	Robot::oi->getRightStick()->SetJoystickMode(SmartJoystick::normal);
}
