#include "ShooterOnOff.h"
ShooterOnOff::ShooterOnOff(OnOff onOff){
	Requires(Robot::climber);
	this->onOff = onOff;
}
void ShooterOnOff::Initialize(){Robot::shooter->ShooterOnOff(onOff == on);}
void ShooterOnOff::Execute(){}
bool ShooterOnOff::IsFinished(){return true;}
void ShooterOnOff::End(){}
void ShooterOnOff::Interrupted(){}
