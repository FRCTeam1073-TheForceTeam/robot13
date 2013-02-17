#include "ChainsawPosition.h"
#include "../JoystickButtonSheet.h"
//#define TIMEOUT
//#define STALL_DETECTION_ON
ChainsawPosition::ChainsawPosition(Destination destination){
	Requires(Robot::climberArms);
#ifdef TIMEOUT
	SetTimeout(3.0);
#endif
	this->destination = destination;
	Reset();
}
void ChainsawPosition::Initialize(){
	puts("init");
	Reset();
	switch(destination){
	case up:
		voltageLeft = Robot::climberArms->LeftEncoderUpVoltage();
		voltageRight = Robot::climberArms->RightEncoderUpVoltage();
		break;
	case middle:
		float left = Robot::climberArms->leftWindowEncoder->GetVoltage();
		float right = Robot::climberArms->rightWindowEncoder->GetVoltage();
		voltageLeft = Robot::climberArms->LeftEncoderMiddleVoltage();
		voltageRight = Robot::climberArms->RightEncoderMiddleVoltage();
		goUpInMiddle = left < voltageLeft || right < voltageRight;
	    break;
	case down:
		if(false && !Robot::oi->getRightStick()->GetRawButton(RIGHT_CLIMBER_SAFETY_BTN)) {
			puts("Safety not pressed, cancelling!!!!!!!!!");
			Cancel();
		}
		voltageLeft = Robot::climberArms->LeftEncoderDownVoltage();
		voltageRight = Robot::climberArms->RightEncoderDownVoltage();
		break;
	default: break;
	}
}
void ChainsawPosition::Execute(){
	SmartDashboard::PutNumber("Left Mag", Robot::climberArms->leftWindowEncoder->GetVoltage());
	SmartDashboard::PutNumber("Right Mag", Robot::climberArms->rightWindowEncoder->GetVoltage());
	Robot::climberArms->ProcessWindowVoltageData();
	float vleft = Robot::climberArms->leftWindowEncoder->GetVoltage();
	float vright = Robot::climberArms->rightWindowEncoder->GetVoltage();
	printf("Voltage Right: %f Target Voltage Right: %f State: %s\n", vright, voltageRight, right ? "true" : "false");
	switch(destination){
	case up:
		Robot::climberArms->WindowMotorsUp(left, right);
		if(!left)left = vleft >= voltageLeft;
		if(!right)right = vright <= voltageRight;
		printf("Right %s\n", right ? "true" : "false");
		break;
	case middle:
		if(goUpInMiddle)
			Robot::climberArms->WindowMotorsUp(left, right);
		else
			Robot::climberArms->WindowMotorsDown(left, right);	
		if(!left)left = fabs(vleft - voltageLeft) <= Robot::climberArms->EncoderVoltageTolerance();
		if(!right)right = fabs(vright - voltageRight) <= Robot::climberArms->EncoderVoltageTolerance();
		break;
	case down:
			Robot::climberArms->WindowMotorsDown(left, right);
			if(!left)left = (vleft <= voltageLeft);
			if(!right) right = (vright >= voltageRight);
		
		break;
	default: break;
	}
	left = 
#ifdef STALL_DETECTION_ON
	Robot::climberArms->leftWindowEncoder->IsStall() ||
#endif
	left;
	right = 
#ifdef STALL_DETECTION_ON
	Robot::climberArms->rightWindowEncoder->IsStall() ||
#endif
	right;
}
bool ChainsawPosition::IsFinished(){
	printf("Left: %s Right: %s\n", left ? "true" : "false", right ? "true" : "false");
	return
#ifdef TIMEOUT
	IsTimedOut() ||
#endif
    (left && right);
}
void ChainsawPosition::End(){
	puts("end");
	Robot::climberArms->WindowMotorsOff();
}
void ChainsawPosition::Interrupted() {End();}
void ChainsawPosition::Reset(){
	goUpInMiddle = true;
	left = false; right = false;
	voltageLeft = 0.0f; voltageRight = 0.0f;
	Robot::climberArms->ResetWindowVoltageData();
}
