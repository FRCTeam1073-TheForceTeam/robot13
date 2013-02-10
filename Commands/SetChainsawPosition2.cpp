#include "SetChainsawPosition2.h"
SetChainsawPosition2::SetChainsawPosition2() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::climber);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void SetChainsawPosition2::Initialize() {Robot::climber->ChainsawPosition2();}
void SetChainsawPosition2::Execute() {}
bool SetChainsawPosition2::IsFinished() {
	//Position 2 will only be accessable from position 1, not position 3
	if(RobotMap::climberRightWindowEncoder->GetVoltage()>1.25 || 
			RobotMap::climberRightWindowEncoder->GetVoltage()>1.25){
		return true;
	}
	else{
		return false;
	}
	
	//return Robot::climber->ClimberIsDown();
}
void SetChainsawPosition2::End() {Robot::climber->ChainsawMovementOff();}
void SetChainsawPosition2::Interrupted() {}
