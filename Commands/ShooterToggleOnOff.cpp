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
	printf("We are in fact turning this %s\n", previousOnOff == on ? "on" : "off");
}
void ShooterToggleOnOff::Execute(){
	
//	if(Robot::shooter->IsShooterMotorOn() == true)
//	{
//		puts("ramping the shooter");
//		Robot::shooter->ShooterRamp(iterationCount* TIMES_PER_SECOND /rampTimeSeconds);
//		iterationCount++;
//	}
//	else puts("Robot::shooter->IsShooterMotorOn() == false");

}
bool ShooterToggleOnOff::IsFinished()
{
	return true;
}
void ShooterToggleOnOff::End(){
	
}
void ShooterToggleOnOff::Interrupted(){End();}
