#include "ChainsawDown.h"
#define RUNTIME 40
ChainsawDown::ChainsawDown() {Requires(Robot::climber);}
void ChainsawDown::Initialize() {
	Robot::climber->ResetWindowVoltageData();
	Robot::climber->ChainsawDown();
	manualPositionCounter = 0;
}
void ChainsawDown::Execute() {
	if(Robot::climber->leftWindowEncoder->IsStall() || Robot::climber->rightWindowEncoder->IsStall()){
		manualPositionCounter++;
	}
	Robot::climber->ProcessWindowVoltageData();}
bool ChainsawDown::IsFinished() {
	return Robot::climber->leftWindowEncoder->GetVoltage() > Robot::climber->EncoderDownVoltage() 
	|| Robot::climber->rightWindowEncoder->GetVoltage() > Robot::climber->EncoderDownVoltage()
	|| manualPositionCounter>=RUNTIME;
}
void ChainsawDown::End(){Robot::climber->ChainsawMovementOff();}
void ChainsawDown::Interrupted() {End();}
