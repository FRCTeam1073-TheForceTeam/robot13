#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues(){
	Requires(Robot::allignmentData);
	Requires(Robot::shooter);
}
void SetShooterToCalculatedValues::Initialize(){
	Robot::shooter->UpdateDefaults(Robot::allignmentData->GetCalculatedDistance(), 
			Robot::allignmentData->GetCalculatedAngle());
}
void SetShooterToCalculatedValues::Execute(){}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}
void SetShooterToCalculatedValues::Interrupted() {}