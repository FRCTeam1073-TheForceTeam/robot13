#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"
Climber::Climber() : Subsystem("Climber") {
	leftCIM = RobotMap::climberLeftCIM;
	rightCIM = RobotMap::climberRightCIM;
	ClimberOnOff = false;
	encoderFailCount = 0;
}
void Climber::InitDefaultCommand() {SetDefaultCommand(new ClimberDrive());}
void Climber::ClimberJagConfig(){
	leftCIM->ChangeControlMode(CANJaguar::kSpeed);
	leftCIM->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
	leftCIM->ConfigEncoderCodesPerRev(360);
	leftCIM->EnableControl();
	
	rightCIM->ChangeControlMode(CANJaguar::kSpeed);
	rightCIM->SetSpeedReference(CANJaguar::kSpeedRef_Encoder);
	rightCIM->ConfigEncoderCodesPerRev(360);
	rightCIM->EnableControl();
	
}
void Climber::Climb(float joyY){
	const float MIN = 0.05f;
	const int EPIC_FAIL = 100;
#warning "Climber Always in EPIC_FAIL mode"	
	// Not the if true or ...
	if((true || encoderFailCount >= -fabs(joyY) > 0.0f) && (leftCIM->GetSpeed() < MIN || rightCIM->GetSpeed() < MIN)){		
		encoderFailCount++;
	}
	else if (encoderFailCount > 0){
		encoderFailCount = 0;
	}	
	if(encoderFailCount > EPIC_FAIL){
		encoderFailCount = -1;
		leftCIM->Disable();
		leftCIM->ChangeControlMode(CANJaguar::kVoltage);
		leftCIM->EnableControl();

		rightCIM->Disable();
		rightCIM->ChangeControlMode(CANJaguar::kVoltage);
		rightCIM->EnableControl();
		printf("\n\n ```````Voltage Mode````````\n\n");
	}
//	printf("Poorly named y variable: %f\n", yPosition);
	if(ClimberOnOff){
		leftCIM->Set(-1 * joyY);
		rightCIM->Set(joyY);
		//printf("\n Climber RPM: %f\n", yPosition);
	}
	else{
		leftCIM->Set(CLIMBER_OFF_SPEED);
		rightCIM->Set(CLIMBER_OFF_SPEED);	
	}
}
bool Climber::getClimberOnOff(){
	return ClimberOnOff;
}	
void Climber::EngageClimber(){
	printf("\n\n *****In engage *******\n\n");
	ClimberOnOff=true;
}	
void Climber::DisengageClimber(){
	printf("\n\n *****In disengage *******\n\n");
	ClimberOnOff=false;
}
