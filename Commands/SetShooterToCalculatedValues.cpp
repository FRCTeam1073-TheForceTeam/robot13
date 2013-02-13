#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() 
{
	if(Robot::allignmentData->IsTarget()){
		float calcAngle = Robot::allignmentData->GetCalculatedAngle();
		float calcDistance = Robot::allignmentData->GetCalculatedDistance();
		Robot::shooter->SetRawAngle(calcAngle);
#warning "Calculated speed / distance not set"
		printf("SetShooterToCalculatedValues angle: %f   distance: %f\n", calcAngle, calcDistance);
	}
	else
		printf("Allignment data; invalid distance and angle\n");
}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}void SetShooterToCalculatedValues::Interrupted() {}
