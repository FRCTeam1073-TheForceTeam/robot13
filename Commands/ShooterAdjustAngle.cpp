#include "ShooterAdjustAngle.h"
ShooterAdjustAngle::ShooterAdjustAngle(bool positive) {
	Requires(Robot::elevator);
	this->positive = positive;
}
void ShooterAdjustAngle::Initialize()
{
	if(positive && !IsAtTopLimit())
		Robot::elevator->MotorUpDown(positive);
	else if (!positive && !IsAtBottomLimit())
		Robot::elevator->MotorUpDown(positive);
	else
		Robot::elevator->MotorOff();
}
void ShooterAdjustAngle::Execute() {	
	//printf("ShooterAdjustAngle::Execute run\n");
	Robot::elevator->encoder->ProcessVoltageData();
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
	Robot::elevator->MotorOff();
	Robot::elevator->SetRawAngle(Robot::elevator->GetCurrentAngle());
	//printf("ShooterAdjustAngle::End End\n");
}
void ShooterAdjustAngle::Interrupted() {
	//printf("ShooterAdjustAngle::Inturupted\n"); 
	End();
}

bool ShooterAdjustAngle::IsAtTopLimit()
{
	bool isStalled = Robot::elevator->Stall();
	printf("IsAtEitherLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\tisStalled:%d\n", positive, Robot::elevator->GetCurrentAngle(), Robot::elevator->GetMaxAngle(), isStalled);
	if (isStalled)
		return false;
	else if (Robot::elevator->GetCurrentAngle() < Robot::elevator->GetMaxAngle())
		return false;
	return true;
}

bool ShooterAdjustAngle::IsAtBottomLimit()
{
	bool isStalled = Robot::elevator->Stall();
		printf("IsAtBottomLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\tisStalled:%d\n", positive, Robot::elevator->GetCurrentAngle(), Robot::elevator->GetMaxAngle(), isStalled);
		if (isStalled)
			return false;
		else if (Robot::elevator->GetCurrentAngle() > Robot::elevator->GetMinAngle())
			return false;
		return true;
}
