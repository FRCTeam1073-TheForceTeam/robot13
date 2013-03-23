#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
#include "HardwarePortDefinitions.h"
class RobotMap {
public:
	static SpeedController* shooterElevationVictor;
	static SmartCANJaguar* driveTrainLeftMotor;
	static SmartCANJaguar* driveTrainRightMotor;
#ifdef ADD_SECONDARY_DRIVE
	static SmartCANJaguar* driveTrainSecondaryRightMotor;
	static SmartCANJaguar* driveTrainSecondaryLeftMotor;
#endif
	static SmartGyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static DigitalInput* collectorDiscOnShooterBed;
	static SmartCANJaguar* shooterFrontJag;
	static SmartCANJaguar* shooterBackJag;
	
	//Mag Encoders
	static StallableAnalogEncoder* shooterElevationEncoder;

	static void init();
};
#endif
