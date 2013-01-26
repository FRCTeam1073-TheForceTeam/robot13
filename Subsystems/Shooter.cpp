#include "Shooter.h"
#include "../Robotmap.h"
#include "../Commands/UpdateCalculatedShooterValues.h"
Shooter::Shooter() : Subsystem("Shooter") , StallableJaguar() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	elevationJag = RobotMap::shooterElevationJag;
	elevationEncoder = RobotMap::shooterElevationEncoder;
	wheelRPMEncoder = RobotMap::shooterWheelRPMEncoder;
	primaryJag = RobotMap::shooterPrimaryJag;
	supportJag = RobotMap::shooterSupportJag;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	isShooterMotorOn = false;
}
void Shooter::InitDefaultCommand() {SetDefaultCommand(new UpdateCalculatedShooterValues());}
void Shooter::ShooterOnOff(bool on){
	isShooterMotorOn = on;
	if(on){
		primaryJag->Set(speed);
		supportJag->Set(GetSupportSetSpeed());
	}
	else {
		primaryJag->Set(SHOOTER_OFF);
		supportJag->Set(SHOOTER_OFF);
	}
}
bool Shooter::IsShooterMotorOn() {return isShooterMotorOn;}
int Shooter::GetPrimarySetSpeed() {return speed;}
int Shooter::GetSupportSetSpeed(){
	//TODO: Update with better math. 
	int math = 2;
	return speed - math;
}
int Shooter::GetSetElevationAngle() {return elevationAngle;}
int Shooter::GetDefaultSpeed() {return defaultSpeed;}
int Shooter::GetDefaultElevationAngle() {return defaultElevationAngle;}
void Shooter::SetToDefaults(){
	IncrementSpeed(defaultSpeed - speed);
	elevationAngle = defaultElevationAngle;
}
void Shooter::UpdateDefaults(double distanceToTarget, double robotAngleToTarget){
	//TODO: Takes Arguements and sets the speed and elevationAngle arguments
}
void Shooter::IncrementSpeed(int speedIncrement){
	speed += speedIncrement;
	if(isShooterMotorOn) ShooterOnOff(true);
}
void Shooter::IncrementAngle(int angleIncrement){
	elevationAngle += angleIncrement;
	TurnToSetAngle();
}
//Figured this might be useful if we want to quickly put the speed to a certain preset
void Shooter::SetRawSpeed(int speed) {
	if(speed < 0 ) return;
	IncrementSpeed(speed - this->speed);
}
void Shooter::SetRawElevationAngle(int elevationAngle) {
	this->elevationAngle = elevationAngle;
}
bool Shooter::IsAtSetAngle(){
	//TODO: Use elevator encoder to determine where we are and where we'd like to be
	return false;
}
//TODO: Update with something realistic
int Shooter::GetFineAdjustmentSpeed() {return 20;}
int Shooter::GetCoarseAdjustmentSpeed() {return 200;}
int Shooter::GetFineAdjustmentAngle() {return 3;}
int Shooter::GetCoarseAdjustmentAngle() {return 15;}
void Shooter::TurnToSetAngle(){
	//TODO: Hardware calls to adjust angle to angle variable
}
void Shooter::StopElevatorMotor(){elevationJag->Set(SHOOTER_OFF);}
