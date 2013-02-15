#include "PullShooterData.h"
PullShooterData::PullShooterData() {Requires(Robot::shooter);}
void PullShooterData::Initialize() {
	puts("Pull shooter data init");
	Robot::shooter->SetPID(SmartDashboard::GetNumber(SHOOTER_P),
			SmartDashboard::GetNumber(SHOOTER_I), SmartDashboard::GetNumber(SHOOTER_D));
}
void PullShooterData::Execute(){
	int speed = (int)SmartDashboard::GetNumber(SHOOTER_FRONT_SET_SPEED);
	int speed2 = (int)SmartDashboard::GetNumber(SHOOTER_BACK_SET_SPEED);
	printf("The speed we are getting from the dashboard is:\t1: %d and 2: %d!\n", speed, speed2);
	Robot::shooter->SetRawSpeed(speed);
	Robot::shooter->SetRawBackSpeed(speed2);
	SmartDashboard::PutNumber(SHOOTER_FRONT_CURRENT_SPEED, RobotMap::shooterFrontJag->GetSpeed());
	SmartDashboard::PutNumber(SHOOTER_BACK_CURRENT_SPEED, RobotMap::shooterBackJag->GetSpeed());
}
bool PullShooterData::IsFinished() {return true;}
