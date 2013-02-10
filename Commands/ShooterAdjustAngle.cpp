#include "shooterAdjustAngle.h"
ShooterAdjustAngle::ShooterAdjustAngle() {
	Requires(Robot::shooter);
}
void ShooterAdjustAngle::Initialize() {}
void ShooterAdjustAngle::Execute() {
	float hat = Robot::oi->getOperatorStick()->GetHatY(); //-1 if down, 0 if neutral, 1 if up
	if (hat != 0)	Robot::shooter->IncrementAngle(hat * Robot::shooter->GetFineAdjustmentAngle());
	//printf ("adjustment angle is %d\n", hat);
}
bool ShooterAdjustAngle::IsFinished() {return false;}
void ShooterAdjustAngle::End() {}
void ShooterAdjustAngle::Interrupted() {}
