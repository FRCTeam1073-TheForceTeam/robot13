#ifndef ROLLER_H
#define ROLLER_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../RobotMap.h"
#define SPEED_FORWARD 1
#define SPEED_REVERSE -1
#define SPEED_OFF 0
class Roller : public Subsystem{
public:
	Roller();
	void MotorForward();
	void MotorReverse();
	void MotorOff();
	Relay* motor;
};
#endif
