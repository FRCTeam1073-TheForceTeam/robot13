#include "ClimberDrive.h"
//#define CLIMBER_MOTOR_RPM (39.0)
const float MaxClimberRPM = 39.0f;
ClimberDrive::ClimberDrive() {Requires(Robot::climber);}
void ClimberDrive::Initialize() {Robot::climber->ClimberJagConfig();}
void ClimberDrive::Execute() {
	float y = Robot::oi->getOperatorStick()->GetY();
	//if (y > 0) y = 0;
	//printf("joy y:\t%f\n", y);	
	Robot::climber->Climb(y * MaxClimberRPM);
}
bool ClimberDrive::IsFinished(){return false;}
void ClimberDrive::End(){}
void ClimberDrive::Interrupted() {}
