#include "ClimberArms.h"
ClimberArms::ClimberArms() : Subsystem("Climber Arms"){
	leftWindowEncoder = RobotMap::climberArmLeftWindowEncoder;
	rightWindowEncoder = RobotMap::climberArmRightWindowEncoder;
	leftClimbWindowVictor = RobotMap::climberArmLeftClimbWindowVictor;
	rightClimbWindowVictor = RobotMap::climberArmRightClimbWindowVictor;
}
void ClimberArms::InitDefaultCommand() {}
float ClimberArms::EncoderVoltageTolerance(){return 1.25f;}
float ClimberArms::LeftEncoderUpVoltage(){return 3.3f;}
float ClimberArms::LeftEncoderMiddleVoltage(){return 2.6f;}
float ClimberArms::LeftEncoderDownVoltage(){return 1.9f;}
float ClimberArms::RightEncoderUpVoltage(){return 0.8f;}
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
void ClimberArms::WindowMotorsUp(bool moveLeft, bool moveRight){
	if(moveLeft) leftClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
		else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	if(moveRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
		else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
}
void ClimberArms::WindowMotorsDown(bool moveLeft, bool moveRight){
	if(moveLeft) leftClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
		else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	if(moveRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
		else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);	
}
void ClimberArms::WindowMotorsOff(){
	leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}
