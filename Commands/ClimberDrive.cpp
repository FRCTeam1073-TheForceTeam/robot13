#include "ClimberDrive.h"
const float MaxClimberRPM = 39.0f;
ClimberDrive::ClimberDrive() {Requires(Robot::climber);}
void ClimberDrive::Initialize() {}
void ClimberDrive::Execute() {
	float y = Robot::oi->getOperatorStick()->GetY();
	Robot::climber->Climb(y * MaxClimberRPM);
}
bool ClimberDrive::IsFinished(){return false;}
void ClimberDrive::End(){}
void ClimberDrive::Interrupted() {}
