#include "ClimberArms.h"
ClimberArms::ClimberArms() : Subsystem("Climber Arms"){
	leftWindowEncoder = RobotMap::climberArmLeftWindowEncoder;
	rightWindowEncoder = RobotMap::climberArmRightWindowEncoder;
	leftClimbWindowVictor = RobotMap::climberArmLeftClimbWindowVictor;
	rightClimbWindowVictor = RobotMap::climberArmRightClimbWindowVictor;
	leftArmUpEncVal = 3.16f;
	leftArmDownEncVal = 2.1f;
	leftArmMiddleEncVal = (leftArmUpEncVal + leftArmDownEncVal)/2;
	rightArmUpEncVal = 0.75;
	rightArmDownEncVal = 2.1f;
	rightArmMiddleEncVal = (rightArmUpEncVal + rightArmDownEncVal)/2;
}
void ClimberArms::InitDefaultCommand() {}
float ClimberArms::EncoderVoltageTolerance(){return 0.15f;}

float ClimberArms::LeftEncoderUpVoltage(){return leftArmUpEncVal;}
float ClimberArms::LeftEncoderMiddleVoltage(){return leftArmMiddleEncVal;}
float ClimberArms::LeftEncoderDownVoltage(){return leftArmDownEncVal;}

float ClimberArms::RightEncoderUpVoltage(){return rightArmUpEncVal;}
float ClimberArms::RightEncoderMiddleVoltage(){return rightArmMiddleEncVal;}
float ClimberArms::RightEncoderDownVoltage(){return rightArmDownEncVal;}

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
	if(!offLeft) leftClimbWindowVictor->Set(-1 * CHAINSAW_WINDOW_UP_SPEED);
		else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	if(!offRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
		else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}
void ClimberArms::WindowMotorsDown(bool offLeft, bool offRight){
	if(!offLeft) leftClimbWindowVictor->Set(-1 * CHAINSAW_WINDOW_DOWN_SPEED);
		else leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	if(!offRight) rightClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
		else rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}
void ClimberArms::WindowMotorsOff(){
	leftClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
	rightClimbWindowVictor->Set(CHAINSAW_WINDOW_OFF_SPEED);
}


void ClimberArms::setArmEncVal(float leftUp, float leftMiddle, float leftDown, 
			          float rightUp, float rightMiddle,float rightDown){
leftArmUpEncVal = leftUp;
leftArmMiddleEncVal = leftMiddle;
leftArmDownEncVal = leftDown;
rightArmUpEncVal = rightUp;
rightArmMiddleEncVal = rightMiddle;
rightArmDownEncVal = rightDown;
printf("Setting leftUpEncVal %f, leftMidEncVal %f , leftDownEncVal %f \n", leftArmUpEncVal,
		leftArmMiddleEncVal, leftArmDownEncVal);
printf("Setting rightUpEncVal %f, rightMidEncVal %f , rightDownEncVal %f \n", rightArmUpEncVal,
		rightArmMiddleEncVal, rightArmDownEncVal);
}

void ClimberArms::ManualUp(){
	leftClimbWindowVictor->Set(-1 * CHAINSAW_WINDOW_UP_SPEED);
	rightClimbWindowVictor->Set(CHAINSAW_WINDOW_UP_SPEED);
}

void ClimberArms::ManualDown(){
	leftClimbWindowVictor->Set(CHAINSAW_WINDOW_DOWN_SPEED);
	rightClimbWindowVictor->Set(-1 * CHAINSAW_WINDOW_DOWN_SPEED);
}
