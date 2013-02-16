#include "ClimberArms.h"
ClimberArms::ClimberArms() : Subsystem("Climber Arms"){
	leftWindowEncoder = RobotMap::climberArmLeftWindowEncoder;
	rightWindowEncoder = RobotMap::climberArmRightWindowEncoder;
	leftClimbWindowVictor = RobotMap::climberArmLeftClimbWindowVictor;
	rightClimbWindowVictor = RobotMap::climberArmRightClimbWindowVictor;
	climberIsSafe = true;
}
void ClimberArms::InitDefaultCommand() {}
float ClimberArms::EncoderVoltageTolerance(){return 0.15f;}

float ClimberArms::LeftEncoderUpVoltage(){return 3.3f;}
float ClimberArms::LeftEncoderMiddleVoltage(){return 2.6f;}
float ClimberArms::LeftEncoderDownVoltage(){return 1.9f;}

float ClimberArms::RightEncoderUpVoltage(){return 0.82f;}
float ClimberArms::RightEncoderMiddleVoltage(){return 1.4f;}
float ClimberArms::RightEncoderDownVoltage(){return 2.15f;}

void ClimberArms::ProcessWindowVoltageData(){
	leftWindowEncoder->ProcessVoltageData();
	rightWindowEncoder->ProcessVoltageData();
}
void ClimberArms::ResetWindowVoltageData(){
	leftWindowEncoder->ResetData();
	rightWindowEncoder->ResetData();
}
bool ClimberArms::WindowMotorStall(){return leftWindowEncoder->IsStall() || rightWindowEncoder->IsStall();}
//the most backwards logic ever.
void ClimberArms::WindowMotorsUp(bool offLeft, bool offRight){
	if(!offLeft) leftClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
		else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	if(!offRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
		else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}
void ClimberArms::WindowMotorsDown(bool offLeft, bool offRight){
	if(!climberIsSafe)
	{
		if(!offLeft) leftClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
			else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
		if(!offRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
			else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	}
}
void ClimberArms::WindowMotorsOff(){
	leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}
