#include "Shooter.h"
#include "../Robot.h"
#include "../Commands/ShooterDefaultCommand.h"
Shooter::Shooter() : Subsystem("Shooter") {
	elevationJag = RobotMap::shooterElevationJag;
	frontJag = RobotMap::shooterFrontJag;
	backJag = RobotMap::shooterBackJag;
	elevationBottomSwitch = RobotMap::shooterElevationBottomSwitch;
	elevationEncoder = RobotMap::shooterElevationEncoder;
	elevationVictor = RobotMap::shooterElevationVictor;
	printf("Limit Test = %s\n", LimitPressed(elevationBottomSwitch) ? "true" : "false");
    isShooterMotorOn = false;
	ConfigureJaguarEncoder(frontJag);
	ConfigureJaguarEncoder(backJag);
	SetPID(SHOOTER_DEFAULT_P, SHOOTER_DEFAULT_I, SHOOTER_DEFAULT_D);
	speed = SHOOTER_FRONT_DEFAULT_SPEED;
	rawBackSpeed = SHOOTER_BACK_DEFAULT_SPEED;
	scaleFactor = 1;
	scaleType = identical;
	isElevatorEncoderFailed = false;
}
void Shooter::InitDefaultCommand() {SetDefaultCommand(new ShooterDefaultCommand());}
void Shooter::ShooterOnOff(bool on){
	isShooterMotorOn = on;
	if(on){
		printf("Front Jag:\t%d", speed);
		printf("Back Jag:\t%d", GetBackSetSpeed());
		frontJag->Set(speed);
		backJag->Set(GetBackSetSpeed());
	}
	else {
		frontJag->Set(SHOOTER_OFF);
		backJag->Set(SHOOTER_OFF);
		isShooterMotorOn = false;
	}
}
bool Shooter::IsShooterMotorOn() {return isShooterMotorOn;}
int Shooter::GetFrontSetSpeed() {return speed;}
int Shooter::GetBackSetSpeed(){
	if(rawBackSpeedEnabled) return (int) rawBackSpeed;
	//TODO: Update with better math. 
	
	switch(scaleType){
	case additive:
		return (int) (speed + scaleFactor);
		break;
	case multiplicative:
		return (int) (speed * scaleFactor);
		break;
	default:
		return speed;
	}
}

void Shooter::SetElevatorEncoderFailed(bool isFailed) {
	isElevatorEncoderFailed = isFailed;
}

bool Shooter::GetElevationEncoderFailed() {
	return isElevatorEncoderFailed;
}

void Shooter::SetBackMode(scaleType_t inScaleType, float inScaleFactor)
{
	scaleType = inScaleType;
	scaleFactor = inScaleFactor; 
	char *scaleTypeWords;
	
	switch (scaleType) {
		case identical:
			scaleTypeWords = "identical";
			break;
		case additive:
			scaleTypeWords = "additive";
			break;
		case multiplicative:
			scaleTypeWords = "multiplicative";
			break;
		default:
			scaleTypeWords = "unknown";
	}
	printf("Setting shooter to scaleType %s scaleFactor %f\n", 
			scaleTypeWords, scaleFactor);
}

float Shooter::GetElevationAngle() {return elevationAngle;}
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
	Robot::allignmentData->SendCurrentSpeed(speed);
}
void Shooter::IncrementAngle(float angleIncrement){
	printf ("IncrementAngle changing by %f\n", angleIncrement);
	elevationAngle += angleIncrement;
	TurnToSetAngle();
	//printf ("it is now %d\n", elevationangle);
	Robot::allignmentData->SendCurrentAngle(elevationAngle);
}
//Figured this might be useful if we want to quickly put the speed to a certain preset
void Shooter::SetRawSpeed(int speed) {
	if(speed < 0 ) return;
	IncrementSpeed(speed - this->speed);
}
void Shooter::SetRawBackSpeed(int speed){
	rawBackSpeed = speed;
	rawBackSpeedEnabled = true;
}
void Shooter::SetRawElevationAngle(float elevationAngle) {
	this->elevationAngle = elevationAngle;
	Robot::allignmentData->SendCurrentAngle(elevationAngle);
}
bool Shooter::IsAtSetAngle(){
	if (elevationAngle == GetCurrentAngle()){
		return true;
	}
	return false;
}
#warning "Whoever's area of expertise this is may want to look at the below method"
float Shooter::GetCurrentAngle(){
	float angle = elevationJag->GetOutputVoltage();
	printf ("Shooter::GetCurrentAngle angle is %f\n", angle);
	return angle;
}
//TODO: Update with something realistic
int Shooter::GetFineAdjustmentSpeed() {return 20;}
int Shooter::GetCoarseAdjustmentSpeed() {return 200;}
float Shooter::GetFineAdjustmentAngle() {return .1;}
void Shooter::TurnToSetAngle(){
	//TODO: Hardware calls to adjust angle to angle variable
}
void Shooter::StopElevatorMotor(){elevationJag->Set(SHOOTER_OFF);}
void Shooter::MoveElevatorMotor(float speed){elevationJag->Set(speed);}
void Shooter::SetPID(double P, double I, double D){
	printf("Setting P:\t%f\nI:\t%f\nD:\t%f\n", P, I, D);
	frontJag->SetPID(P, I, D);
	backJag->SetPID(P, I, D);
}
void Shooter::ConfigureJaguarEncoder(CANJaguar* jaguar){
	jaguar->ChangeControlMode(CANJaguar::kSpeed);
	jaguar->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
	jaguar->ConfigEncoderCodesPerRev(360);	//maybe 360
	jaguar->EnableControl();			
}
