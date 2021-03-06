#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
#include "HardwarePortDefinitions.h"
#include "WPILibExtensions/IREncoder.h"
class RobotMap {
public:
	static SpeedController* shooterElevationVictor;
	static SmartCANJaguar* driveTrainLeftMotor;
	static SmartCANJaguar* driveTrainRightMotor;
	static IREncoder* newShooterIREncoder;
#ifdef ADD_SECONDARY_DRIVE
	static SmartCANJaguar* driveTrainSecondaryRightMotor;
	static SmartCANJaguar* driveTrainSecondaryLeftMotor;
#endif
	static SmartGyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static SmartCANJaguar* shooterJag;
	
	//Mag Encoders
	static StallableAnalogEncoder* shooterElevationEncoder;

	static void init();
};
#endif
