#include "AutonomousTurns.h"
#include "cmath"
#define FORWARD_SPEED .5 //.5 equals half speed
#define BACKWARD_SPEED -.5 //-.5 equals reverse half speed
const float DriveSpeed = .400;
const float P = .02; // Proportional correction factor. .02 = 20 degrees
const float acceptableAngleError = 5.0;
#define TURNING_ANGLE_DEGREES 90
AutonomousTurns::AutonomousTurns() {Init(false);}
AutonomousTurns::AutonomousTurns(bool isRight) {Init(isRight);}
void AutonomousTurns::Initialize() {
	startingAngle = Robot::driveTrain->GetGyroAngle();
	if (isRight)
		targetAngle = TURNING_ANGLE_DEGREES;
	else 
		targetAngle = -TURNING_ANGLE_DEGREES; 
			
			
//	if(isRight) Robot::driveTrain->Move(DriveSpeed, -DriveSpeed);
	//else Robot::driveTrain->Move(-DriveSpeed, DriveSpeed);
}
void AutonomousTurns::Execute() {
	
	currentAngle = startingAngle - Robot::driveTrain->GetGyroAngle(); 
	
	float errorAngle = targetAngle - currentAngle;
	
	float motorOutput = errorAngle * P;
	if (motorOutput > DriveSpeed) 
		motorOutput = DriveSpeed;
	else if (motorOutput < -DriveSpeed)
		motorOutput = -DriveSpeed;
	
	Robot::driveTrain->Move(motorOutput, -motorOutput);
	
	
	
}
bool AutonomousTurns::IsFinished() {
	currentAngle = startingAngle - Robot::driveTrain->GetGyroAngle();
	float errorAngle = targetAngle - currentAngle;
	return (fabs(errorAngle)< acceptableAngleError);
		
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
