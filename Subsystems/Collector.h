#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define COLLECTOR_SPEED_ON -0.4
#define COLLECTOR_SPEED_OFF 0.0
class Collector: public Subsystem {
public:
	SpeedController* motor;
	DigitalInput* discOnShooterBed;
	AnalogChannel* discUpsideDownSensor;
	Collector();
	void InitDefaultCommand();
	bool IsDiscOnShooterBed();
	void MotorOn();
	void MotorOff();
	bool overrided;
};
#endif
