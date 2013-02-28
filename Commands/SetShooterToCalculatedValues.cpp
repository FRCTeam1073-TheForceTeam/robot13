#include "SetShooterToCalculatedValues.h"

#define DEFAULT -1

SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() 
{
	float calcAngle = Robot::allignmentData->GetCalculatedAngle();
	float calcVelocityRPM = Robot::allignmentData->GetCalculatedVelocityRPM();
	if(calcAngle != DEFAULT && calcVelocityRPM != DEFAULT)
	{
		Robot::shooter->SetRawElevationAngle(calcAngle);
		Robot::shooter->SetRawSpeed((int)calcVelocityRPM);
		printf("SetShooterToCalculatedValues angle: %f   distance: %f\n", calcAngle, calcVelocityRPM);
	}
	else
		printf("Allignment data; invalid distance and angle\n");
}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}
void SetShooterToCalculatedValues::Interrupted() {}
