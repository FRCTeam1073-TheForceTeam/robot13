#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static SpeedController* climberRightClimbWindowTalon;
	static CANJaguar* climberLeftCIM;
	static CANJaguar* climberRightCIM;
	static SpeedController* climberLeftClimbWindowTalon;
	static CANJaguar* driveTrainLeftMotor;
	static CANJaguar* driveTrainRightMotor;
	static Gyro* driveTrainGyro;
	static SpeedController* collectorMotor;
	static DigitalInput* collectorDiscOnShooterBed;
	static AnalogChannel* collectorDiscCountSensor;
	static AnalogChannel* collectorDiscUpsideDownSensor;
	static CANJaguar* shooterElevationJag;
	static Encoder* shooterWheelRPMEncoder;
	static CANJaguar* shooterFrontJag;
	static CANJaguar* shooterBackJag;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	//Mag Encoders
	static StallableAnalogEncoder* shooterElevationEncoder;
	static StallableAnalogEncoder* climberLeftWindowEncoder;
	static StallableAnalogEncoder* climberRightWindowEncoder;
	//LS
	static LimitSwitch* shooterElevationTopSwitch;
	static LimitSwitch* shooterElevationBottomSwitch;
	//Chainsaw Top/Bottom Switches
	static LimitSwitch* climberChainsawTopSwitch;
	static LimitSwitch* climberChainsawBottomSwitch;
	//Chainsaw Magnetic Encoder
	static Encoder* climberChainsawElevationMEncoder;
	static DigitalInput* velocity2;
	static DigitalInput* velocity1;
	static void init();
};
#endif
