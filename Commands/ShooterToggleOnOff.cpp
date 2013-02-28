#include "ShooterToggleOnOff.h"
ShooterToggleOnOff::ShooterToggleOnOff(){
	Requires(Robot::shooter);
	previousOnOff = off;
}
void ShooterToggleOnOff::Initialize(){
	previousOnOff = (previousOnOff == on ? off : on);
	Robot::shooter->ShooterOnOff((previousOnOff == on ? true : false));
}
void ShooterToggleOnOff::Execute(){}
bool ShooterToggleOnOff::IsFinished(){return true;}
void ShooterToggleOnOff::End(){}
void ShooterToggleOnOff::Interrupted(){}
