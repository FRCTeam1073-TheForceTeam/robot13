#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Collector: public Subsystem {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* motor;
	DigitalInput* discOnShooterBed;
	AnalogChannel* discCountSensor;
	AnalogChannel* discUpsideDownSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Collector();
	void InitDefaultCommand();
	int  GetNumberOfDiscs();
	bool IsNextDiscUpsideDown();
	bool IsDiscOnShooterBed();
	void MotorOn();
	void MotorOff();
};
#endif
