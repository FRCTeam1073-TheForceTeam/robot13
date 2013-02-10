#include "ChainsawUp.h"
ChainsawUp::ChainsawUp() {Requires(Robot::climber);}
void ChainsawUp::Initialize() {
	Robot::climber->ChainsawUp();
	Robot::climber->ResetWindowVoltageData();
}
void ChainsawUp::Execute() {Robot::climber->ProcessWindowVoltageData();}
bool ChainsawUp::IsFinished() {
	return Robot::climber->leftWindowEncoder->GetVoltage() < Robot::climber->EncoderUpVoltage()
	|| Robot::climber->rightWindowEncoder->GetVoltage() < Robot::climber->EncoderUpVoltage()
	|| Robot::climber->WindowMotorStall();
}
void ChainsawUp::End() {Robot::climber->ChainsawMovementOff();}
void ChainsawUp::Interrupted() {End();}
