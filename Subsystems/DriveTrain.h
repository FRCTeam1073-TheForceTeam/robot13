#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#include "../HardwarePortDefinitions.h"
class DriveTrain: public Subsystem {
public:
	SmartCANJaguar* leftMotor;
	SmartCANJaguar* rightMotor;
	SmartGyro* gyro;
#ifdef ADD_SECONDARY_DRIVE
	SmartCANJaguar* secondaryLeftMotor;
	SmartCANJaguar* secondaryRightMotor;
#endif
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
