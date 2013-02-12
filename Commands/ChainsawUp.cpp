#include "ChainsawUp.h"
#define RUNTIME 40
ChainsawUp::ChainsawUp() {Requires(Robot::climber);}
void ChainsawUp::Initialize() {
	Robot::climber->ChainsawUp();
	Robot::climber->ResetWindowVoltageData();
	manualPositionCounter = 0;
}
void ChainsawUp::Execute() {Robot::climber->ProcessWindowVoltageData();
	if(Robot::climber->leftWindowEncoder->IsStall() || Robot::climber->rightWindowEncoder->IsStall()){
		manualPositionCounter++;
	}
}
bool ChainsawUp::IsFinished() {
	return Robot::climber->leftWindowEncoder->GetVoltage() < Robot::climber->EncoderUpVoltage()
	|| Robot::climber->rightWindowEncoder->GetVoltage() < Robot::climber->EncoderUpVoltage()
	|| manualPositionCounter>=RUNTIME;
}
void ChainsawUp::End() {Robot::climber->ChainsawMovementOff();}
void ChainsawUp::Interrupted() {End();}
