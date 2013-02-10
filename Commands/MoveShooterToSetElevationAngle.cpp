#include "MoveShooterToSetElevationAngle.h"
MoveShooterToSetElevationAngle::MoveShooterToSetElevationAngle() {
	Requires(Robot::shooter);
}
void MoveShooterToSetElevationAngle::Initialize(){
	Robot::shooter->TurnToSetAngle();
}
void MoveShooterToSetElevationAngle::Execute(){}
bool MoveShooterToSetElevationAngle::IsFinished(){
	//TODO: not sure if polarity means == 0
#warning "RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER RED FLAG DANGER "
	bool ShooterBottomSwitch = RobotMap::shooterElevationJag->Get() == 1;
	return Robot::shooter->IsAtSetAngle()
			|| ShooterBottomSwitch;
}
void MoveShooterToSetElevationAngle::End() {Done();}
void MoveShooterToSetElevationAngle::Interrupted(){Done();}
void MoveShooterToSetElevationAngle::Done() {Robot::shooter->StopElevatorMotor();}
