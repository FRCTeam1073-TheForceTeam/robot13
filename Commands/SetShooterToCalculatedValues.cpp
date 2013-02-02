#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() 
{
	double calcAngle = Robot::allignmentData->GetCalculatedAngle();
	double calcDistance = Robot::allignmentData->GetCalculatedDistance();
	printf("SetShooterToCalculatedValues angle: %d   distance: %d", calcAngle, calcDistance);
}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}void SetShooterToCalculatedValues::Interrupted() {}
