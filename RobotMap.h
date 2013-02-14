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
	static CANJaguar* driveTrainRightMotor;
	static Gyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static DigitalInput* collectorDiscOnShooterBed;
	static AnalogChannel* collectorDiscCountSensor;
	static AnalogChannel* collectorDiscUpsideDownSensor;
	static CANJaguar* shooterElevationJag;
	static CANJaguar* shooterFrontJag;
	static CANJaguar* shooterBackJag;
	
	//Mag Encoders
	static StallableAnalogEncoder* shooterElevationEncoder;
	static StallableAnalogEncoder* climberArmLeftWindowEncoder;
	static StallableAnalogEncoder* climberArmRightWindowEncoder;
	//LS
	static DigitalInput* shooterElevationBottomSwitch;
	//Chainsaw Magnetic Encoder
	static DigitalInput* velocity1;
	static DigitalInput* velocity2;
	static void init();
};
#endif
