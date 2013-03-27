#include "ShooterPID.h"

#define P 0.01

ShooterPID::ShooterPID(){
	Requires(Robot::shooter);
}
void ShooterPID::Initialize(){
	printf("ShooterPID Initialize");
}
void ShooterPID::Execute(){
	float actualRPM = RobotMap::newShooterIREncoder->GetRPM();
	float targetRPM = Robot::shooter->GetFrontSetSpeed();
	float errorRPM = targetRPM - actualRPM;
	float rampRate = errorRPM * P;

	printf("Encoder RPM:%f\n", actualRPM);
	printf("ShooterJag Ramp Rate:%f\n", rampRate);
	
	Robot::shooter->SetJagVoltageRampRate(rampRate);
	
	return;
}
bool ShooterPID::IsFinished(){return false;}
void ShooterPID::End(){}
void ShooterPID::Interrupted(){printf("Been Inturrupted\n");}
