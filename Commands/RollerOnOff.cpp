#include "RollerOnOff.h"
RollerOnOff::RollerOnOff(OnOff onOff){
	Requires(Robot::roller);
	this->onOff = onOff;
}
void RollerOnOff::Initialize(){
	switch(onOff){
	case on:
		puts("roller on");
		Robot::roller->MotorForward();
		break;
	case off:
		puts("roller off");
		Robot::roller->MotorOff();
		break;
	default: break;
	}
}
void RollerOnOff::Execute(){}
bool RollerOnOff::IsFinished(){return true;}
void RollerOnOff::End(){}
void RollerOnOff::Interrupted(){}
