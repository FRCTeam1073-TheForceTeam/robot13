#include "AutonomousForward.h"
#define FORWARD_SPEED .5 //.5 equals half speed
const float P = .02; //.02 equals 20 degrees full power.
const float DriveSpeed = .400;
AutonomousForward::AutonomousForward(float distance) {
	Requires(Robot::driveTrain);
	distanceToDrive = distance;
}
void AutonomousForward::Initialize() {
	Robot::driveTrain->GetPosition(startingLeft, startingRight);
//	Robot::driveTrain->Move(FORWARD_SPEED, FORWARD_SPEED);
	startingAngle = Robot::driveTrain->GetGyroAngleDegrees();
	
}
// Called repeatedly when this Command is scheduled to run
void AutonomousForward::Execute() {
	float errorAngle = startingAngle - Robot::driveTrain->GetGyroAngleDegrees();
	float speedAdjuster = errorAngle * P;
	float leftSpeed = DriveSpeed * (1 - speedAdjuster);
	float rightSpeed = DriveSpeed * (1 + speedAdjuster);
	Robot::driveTrain->Move(leftSpeed, rightSpeed);
}
bool AutonomousForward::IsFinished() {
	float currentLeft = 0;
	float currentRight= 0;
	Robot::driveTrain->GetPosition(currentLeft, currentRight);
	return ((currentLeft - startingLeft > distanceToDrive) && (currentRight - startingRight > distanceToDrive));
}
void AutonomousForward::End() {Robot::driveTrain->Stop();}
void AutonomousForward::Interrupted() {}
