#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() 
{
	if(Robot::allignmentData->IsTarget()){
		double calcAngle = Robot::allignmentData->GetCalculatedAngle();
		double calcDistance = Robot::allignmentData->GetCalculatedDistance();
		printf("SetShooterToCalculatedValues angle: %d   distance: %d\n", calcAngle, calcDistance);
	}
	else
		printf("Allignment data; invalid distance and angle\n");
}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}void SetShooterToCalculatedValues::Interrupted() {}
