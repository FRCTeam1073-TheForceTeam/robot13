#ifndef SHOOTER_H
#define SHOOTER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define SHOOTER_SPEED 2000
#define SHOOTER_OFF 0
class Shooter: public Subsystem {
private:
	int speed, elevationAngle;
	int defaultSpeed, defaultElevationAngle;
	bool isShooterMotorOn;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANJaguar* elevationJag;
	Encoder* elevationEncoder;
	Encoder* wheelRPMEncoder;
	CANJaguar* shooterJag;
	DigitalInput* elevationTopSwitch;
	DigitalInput* elevationBottomSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Shooter();
	void InitDefaultCommand();
	void SetToDefaults();
	void IncrementSpeed(int speedIncrement);
	void IncrementAngle(int angleIncrement);
	void SetRawSpeed(int speed);	//used outside of HMI, maybe we add a Dash button?
	void SetRawElevationAngle(int elevationAngle);
	void UpdateDefaults(double distanceToTarget, double robotAngleToTarget);
	void ShooterOnOff(bool on);
	bool IsShooterMotorOn();
	float GetActualMotorSpeed();
	int GetSetSpeed();
	int GetSetElevationAngle();
	int GetDefaultSpeed();
	int GetDefaultElevationAngle();
	bool IsUpLimitPressed();
	bool IsDownLimitPressed();
	bool IsAtSetAngle();
	int GetFineAdjustmentSpeed();
	int GetCoarseAdjustmentSpeed();
	float GetEncoderSpeed();
	float GetVoltage();
	float GetCurrent();
	void TurnToSetAngle();
	void StopElevatorMotor();
	void SetRawAngle(int elevationAngle);
};
#endif
