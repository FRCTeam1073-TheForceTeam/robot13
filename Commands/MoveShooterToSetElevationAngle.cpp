#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::shooter);
	encoderCheck = false;
}
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle(bool encoderCheck) {
	Requires(Robot::shooter);
	this->encoderCheck = encoderCheck;
}
void MoveShooterToSetElevationAngle::Initialize(){
	if(encoderCheck && Robot::shooter->GetElevationEncoderFailed()) return;
	Robot::shooter->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){

	if(encoderCheck && Robot::shooter->GetElevationEncoderFailed()) return;
	//to keep motors driving at speed proportional to error
	Robot::shooter->TurnToSetAngle();
}
bool MoveShooterToSetElevationAngle::IsFinished(){
	if(encoderCheck && Robot::shooter->GetElevationEncoderFailed()) return true;
	return Robot::shooter->IsAtSetAngle();
}
void MoveShooterToSetElevationAngle::End() {Robot::shooter->ElevatorOff();}
void MoveShooterToSetElevationAngle::Interrupted(){End();}
