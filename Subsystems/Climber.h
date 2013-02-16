#ifndef CLIMBER_H
#define CLIMBER_H
#define CLIMBER_OFF_SPEED 0.0f
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Climber: public Subsystem {
private:
	bool ClimberOnOff;
	int encoderFailCount;
public:
	CANJaguar* leftCIM;
	CANJaguar* rightCIM;
	Climber();
	void ClimberJagConfig();
	void ConfigureJaguarForSpeedMode(CANJaguar* jaguar);
	void ConfigureJaguarForVoltageMode(CANJaguar* jaguar);
	void InitDefaultCommand();
	void Climb(float joyY);
	void EngageClimber();
	void DisengageClimber();
};
#endif
