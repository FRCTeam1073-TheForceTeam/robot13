#ifndef SHOOTER_H
#define SHOOTER_H
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#define SHOOTER_OFF 0
#define SHOOTER_DEFAULT_P 00.04
#define SHOOTER_DEFAULT_I 0.004
#define SHOOTER_DEFAULT_D 0.000
#define SHOOTER_DEFAULT_SPEED 2550
#define SHOOTER_WHEEL_DIAMETER_FEET 0.5f///NEEDS TO BE UPDATED
#define PRESET_FEEDER_STATION_ANGLE 45

//Are you hungry? I sure would hope so. we have like thirty defined PIs. I forget what they're called.
//WindRiver won't tell me the name of the one we defined and I don't want to hunt. Here's another
#define NEW_PI 3.14159f
typedef	enum {identical, additive, multiplicative} scaleType_t;
class Shooter: public Subsystem {
private:
	float scaleFactor;
	scaleType_t scaleType;
	int speed; 
	float elevationAngle;
	bool isShooterMotorOn;
	bool isElevatorEncoderFailed;
	void ConfigureJaguarEncoder(CANJaguar* jaguar);
	float ConvertVoltToAngle(float volts);
public:
	void SetJagPercentVoltage(float percentVoltage);
	void TurnToSetAngle();
	SmartCANJaguar* shooterJag;
	SpeedController* elevationVictor;
	StallableAnalogEncoder* elevationEncoder;
	IREncoder* encoder;
	Shooter();
	void InitDefaultCommand();
	void IncrementSpeed(int speedIncrement);
	void IncrementAngle(float angleIncrement);
	void ElevatorUpDown(bool up);
	void ElevatorOff();
	void SetElevatorEncoderFailed(bool isFailed);
	bool Shooter::GetElevationEncoderFailed();
	void SetRawSpeed(int speed);	//used outside of HMI, maybe we add a Dash button?
	void SetRawElevationAngle(float elevationAngle);
	void ShooterOnOff(bool on);
	void ShooterRamp(double rampPercent);
	bool IsShooterMotorOn();
	int GetFrontSetSpeed();	//speed used for shooter wheel
	float GetElevationAngle();
	bool IsAtSetAngle();
	float GetCurrentAngle();
	int GetFineAdjustmentSpeed();
	int GetCoarseAdjustmentSpeed();
	float GetFineAdjustmentAngle();
	void SetToFeederPresetAngle();
	float GetMinAngle();
	float GetMaxAngle();
	bool IsElevatorStalled();
	void ProcessVoltageData();
};
#endif
