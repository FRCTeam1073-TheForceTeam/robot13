#include "ShooterToggleOnOff.h"
#define TIMES_PER_SECOND 0.05f
ShooterToggleOnOff::ShooterToggleOnOff(){
	Requires(Robot::shooter);
	previousOnOff = off;
	iterationCount = 0;
	rampTimeSeconds = 1.0;	
}
void ShooterToggleOnOff::Initialize(){
	iterationCount = 0;
	previousOnOff = (previousOnOff == on ? off : on);
	Robot::shooter->ShooterOnOff(previousOnOff == on);
}
void ShooterToggleOnOff::Execute(){
	if(Robot::shooter->IsShooterMotorOn() == true)
	{
		Robot::shooter->ShooterRamp(iterationCount* TIMES_PER_SECOND /rampTimeSeconds);
		iterationCount++;
	}

}
bool ShooterToggleOnOff::IsFinished()
{
	return !Robot::shooter->IsShooterMotorOn() || (iterationCount * TIMES_PER_SECOND) >= rampTimeSeconds;
}
void ShooterToggleOnOff::End(){
	
}
void ShooterToggleOnOff::Interrupted(){End();}
