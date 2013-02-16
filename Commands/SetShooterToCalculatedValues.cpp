#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() 
{
	if(Robot::allignmentData->IsTarget()){
		float calcAngle = Robot::allignmentData->GetCalculatedAngle();
		float calcVelocityFPS = Robot::allignmentData->GetCalculatedVelocityFPS();
		Robot::shooter->SetRawElevationAngle(calcAngle);
		Robot::shooter->SetRawSpeed(Robot::shooter->VelocityFPSToRPM(calcVelocityFPS));
		printf("SetShooterToCalculatedValues angle: %f   distance: %f\n", calcAngle, calcVelocityFPS);
	}
	else
		printf("Allignment data; invalid distance and angle\n");
}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}void SetShooterToCalculatedValues::Interrupted() {}
