#include "AutonomousTurnToAngle.h"
#define PROPORTIONAL_FACTOR 0.2
#define TURN_SPEED_CAP .4
#define ACCEPTABLE_ANGLE_ERROR_DEGREES 5.0
AutonomousTurnToAngle::AutonomousTurnToAngle(float targetAngle) {
	Requires(Robot::driveTrain);
    this->targetAngle = CalculateCoterminalAngle(targetAngle) + Robot::driveTrain->GetGyroAngle();
	currentAngle = Robot::driveTrain->GetGyroAngle();
	leftIsBest = true;
}
void AutonomousTurnToAngle::Initialize() {
	float startingAngle = Robot::driveTrain->GetGyroAngle();
	float distanceOne = fabs(startingAngle - targetAngle);
	float distanceTwo = fabs((360 - startingAngle) + targetAngle);
	if(startingAngle >= targetAngle) leftIsBest = distanceOne < distanceTwo;
	else leftIsBest = distanceOne > distanceTwo;
}
void AutonomousTurnToAngle::Execute() {
	UpdateCurrentAngle();
	float output = fabs(targetAngle - currentAngle) * PROPORTIONAL_FACTOR;
	if (output > TURN_SPEED_CAP) 
		output = TURN_SPEED_CAP;
	else if(output < -TURN_SPEED_CAP) 
		output = -TURN_SPEED_CAP;
	if(leftIsBest)Robot::driveTrain->Move(output, -output);
	else Robot::driveTrain->Move(-output, output);
}
bool AutonomousTurnToAngle::IsFinished() {
	UpdateCurrentAngle();
	return fabs(targetAngle - Robot::driveTrain->GetGyroAngle()) < ACCEPTABLE_ANGLE_ERROR_DEGREES;
}
void AutonomousTurnToAngle::End(){Robot::driveTrain->Stop();}
void AutonomousTurnToAngle::Interrupted(){End();}
float AutonomousTurnToAngle::CalculateCoterminalAngle(float targetAngle){
	const float inc = 360.f;
	while(targetAngle < 0) targetAngle += inc;
	while(targetAngle > inc) targetAngle -= inc;
	return targetAngle;
}
void AutonomousTurnToAngle::UpdateCurrentAngle(){currentAngle = Robot::driveTrain->GetGyroAngle();}
