#include "ClimberOnOff.h"
ClimberOnOff::ClimberOnOff(OnOff offOff){
	Requires(Robot::climber);
	this->onOff = onOff;
}
void ClimberOnOff::Initialize(){
	switch(onOff){
		case on: Robot::climber->EngageClimber(); break;
		case off:Robot::climber->DisengageClimber(); break;
		default: break;
	}
}
void ClimberOnOff::Execute(){}
bool ClimberOnOff::IsFinished(){return true;}
void ClimberOnOff::End(){}
void ClimberOnOff::Interrupted(){}
