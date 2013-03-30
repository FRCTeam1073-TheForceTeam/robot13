#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#define COLLECTOR_SPEED_ON 0.75
#define COLLECTOR_SPEED_OFF 0.0
class Collector: public Subsystem {
public:
	SpeedController* motor;
	Collector();
	void InitDefaultCommand();
	void MotorOn();
	void MotorReverse();
	void MotorOff();
};
#endif
