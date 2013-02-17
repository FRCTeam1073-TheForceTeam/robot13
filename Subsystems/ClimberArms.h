#ifndef CLIMBER_ARMS_H
#define CLIMBER_ARMS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#include "../RobotMap.h"
#define CHAINSAW_WINDOW_OFF_SPEED 0.0f
#define CHAINSAW_WINDOW_UP_SPEED 0.3f
#define CHAINSAW_WINDOW_DOWN_SPEED -0.3f
class ClimberArms : public Subsystem{
private:
	float leftArmUpEncVal;
	float leftArmMiddleEncVal;
	float leftArmDownEncVal;
	float rightArmUpEncVal;
	float rightArmMiddleEncVal;
	float rightArmDownEncVal;
public:
	ClimberArms();
	StallableAnalogEncoder* leftWindowEncoder;
	StallableAnalogEncoder* rightWindowEncoder;
	SpeedController* leftClimbWindowVictor;
	SpeedController* rightClimbWindowVictor;
	void InitDefaultCommand();
	float EncoderVoltageTolerance();
	float LeftEncoderUpVoltage();
	float LeftEncoderMiddleVoltage();
	float LeftEncoderDownVoltage();
	float RightEncoderUpVoltage();
	float RightEncoderMiddleVoltage();
	float RightEncoderDownVoltage();
	void ProcessWindowVoltageData();
	void ResetWindowVoltageData();
	bool WindowMotorStall();
	//up and down methods are the devel's spawn. pass in true for off.
	void WindowMotorsUp(bool offLeft, bool offRight);
	void WindowMotorsDown(bool offLeft, bool offRight);
	void WindowMotorsOff();
	bool climberIsSafe;
	void setArmEncVal(float leftUp, float leftMiddle, float leftDown, 
			          float rightUp, float rightMiddle,float rightDown);
};
#endif
