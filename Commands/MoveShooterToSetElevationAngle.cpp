#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::shooter);
}
void MoveShooterToSetElevationAngle::Initialize(){
	Robot::shooter->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){}
bool MoveShooterToSetElevationAngle::IsFinished(){
	return Robot::shooter->IsAtSetAngle() || RobotMap::shooterElevationTopSwitch->IsPressed()
			|| RobotMap::shooterElevationBottomSwitch->IsPressed();
}
void MoveShooterToSetElevationAngle::End() {Done();}
void MoveShooterToSetElevationAngle::Interrupted(){Done();}
void MoveShooterToSetElevationAngle::Done() {Robot::shooter->StopElevatorMotor();}
