#include "Shooter.h"
#include "../Robot.h"

#define ELEVATION_INCREMENT_ANGLE_SPEED_UP 0.4
#define ELEVATION_INCREMENT_ANGLE_SPEED_DOWN -0.3
#define ELEVATION_MIN_VOLTAGE 1.71
#define ELEVATION_MAX_VOLTAGE 2.34
#define ELEVATION_MIN_ANGLE 10.5
#define ELEVATION_MAX_ANGLE 52.2
	const float elevationThreshold = 2.0f;
	const float P = 0.4f;
Shooter::Shooter() : Subsystem("Shooter") {
	frontJag = RobotMap::shooterFrontJag;
	backJag = RobotMap::shooterBackJag;
	elevationEncoder = RobotMap::shooterElevationEncoder;
	elevationVictor = RobotMap::shooterElevationVictor;
    isShooterMotorOn = false;
	ConfigureJaguarEncoder(frontJag);
	ConfigureJaguarEncoder(backJag);
	SetPID(SHOOTER_DEFAULT_P, SHOOTER_DEFAULT_I, SHOOTER_DEFAULT_D);
	speed = SHOOTER_FRONT_DEFAULT_SPEED;
	rawBackSpeed = SHOOTER_BACK_DEFAULT_SPEED;
	scaleFactor = 1;
	scaleType = identical;
	isElevatorEncoderFailed = false;
	//we update these values with preferences after the shooter gets constructed
	//these two assignments ar emerely to ensure that these vars get some value in the realm of reality during construction
	elevatorMinVoltage = ELEVATION_MIN_VOLTAGE;
	elevatorMaxVoltage = ELEVATION_MAX_VOLTAGE;
}
void Shooter::InitDefaultCommand() {}
void Shooter::ShooterOnOff(bool on){
	isShooterMotorOn = on;
	if(on){
		printf("Front Jag:\t%d\tBack Jag:%d\tFrontCurrentSpeed:%lf\n", speed, GetBackSetSpeed(), frontJag->GetSpeed());
		frontJag->Set(speed);
		backJag->Set(GetBackSetSpeed());
	}
	else {
		printf("Shooter Off\n");
		frontJag->Set(SHOOTER_OFF);
		backJag->Set(SHOOTER_OFF);
		isShooterMotorOn = false;
	}
}
bool Shooter::IsShooterMotorOn() {return isShooterMotorOn;}
int Shooter::GetFrontSetSpeed() {return speed;}
int Shooter::GetBackSetSpeed(){
	//if(rawBackSpeedEnabled) return (int) rawBackSpeed;
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

	return (fabs(elevationAngle - GetCurrentAngle()) < elevationThreshold);
}
float Shooter::GetCurrentAngle(){
	float volts = elevationEncoder->GetVoltage();
	float angle = ConvertVoltToAngle(volts);
	printf ("Shooter::GetCurrentAngle angle is %f\n", angle);
	return angle;
}
//TODO: Update with something realistic
int Shooter::GetFineAdjustmentSpeed() {return 20;}
int Shooter::GetCoarseAdjustmentSpeed() {return 200;}
float Shooter::GetFineAdjustmentAngle() {return .1;}
void Shooter::TurnToSetAngle(){
	float currentAngle = Robot::shooter->GetCurrentAngle(); 
	float targetAngle = Robot::shooter->GetElevationAngle();
	float errorAngle = targetAngle - currentAngle;
	float motorOutput = errorAngle * P;
	if (motorOutput > ELEVATION_INCREMENT_ANGLE_SPEED_UP) 
		motorOutput = ELEVATION_INCREMENT_ANGLE_SPEED_UP;
	else if (motorOutput < ELEVATION_INCREMENT_ANGLE_SPEED_DOWN)
		motorOutput = ELEVATION_INCREMENT_ANGLE_SPEED_DOWN;
	elevationVictor->Set(motorOutput);
}
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

void Shooter::ElevatorUpDown(bool up)
{
	if(up)
		elevationVictor->Set(ELEVATION_INCREMENT_ANGLE_SPEED_UP);
	else
		elevationVictor->Set(ELEVATION_INCREMENT_ANGLE_SPEED_DOWN);
}

void Shooter::ElevatorOff()
{
	elevationVictor->Set(0.0); //turn off, this is a useless comment... -_-
}

float Shooter::GetMinAngle()
{
	return ConvertVoltToAngle(ELEVATION_MIN_VOLTAGE);
}

float Shooter::GetMaxAngle()
{
	return ConvertVoltToAngle(ELEVATION_MAX_VOLTAGE);
}

float Shooter::ConvertVoltToAngle(float volt)
{
	float voltDiff = ELEVATION_MAX_VOLTAGE - ELEVATION_MIN_VOLTAGE;//0.569
	float angleDiff = ELEVATION_MAX_ANGLE - ELEVATION_MIN_ANGLE;//40.6
	float degreesPerVolt = (angleDiff / voltDiff);//~71.35
	float angle =((volt - ELEVATION_MIN_VOLTAGE) * degreesPerVolt) + ELEVATION_MIN_ANGLE; 
	printf("ConvertVoltToAngle  Angle:%f\t Volt:%f\n", angle, volt);
	return angle;
}

bool Shooter::IsElevatorStalled()
{
	return elevationEncoder->IsStall();
}

void Shooter::ProcessVoltageData()
{
	elevationEncoder->ProcessVoltageData();
}
void Shooter::SetToFeederPresetAngle() {
	SetRawElevationAngle(PRESET_FEEDER_STATION_ANGLE);
}
void Shooter::UpdateElevatorAngleConstants(float vmin, float vmax){
	elevatorMinVoltage = vmin;
	elevatorMaxVoltage = vmax;
}
