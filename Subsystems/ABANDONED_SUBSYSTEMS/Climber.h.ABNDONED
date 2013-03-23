#ifndef CLIMBER_H
#define CLIMBER_H
#define CLIMBER_OFF_SPEED 0.0f
#include "Commands/Subsystem.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#include "WPILib.h"
class Climber: public Subsystem {
private:
	bool ClimberOnOff;
	int encoderFailCount;
public:
	SmartCANJaguar* leftCIM;
	SmartCANJaguar* rightCIM;
	Climber();
	void InitDefaultCommand();
	void Climb(float joyY);
	void EngageClimber();
	void DisengageClimber();
	bool GetClimberOnOff();
};
#endif
