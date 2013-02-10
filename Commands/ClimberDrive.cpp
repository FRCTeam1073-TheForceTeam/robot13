#include "ClimberDrive.h"
//#define CLIMBER_MOTOR_RPM (39.0)
const float MaxClimberRPM = 39.0f;
ClimberDrive::ClimberDrive() {}
void ClimberDrive::Initialize() {Robot::climber->ClimberJagConfig();}
void ClimberDrive::Execute() {
	Robot::climber->Climb((Robot::oi->getOperatorStick()->GetY())*MaxClimberRPM);
}
bool ClimberDrive::IsFinished(){return false;}
void ClimberDrive::End(){}
void ClimberDrive::Interrupted() {}
