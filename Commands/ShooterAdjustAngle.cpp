#include "shooterAdjustAngle.h"
ShooterAdjustAngle::ShooterAdjustAngle(bool positive) {
	Requires(Robot::shooter);
	this->positive = positive;
}
void ShooterAdjustAngle::Initialize()
{
	if(positive && !IsAtTopLimit())
		Robot::shooter->ElevatorUpDown(positive);
	else if (!positive && !IsAtBottomLimit())
		Robot::shooter->ElevatorUpDown(positive);
	else
		Robot::shooter->ElevatorOff();
}
void ShooterAdjustAngle::Execute() {	
	//printf("ShooterAdjustAngle::Execute run\n");
	Robot::shooter->ProcessVoltageData();
}
bool ShooterAdjustAngle::IsFinished() {
	//printf("ShooterAdjustAngle::IsFinished run\n");
	if(positive && !IsAtTopLimit())
		return false;
	else if (!positive && !IsAtBottomLimit())
		return false;

	return true;
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

bool ShooterAdjustAngle::IsAtTopLimit()
{
	bool isStalled = Robot::shooter->IsElevatorStalled();
	printf("IsAtEitherLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\tisStalled:%d\n", positive, Robot::shooter->GetCurrentAngle(), Robot::shooter->GetMaxAngle(), isStalled);
	if (isStalled)
		return false;
	else if (Robot::shooter->GetCurrentAngle() < Robot::shooter->GetMaxAngle())
		return false;
	else
		return true;
}

bool ShooterAdjustAngle::IsAtBottomLimit()
{
	bool isStalled = Robot::shooter->IsElevatorStalled();
		printf("IsAtBottomLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\tisStalled:%d\n", positive, Robot::shooter->GetCurrentAngle(), Robot::shooter->GetMaxAngle(), isStalled);
		if (isStalled)
			return false;
		else if (Robot::shooter->GetCurrentAngle() > Robot::shooter->GetMinAngle())
			return false;
		else
			return true;
}
