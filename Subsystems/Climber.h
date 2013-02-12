#ifndef CLIMBER_H
#define CLIMBER_H
#define CHAINSAW_DOWN_SPEED -0.5
#define CHAINSAW_UP_SPEED 0.5
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "..\WPILibExtensions\StallableAnalogEncoder.h"
class Climber: public Subsystem {
private:
	bool ClimberOnOff;
	int encoderFailCount;
public:
	SpeedController* leftClimbWindowTalon;
	SpeedController* rightClimbWindowTalon;
	CANJaguar* leftCIM;
	CANJaguar* rightCIM;
    StallableAnalogEncoder* leftWindowEncoder;
	StallableAnalogEncoder* rightWindowEncoder;
	
	Climber();
	void ClimberJagConfig();
	void InitDefaultCommand();
	void Climb(float yPosition);
	bool getClimberOnOff();
	void EngageClimber();
	void DisengageClimber();
	void ChainsawUp();
	void ChainsawDown();
	void ChainsawMovementOff();
	float EncoderUpVoltage();
	float EncoderMiddleVoltage();
	float EncoderDownVoltage();
	void ProcessWindowVoltageData();
	void ResetWindowVoltageData();
	bool WindowMotorStall();
};
#endif
