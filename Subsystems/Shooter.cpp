#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/UpdateCalculatedShooterValues.h"
Shooter::Shooter() : Subsystem("Shooter") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	elevationJag = RobotMap::shooterElevationJag;
	elevationEncoder = RobotMap::shooterElevationEncoder;
	shooterJag = RobotMap::shooterShooterJag;
	shooterEncoder = RobotMap::shooterShooterEncoder;
	elevationTopSwitch = RobotMap::shooterElevationTopSwitch;
	elevationBottomSwitch = RobotMap::shooterElevationBottomSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	isShooterMotorOn = false;
}
void Shooter::InitDefaultCommand() {SetDefaultCommand(new UpdateCalculatedShooterValues());}
void Shooter::ShooterOnOff(bool on){
	isShooterMotorOn = on;
	if(on) shooterJag->Set(speed);
	else shooterJag->Set(SHOOTER_OFF);
}
bool Shooter::IsShooterMotorOn() {return isShooterMotorOn;}
float Shooter::GetActualMotorSpeed() {return shooterJag->GetSpeed();}
int Shooter::GetSetSpeed() {return speed;}
int Shooter::GetSetElevationAngle() {return elevationAngle;}
int Shooter::GetDefaultSpeed() {return defaultSpeed;}
int Shooter::GetDefaultElevationAngle() {return defaultElevationAngle;}
void Shooter::SetToDefaults(){
	IncrementSpeed(defaultSpeed - speed);
	elevationAngle = defaultElevationAngle;
}
void Shooter::UpdateDefaults(int distanceToTarget, int robotAngleToTarget){
	//TODO: Math
}
void Shooter::IncrementSpeed(int speedIncrement){
	speed += speedIncrement;
	if(isShooterMotorOn) ShooterOnOff(true);
}
void Shooter::IncrementAngle(int angleIncrement){
	elevationAngle += angleIncrement;
}
//Figured this might be useful if we want to quickly put the speed to a certain preset
void Shooter::SetRawSpeed(int speed) {
	if(speed < 0 ) return;
	IncrementSpeed(speed - this->speed);
}
bool Shooter::IsUpLimitPressed(){
	return elevationTopSwitch->Get() == 1;
}
bool Shooter::IsDownLimitPressed(){
	return elevationBottomSwitch->Get() == 1;
}
//TODO: Update with something realistic
int Shooter::GetFineAdjustmentSpeed() {return 20;}
int Shooter::GetCoarseAdjustmentSpeed() {return 200;}
