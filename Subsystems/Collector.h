#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define COLLECTOR_SPEED_ON -0.1
#define COLLECTOR_SPEED_OFF 0.0
class Collector: public Subsystem {
public:
	SpeedController* motor;
	DigitalInput* discOnShooterBed;
	AnalogChannel* discCountSensor;
	AnalogChannel* discUpsideDownSensor;
	Collector();
	void InitDefaultCommand();
	int  GetNumberOfDiscs();
	bool IsDiscOnShooterBed();
	void MotorOn();
	void MotorOff();
	bool overrided;
};
#endif
