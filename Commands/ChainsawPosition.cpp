#include "ChainsawPosition.h"
ChainsawPosition::ChainsawPosition(Destination destination){
	//Requires(Robot::climber);	//not sure about this...
	this->destination = destination;
	Reset();
}
void ChainsawPosition::Initialize(){Reset();}
void ChainsawPosition::Execute(){
	Robot::climber->ProcessWindowVoltageData();
	float voltage = 0.0f;
	switch(destination){
	case up:
		lessThan = true;
		voltage = Robot::climber->EncoderUpVoltage();
		Robot::climber->ChainsawUp(left, right);
		break;
	case middle:
		Robot::climber->ChainsawDown(left, right);
		voltage = Robot::climber->EncoderMiddleVoltage();
		break;
	case down:
		Robot::climber->ChainsawDown(left, right);
		voltage = Robot::climber->EncoderDownVoltage();
		break;
	default: break;
	if(lessThan){
		left = Robot::climber->leftWindowEncoder->GetVoltage() < voltage;
		right = Robot::climber->rightWindowEncoder->GetVoltage() < voltage;
	}
	else{
		left = Robot::climber->leftWindowEncoder->GetVoltage() > voltage;
		right = Robot::climber->rightWindowEncoder->GetVoltage() > voltage;
	}
	left = left || Robot::climber->leftWindowEncoder->IsStall();
	right = right || Robot::climber->rightWindowEncoder->IsStall();
	}
}
bool ChainsawPosition::IsFinished(){return left && right;}
void ChainsawPosition::End(){Robot::climber->ChainsawMovementOff();}
void ChainsawPosition::Interrupted() {End();}
void ChainsawPosition::Reset(){
	lessThan = false;
	left = true; right = true;
	Robot::climber->ResetWindowVoltageData();
}