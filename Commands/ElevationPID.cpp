#include "ElevationPID.h"

const float DriveSpeed = .400;
const float P = .02; // Proportional correction factor. .02 = 20 degrees
const float acceptableAngleError = 5.0;
#define TURNING_ANGLE_DEGREES 90
ElevationPID::ElevationPID() {Requires(Robot::shooter);}
void ElevationPID::Initialize() {
	startingAngle = Robot::shooter->GetCurrentAngle();
}
void ElevationPID::Execute() {
	currentAngle = Robot::shooter->GetCurrentAngle(); 
	float targetAngle = Robot::shooter->GetElevationAngle();
	float errorAngle = targetAngle - currentAngle;
	float motorOutput = errorAngle * P;
	if (motorOutput > DriveSpeed) 
		motorOutput = DriveSpeed;
	else if (motorOutput < -DriveSpeed)
		motorOutput = -DriveSpeed;
	Robot::driveTrain->Move(motorOutput, -motorOutput);
}
bool ElevationPID::IsFinished() {
	
	currentAngle = startingAngle - Robot::shooter->GetCurrentAngle();
	float targetAngle = Robot::shooter->GetElevationAngle();
	float errorAngle = targetAngle - currentAngle;
	return (fabs(errorAngle)< acceptableAngleError);
}
void ElevationPID::Interrupted() {End();}
