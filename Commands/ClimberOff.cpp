#include "ClimberOff.h"
ClimberOff::ClimberOff() {
	Requires(Robot::climber);
}
void ClimberOff::Initialize() {}
void ClimberOff::Execute() {
	Robot::climber->DisengageClimber();
}
bool ClimberOff::IsFinished() {return true;}
void ClimberOff::End() {}
void ClimberOff::Interrupted() {}
