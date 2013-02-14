#include "ChainsawPosition.h"
//#define TIMEOUT
ChainsawPosition::ChainsawPosition(Destination destination){
	Requires(Robot::climberArms);
#ifdef TIMEOUT
	SetTimeout(3.0);
#endif
	this->destination = destination;
	Reset();
}
void ChainsawPosition::Initialize(){
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
	left = left || Robot::climberArms->leftWindowEncoder->IsStall();
	right = right || Robot::climberArms->rightWindowEncoder->IsStall();
}
bool ChainsawPosition::IsFinished(){
	return
#ifdef TIMEOUT
	IsTimedOut() ||
#endif
    (left && right);
}
void ChainsawPosition::End(){Robot::climberArms->WindowMotorsOff();}
void ChainsawPosition::Interrupted() {End();}
void ChainsawPosition::Reset(){
	left = false; right = false;
	voltageLeft = 0.0f; voltageRight = 0.0f;
	Robot::climberArms->ResetWindowVoltageData();
}
