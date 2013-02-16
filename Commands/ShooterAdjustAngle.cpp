#include "shooterAdjustAngle.h"
ShooterAdjustAngle::ShooterAdjustAngle(bool positive) {
	Requires(Robot::shooter);
	this->positive = positive;
}
void ShooterAdjustAngle::Initialize() {Robot::shooter->ElevatorUpDown(positive);}
void ShooterAdjustAngle::Execute() {	
}
bool ShooterAdjustAngle::IsFinished() {return true;}
void ShooterAdjustAngle::End() {Robot::shooter->ElevatorOff();}
void ShooterAdjustAngle::Interrupted() {}
