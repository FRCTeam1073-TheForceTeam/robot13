#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"
Climber::Climber() : Subsystem("Climber") {
	leftCIM = RobotMap::climberLeftCIM;
	rightCIM = RobotMap::climberRightCIM;
	ClimberOnOff = false;
	encoderFailCount = 0;
	leftCIM->ConfigureSpeedMode();
	rightCIM->ConfigureSpeedMode();
}
void Climber::InitDefaultCommand() {SetDefaultCommand(new ClimberDrive());}
void Climber::Climb(float joyY){
	const float MIN = 0.05f;
	const int EPIC_FAIL = 100;
	if(fabs(joyY) > 0.0f && (fabs(rightCIM->GetSpeed()) < MIN || fabs(leftCIM->GetSpeed()) < MIN)){
		if(encoderFailCount >= 0){
			encoderFailCount++;
		}
	}
	else if(encoderFailCount > 0) encoderFailCount = 0;
	if(encoderFailCount > EPIC_FAIL){
		encoderFailCount = -1;
		leftCIM->ConfigureVoltageMode();
		rightCIM->ConfigureVoltageMode();
		puts("Now in Voltage Mode");
	}
	if(ClimberOnOff){
		leftCIM->Set(joyY);
		rightCIM->Set(joyY);
	}
}
void Climber::EngageClimber(){ClimberOnOff = true;}	
void Climber::DisengageClimber(){
	ClimberOnOff = false;
	leftCIM->Set(CLIMBER_OFF_SPEED);
	rightCIM->Set(CLIMBER_OFF_SPEED);	
}
bool Climber::GetClimberOnOff(){return ClimberOnOff;}	
