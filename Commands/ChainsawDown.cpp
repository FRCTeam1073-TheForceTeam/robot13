#include "ChainsawDown.h"
ChainsawDown::ChainsawDown() {Requires(Robot::climber);}
void ChainsawDown::Initialize() {
	Robot::climber->ResetWindowVoltageData();
	Robot::climber->ChainsawDown();
}
void ChainsawDown::Execute() {Robot::climber->ProcessWindowVoltageData();}
bool ChainsawDown::IsFinished() {
	return Robot::climber->leftWindowEncoder->GetVoltage() > Robot::climber->EncoderDownVoltage() 
	|| Robot::climber->rightWindowEncoder->GetVoltage() > Robot::climber->EncoderDownVoltage()
	|| Robot::climber->WindowMotorStall();
}
void ChainsawDown::End(){Robot::climber->ChainsawMovementOff();}
void ChainsawDown::Interrupted() {End();}
