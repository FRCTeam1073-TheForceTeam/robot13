#include "AutonomousTurns.h"
#include "cmath"
#define FORWARD_SPEED 100
#define TURNING_ANGLE 90
AutonomousTurns::AutonomousTurns() {Init(false);}
AutonomousTurns::AutonomousTurns(bool isRight) {Init(isRight);}
void AutonomousTurns::Initialize() {
	startingAngle = Robot::driveTrain->GetGyroAngle();
	if(isRight) Robot::driveTrain->Move(0, FORWARD_SPEED);
	else Robot::driveTrain->Move(FORWARD_SPEED, 0);
}
void AutonomousTurns::Execute() {
	
}
bool AutonomousTurns::IsFinished() {
	float value = startingAngle - Robot::driveTrain->GetGyroAngle();
	if(!isRight) value = abs(value); 
	return value > TURNING_ANGLE;
}
void AutonomousTurns::End() {
	Robot::driveTrain->Move(0, 0);
}
void AutonomousTurns::Interrupted() {
	End();
}
void AutonomousTurns::Init(bool isRight){
	Requires(Robot::driveTrain);
	this->isRight = isRight;
}
