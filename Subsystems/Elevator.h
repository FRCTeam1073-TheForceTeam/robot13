#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class Elevator : public Subsystem{
public:
	Elevator();
	void InitDefaultCommand();
	void MotorOff();
	SpeedController* motor;
	StallableAnalogEncoder* encoder;
	float GetAngle();
	float GetCurrentAngle();
	void IncrementAngle(float angleIncrement);
	void SetRawAngle(float newAngle);
	void TurnToSetAngle();
	void MotorUpDown(bool up);
	bool Stall();
	void SetToFeederAngle();
	void SetEncoderFailed(bool isFailed);
	bool GetEncoderFailed();
	bool IsAtSetAngle();
	float GetMinAngle();
	float GetMaxAngle();
private:
	float ConvertVoltToAngle(float volt);
	float angle;
	bool isEncoderFailed;
};
#endif
