#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class DriveTrain: public Subsystem {
public:
	CANJaguar* leftMotor;
	SmartCANJaguar* rightMotor;
	SmartGyro* gyro;
	CANJaguar* leftMotorSecondary;
	CANJaguar* rightMotorSecondary;
	DriveTrain();
	void InitDefaultCommand();
	void Move(float left, float right);
	void Stop();
	void GetPosition (float &left,float &right);
	float TicksToInches (float ticks);
private:
	void ConfigureJaguarEncoder(CANJaguar* jaguar);
};
#endif
