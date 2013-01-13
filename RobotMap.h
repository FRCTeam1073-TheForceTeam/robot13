#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
#define GREG "foo"


/*
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static AnalogChannel* lightLightRing;
	static Ultrasonic* navigationRangeFinder;
	static AnalogChannel* navigationAltimiter;
	static Servo* climberRightServo;
	static Servo* climberLeftServo;
	static CANJaguar* driveTrainLeftDriveMotor;
	static CANJaguar* driveTrainRightDriveMotor;
	static CANJaguar* shooterElevationJag;
	static Encoder* shooterElevationEncoder;
	static CANJaguar* shooterShooterJag;
	static Encoder* shooterShooterEncoder;
	static DigitalInput* shooterElevatorTopSwitch;
	static DigitalInput* shooterElevatorBottomSwitch;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static void init();
};
#endif
