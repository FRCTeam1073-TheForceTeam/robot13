#include "Shooter.h"
#include "../Robot.h"
#include "../Commands/ShooterPID.h"

//this will require optimization
#define ELEVATION_INCREMENT_SCALE_FACTOR 1.0f	//was 1.0
#define ELEVATION_INCREMENT_ANGLE_SPEED_UP 1.0 * ELEVATION_INCREMENT_SCALE_FACTOR
#define ELEVATION_INCREMENT_ANGLE_SPEED_DOWN -1.0 * ELEVATION_INCREMENT_SCALE_FACTOR
#define ELEVATION_MIN_VOLTAGE 1.71
#define ELEVATION_MAX_VOLTAGE 2.34
#define ELEVATION_MIN_ANGLE 10.5
#define ELEVATION_MAX_ANGLE 52.2
	const float elevationThreshold = 0.5f;
Shooter::Shooter() : Subsystem("Shooter") {
	shooterJag = RobotMap::shooterJag;
	encoder = RobotMap::newShooterIREncoder;
    isShooterMotorOn = false;
	ConfigureJaguarEncoder(shooterJag);
	speed = SHOOTER_DEFAULT_SPEED;
	scaleFactor = 1;
	scaleType = identical;
}
void Shooter::InitDefaultCommand() {SetDefaultCommand(new ShooterPID());}
void Shooter::ShooterOnOff(bool on){
	isShooterMotorOn = on;
	if(on){
		printf("Shooter ON with Speed:%f\n", (float)speed);
	}
	else {
		printf("Shooter Off\n");
		//previousSpeed = speed;
		//speed = 0.0;
		shooterJag->Set(SHOOTER_OFF);//redundant
		isShooterMotorOn = false;//redundant too
	}
}
void Shooter::ShooterRamp(double rampPercent){
	//shooterJag->Set(speed * rampPercent);
}
bool Shooter::IsShooterMotorOn() {return isShooterMotorOn;}
int Shooter::GetFrontSetSpeed() {return speed;}
void Shooter::IncrementSpeed(int speedIncrement){
	speed += speedIncrement;
	if(isShooterMotorOn) 
	{
		//shooterJag->Set(speed);
	}
	Robot::allignmentData->SendCurrentSpeed(speed);
}

//Figured this might be useful if we want to quickly put the speed to a certain preset
void Shooter::SetRawSpeed(int speed) {
	if(speed < 0 ) return;
	IncrementSpeed(speed - this->speed);
}

//TODO: Update with something realistic
int Shooter::GetFineAdjustmentSpeed() {return 20;}
int Shooter::GetCoarseAdjustmentSpeed() {return 50;}

void Shooter::ConfigureJaguarEncoder(CANJaguar* jaguar){
	jaguar->ChangeControlMode(CANJaguar::kPercentVbus);
	//jaguar->SetVoltageRampRate(1.0);
	jaguar->EnableControl();			
}


void Shooter::SetJagPercentVoltage(float percentVoltage)
{
	if (isShooterMotorOn)
		shooterJag->Set(percentVoltage);
	else
		shooterJag->Set(0);
	
	//shooterJag->Set(0.6);
}

