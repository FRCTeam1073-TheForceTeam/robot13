#include "ChainsawMiddle.h"
ChainsawMiddle::ChainsawMiddle() {Requires(Robot::climber);}
void ChainsawMiddle::Initialize() {
	Robot::climber->ResetWindowVoltageData();
	Robot::climber->ChainsawDown();
}
void ChainsawMiddle::Execute() {Robot::climber->ProcessWindowVoltageDat)();}
bool ChainsawMiddle::IsFinished() {
	//Position 2 will only be accessable from position 1, not position 3
	return RobotMap::climberRightWindowEncoder->GetVoltage() > Robot::climber->EncoderMiddleVoltage()
	|| RobotMap::climberRightWindowEncoder->GetVoltage() > Robot::climber->EncoderMiddleVoltage()
	|| Robot::climber->WindowMotorStall();
}
void ChainsawMiddle::End() {Robot::climber->ChainsawMovementOff();}
void ChainsawMiddle::Interrupted() {End();}
