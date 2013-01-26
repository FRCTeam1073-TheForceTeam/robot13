#include "ManualShooterAngleAdjust.h"
ManualShooterAngleAjust::ManualShooterAngleAjust(bool coarse, bool positive){
	this->coarse = coarse;
	this->positive = positive;
	Requires(Robot::shooter);
}
void ManualShooterAngleAjust::Initialize(){
	int angle = coarse ? Robot::shooter->GetCoarseAdjustmentAngle() : Robot::shooter->GetFineAdjustmentAngle();
	if(!positive) angle *= -1;
	Robot::shooter->IncrementAngle(angle);
}
bool ManualShooterAngleAjust::IsFinished(){
	return false;
}
void ManualShooterAngleAjust::End(){
	Robot::shooter->StopElevatorMotor();
}
void ManualShooterAngleAjust::Interrupted()	{End();}
