#ifndef ROLLER_H
#define ROLLER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
class Roller : public Subsystem{
public:
	Roller();
	void MotorForward();
	void MotorOff();
	Relay* motor;
};
#endif
