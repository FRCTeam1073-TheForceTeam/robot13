#include "TurboDriveOn.h"
#define PRINT_TURBO
TurboDriveOn::TurboDriveOn(SmartJoystick* stick) {
	this->stick = stick;
	old = SmartJoystick::normal;
}
void TurboDriveOn::Initialize(){
#ifdef PRINT_TURBO
	puts("turbo init");
#endif
	old = stick->GetJoystickMode();
	stick->SetJoystickMode(SmartJoystick::extreme);
}
void TurboDriveOn::Execute(){}
bool TurboDriveOn::IsFinished(){return false;}
void TurboDriveOn::End(){Interrupted();}	//the command should never actually End, but good practice just in case
void TurboDriveOn::Interrupted() {
	stick->SetJoystickMode(old);
#ifdef PRINT_TURBO
	puts("turbo done");
#endif
}
