#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
#include "HardwarePortDefinitions.h"
class RobotMap {
public:
	static SpeedController* climberArmLeftClimbWindowVictor;
	static SpeedController* climberArmRightClimbWindowVictor;
	static SpeedController* shooterElevationVictor;
	static CANJaguar* climberLeftCIM;
	static CANJaguar* climberRightCIM;
	static CANJaguar* driveTrainLeftMotor;
	static SmartCANJaguar* driveTrainRightMotor;
#ifdef ADD_SECONDARY_DRIVE
	static CANJaguar* driveTrainRightMotorSecondary;
	static CANJaguar* driveTrainLeftMotorSecondary;
#endif
	static SmartGyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static DigitalInput* collectorDiscOnShooterBed;
	static AnalogChannel* collectorDiscCountSensor;
	static AnalogChannel* collectorDiscUpsideDownSensor;
	static CANJaguar* shooterElevationJag;
	static SmartCANJaguar* shooterFrontJag;
	static CANJaguar* shooterBackJag;
	
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
