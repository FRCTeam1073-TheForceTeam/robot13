#include "shooterAdjustAngle.h"
ShooterAdjustAngle::ShooterAdjustAngle(bool positive) {
	Requires(Robot::shooter);
	this->positive = positive;
}
void ShooterAdjustAngle::Initialize()
{
	if(!IsAtEitherLimit())
		Robot::shooter->ElevatorUpDown(positive);
}
void ShooterAdjustAngle::Execute() {	
	//printf("ShooterAdjustAngle::Execute run\n");
	Robot::shooter->ProcessVoltageData();
}
bool ShooterAdjustAngle::IsFinished() {
	//printf("ShooterAdjustAngle::IsFinished run\n");
	if (IsAtEitherLimit())
		return true;
	
	return false;
}
void ShooterAdjustAngle::End() 
{
	//printf("ShooterAdjustAngle::End Start\n");
	Robot::shooter->ElevatorOff();
	Robot::shooter->SetRawElevationAngle(Robot::shooter->GetCurrentAngle());
	//printf("ShooterAdjustAngle::End End\n");
}
void ShooterAdjustAngle::Interrupted() {
	//printf("ShooterAdjustAngle::Inturupted\n"); 
	End();
}

bool ShooterAdjustAngle::IsAtEitherLimit()
{
	bool isStalled = Robot::shooter->IsElevatorStalled();
	printf("IsAtEitherLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\tisStalled:%d\n", positive, Robot::shooter->GetCurrentAngle(), Robot::shooter->GetMaxAngle(), isStalled);
	if (isStalled)
		return false;
	else if (positive && Robot::shooter->GetCurrentAngle() < Robot::shooter->GetMaxAngle())
		return false;
	else if (!positive && (Robot::shooter->GetCurrentAngle() - Robot::shooter->GetMinAngle()) > 3)
		return false;
	else
		return true;
}
