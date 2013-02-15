#include "TurboDriveOn.h"
bool TurboDriveOn::on = false;
TurboDriveOn::TurboDriveOn() {
	old_left = SmartJoystick::normal;
	old_right = SmartJoystick::normal;
}
void TurboDriveOn::Initialize(){
	on = !on;
	if(on){
		old_left = Robot::oi->getLeftStick()->GetJoystickMode();
		old_right = Robot::oi->getRightStick()->GetJoystickMode();
		Robot::oi->getLeftStick()->SetJoystickMode(SmartJoystick::extreme);
		Robot::oi->getRightStick()->SetJoystickMode(SmartJoystick::extreme);
	}
	else{
		Robot::oi->getLeftStick()->SetJoystickMode(old_left);
		Robot::oi->getRightStick()->SetJoystickMode(old_right);
	}
}
void TurboDriveOn::Execute(){}
bool TurboDriveOn::IsFinished(){return true;}
void TurboDriveOn::End(){}
void TurboDriveOn::Interrupted() {}
