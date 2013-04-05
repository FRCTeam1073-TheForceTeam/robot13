#include "Elevator.h"
#include "../Robot.h"
#define MAX_VOLTAGE 2.694f
#define MAX_ANGLE 25.0f
#define MIN_VOLTAGE 2.314f
#define MIN_ANGLE -2.1f
#define ELEVATION_VOLTAGE_THRESHOLD 0.5f
#define ELEVATION_MOTOR_VOLTAGE_UP 1.0
#define ELEVATION_MOTOR_VOLTAGE_DOWN -1.0
#define ELEVATION_FEEDER_ANGLE 45.0f	//this really SHOULD be just some proportion between min/max...
Elevator::Elevator() : Subsystem("Elevator"){
	motor = RobotMap::shooterElevationVictor;
	encoder = RobotMap::shooterElevationEncoder;
	isEncoderFailed = false;
}
void Elevator::InitDefaultCommand(){}
float Elevator::GetAngle(){return angle;}
float Elevator::GetCurrentAngle(){
	float angle = ConvertVoltToAngle(encoder->GetVoltage());
	printf ("Shooter::GetCurrentAngle angle is %f\n", angle);
	return angle; 
}
void Elevator::MotorOff(){motor->Set(0.0f);}
void Elevator::TurnToSetAngle(){
	const float P = 0.4f;
	const float errorAngle = angle - GetCurrentAngle();
	float motorOutput = errorAngle * P;
	if (motorOutput > ELEVATION_MOTOR_VOLTAGE_UP) 
		motorOutput = ELEVATION_MOTOR_VOLTAGE_UP;
	else if (motorOutput < ELEVATION_MOTOR_VOLTAGE_DOWN)
		motorOutput = ELEVATION_MOTOR_VOLTAGE_DOWN;
	motor->Set(motorOutput);	
}
void Elevator::IncrementAngle(float angleIncrement){
	angle += angleIncrement;
	TurnToSetAngle();
	Robot::allignmentData->SendCurrentAngle(angle);
}
void Elevator::SetRawAngle(float newAngle){angle = newAngle;}

float Elevator::ConvertVoltToAngle(float volt){
	float voltDiff = MAX_VOLTAGE - MIN_VOLTAGE;
	float angleDiff = MAX_ANGLE - MIN_ANGLE;
	float degreesPerVolt = (angleDiff / voltDiff);//72 manufacturing spec
	float angleValue =((volt - MIN_VOLTAGE) * degreesPerVolt) + MIN_ANGLE; 
	printf("ConvertVoltToAngle  Angle:%f\t Volt:%f\n", angle, volt);
	return angleValue;
}

void Elevator::MotorUpDown(bool up){motor->Set(up ? ELEVATION_MOTOR_VOLTAGE_UP : ELEVATION_MOTOR_VOLTAGE_DOWN);}
bool Elevator::Stall() {return encoder->IsStall();}
void Elevator::SetToFeederAngle(){SetRawAngle(ELEVATION_FEEDER_ANGLE);}
void Elevator::SetEncoderFailed(bool isFailed) {isEncoderFailed = isFailed;}
bool Elevator::GetEncoderFailed(){return isEncoderFailed;}
bool Elevator::IsAtSetAngle(){return (fabs(angle - GetCurrentAngle()) < ELEVATION_VOLTAGE_THRESHOLD);}
float Elevator::GetMinAngle(){return ConvertVoltToAngle(MIN_VOLTAGE);}
float Elevator::GetMaxAngle(){return ConvertVoltToAngle(MAX_VOLTAGE);}
