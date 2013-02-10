#include "TurboDriveOn.h"
TurboDriveOn::TurboDriveOn() {
	old_left = SmartJoystick::normal;
	old_right = SmartJoystick::normal;
}
void TurboDriveOn::Initialize() {
	old_left = Robot::oi->getLeftStick()->GetJoystickMode();
	old_right = Robot::oi->getRightStick()->GetJoystickMode();
	Robot::oi->getLeftStick()->SetJoystickMode(SmartJoystick::extreme);
	Robot::oi->getRightStick()->SetJoystickMode(SmartJoystick::extreme);
}
void TurboDriveOn::Execute() {}
bool TurboDriveOn::IsFinished() {return false;}
void TurboDriveOn::End() {}
void TurboDriveOn::Interrupted() {
	Robot::oi->getLeftStick()->SetJoystickMode(old_left);
	Robot::oi->getRightStick()->SetJoystickMode(old_right);
}
