#include "ManualShooterSpeedAdjust.h"
ManualShooterSpeedAdjust::ManualShooterSpeedAdjust(bool positive, bool coarse) {
	Requires(Robot::shooter);
	this->positive = positive;
	this->coarse = coarse;
}
void ManualShooterSpeedAdjust::Initialize() {
	int increment = coarse ? Robot::shooter->GetCoarseAdjustmentSpeed() : Robot::shooter->GetFineAdjustmentSpeed();
	if(!positive) increment *= -1;
	Robot::shooter->IncrementSpeed(increment);
}
void ManualShooterSpeedAdjust::Execute() {}
bool ManualShooterSpeedAdjust::IsFinished() {return true;}
void ManualShooterSpeedAdjust::End() {}
void ManualShooterSpeedAdjust::Interrupted() {}
