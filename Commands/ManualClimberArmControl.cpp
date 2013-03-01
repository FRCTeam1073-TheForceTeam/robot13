#include "ManualClimberArmControl.h"
ManualClimberArmControl::ManualClimberArmControl(bool goUp){
	this->goUp = goUp;
	Requires(Robot::climberArms);
}
void ManualClimberArmControl::Initialize(){
	if(goUp) Robot::climberArms->ManualUp();
	else Robot::climberArms->ManualDown();
}
void ManualClimberArmControl::Execute() {}
bool ManualClimberArmControl::IsFinished() {return false;}
void ManualClimberArmControl::End(){Interrupted();}	//should never get here
void ManualClimberArmControl::Interrupted(){Robot::climberArms->WindowMotorsOff();}
