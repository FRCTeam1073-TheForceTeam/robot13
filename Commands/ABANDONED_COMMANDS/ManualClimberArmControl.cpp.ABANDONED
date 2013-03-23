#include "ManualClimberArmControl.h"
ManualClimberArmControl::ManualClimberArmControl(bool goUp){
	this->goUp = goUp;
	Requires(Robot::climberArms);
}
void ManualClimberArmControl::Initialize(){
	printf("Init Arms going %s\n", goUp ? "up" : "down");
	if(goUp) Robot::climberArms->ManualUp();
	else Robot::climberArms->ManualDown();
}
void ManualClimberArmControl::Execute() {printf("executing %s!!!\n", goUp ? "up" : "down");}
bool ManualClimberArmControl::IsFinished() {return false;}
void ManualClimberArmControl::End(){Interrupted();}	//should never get here
void ManualClimberArmControl::Interrupted(){
	puts("arms going downnn");
	Robot::climberArms->WindowMotorsOff();
}
