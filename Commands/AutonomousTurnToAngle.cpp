#include "AutonomousTurnToAngle.h"
#define PROPORTIONAL_FACTOR 0.01
#define TURN_SPEED_CAP .4
#define ACCEPTABLE_ANGLE_ERROR_DEGREES 5.0
AutonomousTurnToAngle::AutonomousTurnToAngle(float targetAngle) {
	Requires(Robot::driveTrain);
	this->targetAngle = CalculateCoterminalAngle(targetAngle) + Robot::driveTrain->gyro->GetAngle();
	currentAngle = Robot::driveTrain->gyro->GetAngle();
	leftIsBest = true;
}
void AutonomousTurnToAngle::Initialize() {
	float startingAngle = Robot::driveTrain->gyro->GetAngle();
	float distanceOne = fabs(startingAngle - targetAngle);
	float distanceTwo = fabs((360 - startingAngle) + targetAngle);
	if(startingAngle >= targetAngle) leftIsBest = distanceOne < distanceTwo;
	else leftIsBest = distanceOne > distanceTwo;
}
void AutonomousTurnToAngle::Execute() {
	UpdateCurrentAngle();
	float angleError = targetAngle - currentAngle;
	float output = angleError * PROPORTIONAL_FACTOR;
	if (output > TURN_SPEED_CAP) 
		output = TURN_SPEED_CAP;
	else if(output < -TURN_SPEED_CAP) 
		output = -TURN_SPEED_CAP;
	printf("output speed %f, angle %f, angleError %f\n", output, targetAngle, angleError);
	/*if(leftIsBest)Robot::driveTrain->Move(-output, -output);
	else*/ Robot::driveTrain->Move(output, output);
}
bool AutonomousTurnToAngle::IsFinished() {
	UpdateCurrentAngle();
	return fabs(targetAngle - Robot::driveTrain->gyro->GetAngle()) < ACCEPTABLE_ANGLE_ERROR_DEGREES;
}
void AutonomousTurnToAngle::End(){Robot::driveTrain->Stop();}
void AutonomousTurnToAngle::Interrupted(){End();}
float AutonomousTurnToAngle::CalculateCoterminalAngle(float targetAngle){
	const float inc = 360.f;
	while(targetAngle < 0) targetAngle += inc;
	while(targetAngle > inc) targetAngle -= inc;
	return targetAngle;
}
void AutonomousTurnToAngle::UpdateCurrentAngle(){currentAngle = Robot::driveTrain->gyro->GetAngle();}
