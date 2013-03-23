#ifndef CLIMBER_ARMS_H
#define CLIMBER_ARMS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../WPILibExtensions/WPILibExtensions.h"
#include "../RobotMap.h"
/* A note about voltages on the ClimberArms Victor and Window Motors
 * A Positive Voltage on the Left Victor makes the left Window Motor go down
 * A Negative Voltage on the Right Victor makes the right Window Motor go up
 */ 
#define CHAINSAW_WINDOW_OFF_SPEED 0.0f
#define CHAINSAW_WINDOW_UP_SPEED 0.6f
#define CHAINSAW_WINDOW_DOWN_SPEED 0.4f
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
	void setArmEncVal(float leftUp, float leftMiddle, float leftDown, 
			          float rightUp, float rightMiddle,float rightDown);
	void ManualUp();
	void ManualDown();
};
#endif
