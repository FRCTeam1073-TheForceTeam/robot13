#include "ShooterPID.h"

const float P = 0.01;
static int counter = 0;

ShooterPID::ShooterPID(){
	Requires(Robot::shooter);
	printf("ShooterPID Constructor\n");
}
void ShooterPID::Initialize(){
	printf("ShooterPID Initialize\n");
}
void ShooterPID::Execute(){
	counter++;
	float actualRPM = RobotMap::newShooterIREncoder->GetRPM();
	float targetRPM = Robot::shooter->GetFrontSetSpeed();
	float errorRPM = targetRPM - actualRPM;
	float percentVoltage = errorRPM * P;

	if (counter % 50 == 0)
	{
		printf("Encoder RPM:%f\n", actualRPM);
		printf("ShooterJag Percent Voltage:%f\n", percentVoltage);
		printf("Shooter Target Speed: %f\n", targetRPM);
	}
	
	Robot::shooter->SetJagPercentVoltage(percentVoltage);
	
	return;
}
bool ShooterPID::IsFinished(){return false;}
void ShooterPID::End(){}
void ShooterPID::Interrupted(){printf("Been Inturrupted\n");}
