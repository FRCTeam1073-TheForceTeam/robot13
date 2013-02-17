#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::shooter);
}
void MoveShooterToSetElevationAngle::Initialize(){
	Robot::shooter->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){}
bool MoveShooterToSetElevationAngle::IsFinished(){
	return Robot::shooter->IsAtSetAngle();
}
void MoveShooterToSetElevationAngle::End() {Robot::shooter->ElevatorOff();}
void MoveShooterToSetElevationAngle::Interrupted(){End();}
