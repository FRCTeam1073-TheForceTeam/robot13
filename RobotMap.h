#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
#include "HardwarePortDefinitions.h"
#include "WPILibExtensions/IREncoder.h"
class RobotMap {
public:
	static SpeedController* climberArmLeftClimbWindowVictor;
	static SpeedController* climberArmRightClimbWindowVictor;
	static SpeedController* shooterElevationVictor;
	static SmartCANJaguar* climberLeftCIM;
	static SmartCANJaguar* climberRightCIM;
	static SmartCANJaguar* driveTrainLeftMotor;
	static SmartCANJaguar* driveTrainRightMotor;
	static Relay* rollerMotor;
	static IREncoder* newShooterIREncoder;
#ifdef ADD_SECONDARY_DRIVE
	static SmartCANJaguar* driveTrainSecondaryRightMotor;
	static SmartCANJaguar* driveTrainSecondaryLeftMotor;
#endif
	static SmartGyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static DigitalInput* collectorDiscOnShooterBed;
	static AnalogChannel* collectorDiscCountSensor;
	static SmartCANJaguar* shooterJag;
	
	//Mag Encoders
	static StallableAnalogEncoder* shooterElevationEncoder;
	static StallableAnalogEncoder* climberArmLeftWindowEncoder;
	static StallableAnalogEncoder* climberArmRightWindowEncoder;
	//Chainsaw Magnetic Encoder
	static DigitalInput* velocity1;
	static DigitalInput* velocity2;
	static void init();
};
#endif
