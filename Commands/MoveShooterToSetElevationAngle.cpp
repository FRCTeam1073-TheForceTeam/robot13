#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::elevator);
	encoderCheck = false;
}
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle(bool encoderCheck) {
	Requires(Robot::elevator);
	this->encoderCheck = encoderCheck;
}
void MoveShooterToSetElevationAngle::Initialize(){
	if(encoderCheck && Robot::elevator->GetEncoderFailed()) return;
	Robot::elevator->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){

	if(encoderCheck && Robot::elevator->GetEncoderFailed()) return;
	//to keep motors driving at speed proportional to error
	Robot::elevator->TurnToSetAngle();
}
bool MoveShooterToSetElevationAngle::IsFinished(){
	if(encoderCheck && Robot::elevator->GetEncoderFailed()) return true;
	return Robot::elevator->IsAtSetAngle();
}
void MoveShooterToSetElevationAngle::End() {Robot::elevator->MotorOff();}
void MoveShooterToSetElevationAngle::Interrupted(){End();}
