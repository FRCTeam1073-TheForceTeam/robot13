#include "ShooterAdjustAngle.h"

const float softTopAngleLimit = 25;
const float softBottomAngleLimit = -0.6;

ShooterAdjustAngle::ShooterAdjustAngle(bool positive) {
	Requires(Robot::elevator);
	this->positive = positive;
}
void ShooterAdjustAngle::Initialize()
{
	if(!IsFinished()){
		if(positive)// && !IsAtTopLimit())
			Robot::elevator->MotorUpDown(positive);
		else if (!positive)// && !IsAtBottomLimit())
			Robot::elevator->MotorUpDown(positive);
		else
			Robot::elevator->MotorOff();
	}
	else Robot::elevator->MotorOff();
}
void ShooterAdjustAngle::Execute() {	
	//printf("ShooterAdjustAngle::Execute run\n");
	Robot::elevator->encoder->ProcessVoltageData();
}
bool ShooterAdjustAngle::IsFinished() {
	//printf("ShooterAdjustAngle::IsFinished run\n");
	if(positive)// && !IsAtTopLimit())
		return false;
	else if (!positive)// && !IsAtBottomLimit())
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

bool ShooterAdjustAngle::IsAtTopLimit(){
	printf("IsAtEitherLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\n", positive, Robot::elevator->GetCurrentAngle(), Robot::elevator->GetMaxAngle());
	if (Robot::elevator->GetCurrentAngle() < softTopAngleLimit)
		return false;
	return true;
}

bool ShooterAdjustAngle::IsAtBottomLimit(){
		printf("IsAtBottomLimit. up: %d\tCurrent Angle: %f\tMax Angle:%f\n", positive, Robot::elevator->GetCurrentAngle(), Robot::elevator->GetMaxAngle());
		if (Robot::elevator->GetCurrentAngle() > softBottomAngleLimit)
			return false;
		return true;
}
