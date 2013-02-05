#ifndef SHOOTER_H
#define SHOOTER_H
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#define SHOOTER_SPEED 2000
#define SHOOTER_OFF 0
class Shooter: public Subsystem {
private:
	int speed, elevationAngle;
	int defaultSpeed, defaultElevationAngle;
	bool isShooterMotorOn;
public:
	void TurnToSetAngle();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANJaguar* elevationJag;
	Encoder* elevationEncoder;
	Encoder* wheelRPMEncoder;
	CANJaguar* frontJag;
	CANJaguar* backJag;
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
	int GetPrimarySetSpeed();	//speed used for shooter wheel
	int GetSupportSetSpeed();	//returns manipulation of GetPrimarySetSpeed() 
	int GetElevationAngle();
	int GetDefaultSpeed();
	int GetDefaultElevationAngle();
	bool IsAtSetAngle();
	float GetCurrentAngle();
	int GetFineAdjustmentSpeed();
	int GetCoarseAdjustmentSpeed();
	int GetFineAdjustmentAngle();
	int GetCoarseAdjustmentAngle();
	void StopElevatorMotor();
	void SetRawAngle(int elevationAngle);
	void SetPID(double P, double I, double D);
	void MoveElevatorMotor(float speed);
};
#endif
