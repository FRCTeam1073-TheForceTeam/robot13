#include "ManualShooterSpeedAdust.h"
ManualShooterSpeedAdust::ManualShooterSpeedAdust(bool positive, bool coarse) {
	Requires(Robot::shooter);
	this->positive = positive;
	this->coarse = coarse;
}
void ManualShooterSpeedAdust::Initialize() {
	int increment = coarse ? Robot::shooter->GetCoarseAdjustmentSpeed() : Robot::shooter->GetFineAdjustmentSpeed();
	if(!positive) increment *= -1;
	Robot::shooter->IncrementSpeed(increment);
}
void ManualShooterSpeedAdust::Execute() {}
bool ManualShooterSpeedAdust::IsFinished() {return true;}
void ManualShooterSpeedAdust::End() {}
void ManualShooterSpeedAdust::Interrupted() {}
