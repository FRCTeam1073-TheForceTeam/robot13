#include "ShooterToggleOnOff.h"
#define TIMES_PER_SECOND 0.05f
ShooterToggleOnOff::ShooterToggleOnOff(){
	Requires(Robot::shooter);
	previousOnOff = off;
	iterationCount = 0;
	rampTimeSeconds = 1.0;	
}
void ShooterToggleOnOff::Initialize(){
	previousOnOff = (previousOnOff == on ? off : on);
	Robot::shooter->ShooterOnOff(previousOnOff == on);
}
void ShooterToggleOnOff::Execute(){
	Robot::shooter->ShooterRamp(iterationCount* TIMES_PER_SECOND /rampTimeSeconds);
	iterationCount++;
}
bool ShooterToggleOnOff::IsFinished(){
	return (iterationCount * TIMES_PER_SECOND) >= rampTimeSeconds;
}
void ShooterToggleOnOff::End(){}
void ShooterToggleOnOff::Interrupted(){}
