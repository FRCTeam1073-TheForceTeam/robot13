#include "PullShooterData.h"
PullShooterData::PullShooterData() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void PullShooterData::Initialize() {
	puts("Pull shooer data init");
	Robot::shooter->SetPID(SmartDashboard::GetNumber(SHOOTER_P),
			SmartDashboard::GetNumber(SHOOTER_I), SmartDashboard::GetNumber(SHOOTER_D));
}
void PullShooterData::Execute(){
	int speed = (int)SmartDashboard::GetNumber(SHOOTER_PRIMARY_SPEED_SET);
	printf("The speed we are getting from the dashboard is:\t%d!\n", speed);
	Robot::shooter->SetRawSpeed(speed);
	SmartDashboard::PutNumber(SHOOTER_RPM_ENCODER, RobotMap::shooterWheelRPMEncoder->Get());
	SmartDashboard::PutNumber(SHOOTER_PRIMARY_CURRENT_SPEED, RobotMap::shooterPrimaryJag->GetSpeed());
	SmartDashboard::PutNumber(SHOOTER_SUPPORT_CURRENT_SPEED, RobotMap::shooterSupportJag->GetSpeed());
}
bool PullShooterData::IsFinished() {return true;}
