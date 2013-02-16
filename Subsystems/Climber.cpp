#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"
Climber::Climber() : Subsystem("Climber") {
	leftCIM = RobotMap::climberLeftCIM;
	rightCIM = RobotMap::climberRightCIM;
	ClimberOnOff = false;
	encoderFailCount = 0;
	ConfigureJaguarForSpeedMode(leftCIM);
	ConfigureJaguarForSpeedMode(rightCIM);
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
		ConfigureJaguarForVoltageMode(leftCIM);
		ConfigureJaguarForVoltageMode(rightCIM);
		puts("Now in Voltage Mode");
	}
	if(ClimberOnOff){
		leftCIM->Set(joyY);
		rightCIM->Set(joyY);
		//printf("\n Climber RPM: %f\n", yPosition);
	}
	else{
		leftCIM->Set(CLIMBER_OFF_SPEED);
		rightCIM->Set(CLIMBER_OFF_SPEED);	
	}
}
void Climber::EngageClimber(){ClimberOnOff = true;}	
void Climber::DisengageClimber(){ClimberOnOff = false;}
void Climber::ConfigureJaguarForSpeedMode(CANJaguar* jaguar){
	jaguar->DisableControl();
	jaguar->ChangeControlMode(CANJaguar::kSpeed);
	jaguar->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
	jaguar->ConfigEncoderCodesPerRev(360);
	jaguar->EnableControl();
}
void Climber::ConfigureJaguarForVoltageMode(CANJaguar* jaguar){
	jaguar->Disable();
	jaguar->ChangeControlMode(CANJaguar::kVoltage);
	jaguar->EnableControl();
}
