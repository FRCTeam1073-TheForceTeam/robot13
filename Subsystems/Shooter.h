#ifndef SHOOTER_H
#define SHOOTER_H
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#define SHOOTER_OFF 0
#define SHOOTER_DEFAULT_P 00.04
#define SHOOTER_DEFAULT_I 0.004
#define SHOOTER_DEFAULT_D 0.000
#define SHOOTER_FRONT_DEFAULT_SPEED 2550
#define SHOOTER_BACK_DEFAULT_SPEED  2550 

typedef	enum {identical, additive, multiplicative} scaleType_t;

class Shooter: public Subsystem {
private:
	float scaleFactor;
	scaleType_t scaleType;
	int speed; 
	float elevationAngle;
	int defaultSpeed, defaultElevationAngle;
	bool isShooterMotorOn;
	bool rawBackSpeedEnabled;	//hack for now...
	double rawBackSpeed;	//hack for now...
	void ConfigureJaguarEncoder(CANJaguar* jaguar);
public:
	void TurnToSetAngle();
	CANJaguar* elevationJag;
	CANJaguar* frontJag;
	CANJaguar* backJag;
	DigitalInput* elevationBottomSwitch;
	SpeedController* elevationVictor;
	StallableAnalogEncoder* elevationEncoder;
	Shooter();
	void InitDefaultCommand();
	void SetToDefaults();
	void IncrementSpeed(int speedIncrement);
	void IncrementAngle(float angleIncrement);
	void SetRawSpeed(int speed);	//used outside of HMI, maybe we add a Dash button?
	void SetRawBackSpeed(int speed);
	void SetRawElevationAngle(float elevationAngle);
	void UpdateDefaults(double distanceToTarget, double robotAngleToTarget);
	void ShooterOnOff(bool on);
	bool IsShooterMotorOn();
	int GetFrontSetSpeed();	//speed used for shooter wheel
	int GetBackSetSpeed();	//returns manipulation of GetFrontSetSpeed() 
	void SetBackMode(scaleType_t inScaleType, float inScaleFactor);		//sets scaling behavior of rear wheel speed relative to front
	float GetElevationAngle();
	int GetDefaultSpeed();
	int GetDefaultElevationAngle();
	bool IsAtSetAngle();
	float GetCurrentAngle();
	int GetFineAdjustmentSpeed();
	int GetCoarseAdjustmentSpeed();
	float GetFineAdjustmentAngle();
	void StopElevatorMotor();
	void SetPID(double P, double I, double D);
	void MoveElevatorMotor(float speed);
};
#endif
