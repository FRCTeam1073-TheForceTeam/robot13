#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::shooter);
}
void MoveShooterToSetElevationAngle::Initialize(){
	Robot::shooter->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){}
bool MoveShooterToSetElevationAngle::IsFinished(){
	bool ShooterBottomSwitch = RobotMap::shooterElevationJag->Get() == 0;
	return Robot::shooter->IsAtSetAngle()
			|| ShooterBottomSwitch;
}
void MoveShooterToSetElevationAngle::End() {Robot::shooter->ElevatorOff();}
void MoveShooterToSetElevationAngle::Interrupted(){End();}
