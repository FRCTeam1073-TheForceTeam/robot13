#include "PullShooterData.h"

#define DEBUG_DATA

PullShooterData::PullShooterData() {Requires(Robot::shooter);}
void PullShooterData::Initialize() {
#ifdef DEBUG_DATA
	puts("Pull shooter data init");
	Robot::shooter->SetPID(SmartDashboard::GetNumber(SHOOTER_P),
			SmartDashboard::GetNumber(SHOOTER_I), SmartDashboard::GetNumber(SHOOTER_D));
#endif
}
void PullShooterData::Execute(){
#ifdef DEBUG_DATA
	int speed = (int)SmartDashboard::GetNumber(SHOOTER_FRONT_SET_SPEED);
	int speed2 = (int)SmartDashboard::GetNumber(SHOOTER_BACK_SET_SPEED);
	printf("The speed we are getting from the dashboard is:\t1: %d and 2: %d!\n", speed, speed2);
	Robot::shooter->SetRawSpeed(speed);
	
	SmartDashboard::PutNumber(SHOOTER_FRONT_CURRENT_SPEED, RobotMap::shooterJag->GetSpeed());
#endif
}
bool PullShooterData::IsFinished() {return true;}
