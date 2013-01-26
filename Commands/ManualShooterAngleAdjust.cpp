#include "ManualShooterAngleAdjust.h"
ManualShooterAngleAdjust::ManualShooterAngleAdjust(){/*Don't construct me*/}
ManualShooterAngleAdjust::ManualShooterAngleAdjust(bool coarse, bool positive){
	this->coarse = coarse;
	this->positive = positive;
	Requires(Robot::shooter);
}
void ManualShooterAngleAdjust::Initialize(){
	int angle = coarse ? Robot::shooter->GetCoarseAdjustmentAngle() : Robot::shooter->GetFineAdjustmentAngle();
	if(!positive) angle *= -1;
	Robot::shooter->IncrementAngle(angle);
}
bool ManualShooterAngleAdjust::IsFinished(){
	return false;
}
void ManualShooterAngleAdjust::End(){
	Robot::shooter->StopElevatorMotor();
}
void ManualShooterAngleAdjust::Interrupted()	{End();}
