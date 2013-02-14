#include "ChainsawPosition.h"
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
		voltageLeft = Robot::climberArms->LeftEncoderMiddleVoltage();
		voltageRight = Robot::climberArms->RightEncoderMiddleVoltage();
	    break;
	case down:
		voltageLeft = Robot::climberArms->LeftEncoderDownVoltage();
		voltageRight = Robot::climberArms->RightEncoderDownVoltage();
		break;
	default: break;
	}
}
void ChainsawPosition::Execute(){
	Robot::climberArms->ProcessWindowVoltageData();
	float vleft = Robot::climberArms->GetVoltageLeft();
	float vright = Robot::climberArms->GetVoltageRight();
	printf("Voltage Left: %f Target Voltage Left: %f\n", vleft, voltageLeft);
	switch(destination){
	case up:
		Robot::climberArms->WindowMotorsUp(left, right);
		if(!left)left = vleft >= voltageLeft;
		if(!right)right = vright <= voltageRight;
		break;
	case middle:
		Robot::climberArms->WindowMotorsDown(left, right);
		if(!left)left = fabs(vleft - voltageLeft) <= Robot::climberArms->EncoderVoltageTolerance();
		if(!right)right = fabs(vright - voltageRight) <= Robot::climberArms->EncoderVoltageTolerance();
		break;
	case down:
		Robot::climberArms->WindowMotorsDown(left, right);
		if(!left)left = vleft <= voltageLeft;
		if(!right) right = vright >= voltageRight;
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
	return
#ifdef TIMEOUT
	IsTimedOut() ||
#endif
    (left && right);
}
void ChainsawPosition::End(){
	puts("end");
	Robot::climberArms->WindowMotorsOff();}
void ChainsawPosition::Interrupted() {End();}
void ChainsawPosition::Reset(){
	left = false; right = false;
	voltageLeft = 0.0f; voltageRight = 0.0f;
	Robot::climberArms->ResetWindowVoltageData();
}
