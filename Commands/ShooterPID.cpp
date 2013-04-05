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
//#define DEBUG_PID_PRINT
#ifdef DEBUG_PID_PRINT
	if (counter % 10 == 0)
	{
		printf("RPM:%6.3f\tVolts:%5.2f\tTargSpeed: %5.0f\n", actualRPM, percentVoltage, targetRPM);
	}
#endif
	
	Robot::shooter->SetJagPercentVoltage(percentVoltage);
	
	return;
}
bool ShooterPID::IsFinished(){return false;}
void ShooterPID::End(){}
void ShooterPID::Interrupted(){printf("Been Inturrupted\n");}

