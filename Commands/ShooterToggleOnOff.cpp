#include "ShooterToggleOnOff.h"
ShooterToggleOnOff::ShooterToggleOnOff(){
	Requires(Robot::climber);
	previousOnOff = off;
}
void ShooterToggleOnOff::Initialize(){
	Robot::shooter->ShooterOnOff((previousOnOff == on ? off: on));
	previousOnOff = (previousOnOff == on ? off: on);
}
void ShooterToggleOnOff::Execute(){}
bool ShooterToggleOnOff::IsFinished(){return true;}
void ShooterToggleOnOff::End(){}
void ShooterToggleOnOff::Interrupted(){}
