#include "Climber.h"4
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"
#include "../WPILibExtensions/WPILibExtensions.h"
Climber::Climber() : Subsystem("Climber") {
	leftClimbWindowTalon = RobotMap::climberLeftClimbWindowTalon;
	rightClimbWindowTalon = RobotMap::climberRightClimbWindowTalon;
	leftCIM = RobotMap::climberLeftCIM;
	rightCIM = RobotMap::climberRightCIM;
	leftWindowEncoder = RobotMap::climberLeftWindowEncoder;
	rightWindowEncoder = RobotMap::climberRightWindowEncoder;
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
void Climber::Climb(float yPosition){
	const float MIN = 0.05f;
	const int EPIC_FAIL = 100;
	if(encoderFailCount >= -fabs(yPosition) > 0.0f && (leftCIM->GetSpeed() < MIN || rightCIM->GetSpeed() < MIN)){		
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
	}
	
	if(ClimberOnOff){
		leftCIM->Set(yPosition);
		rightCIM->Set(yPosition);
	}
	else{
		leftCIM->Set(0);
		rightCIM->Set(0);	
	}
}
bool Climber::getClimberOnOff(){
	return ClimberOnOff;
}	
void Climber::EngageClimber(){
	//printf("\n\n *****In engage *******\n\n");
	ClimberOnOff=true;
}	
void Climber::DisengageClimber(){
	//printf("\n\n *****In disengage *******\n\n");
	ClimberOnOff=false;
}
void Climber::ChainsawMovementOff(){
	leftClimbWindowTalon->Set(0);
	rightClimbWindowTalon->Set(0);	
}
void Climber::ChainsawUp(){
	leftClimbWindowTalon->Set(CHAINSAW_UP_SPEED);
	rightClimbWindowTalon->Set(CHAINSAW_UP_SPEED);
}
void Climber::ChainsawDown(){
	leftClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
	rightClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
}

float Climber::EncoderUpVoltage(){return 0.15625f;}
float Climber::EncoderMiddleVoltage(){return 1.25f;}
float Climber::EncoderDownVoltage(){return 2.34375f;}
void Climber::ProcessWindowVoltageData(){
	leftWindowEncoder->ProcessVoltageData();
	rightWindowEncoder->ProcessVoltageData();
}
void Climber::ResetWindowVoltageData(){
	leftWindowEncoder->ResetData();
	rightWindowEncoder->ResetData();
}
bool Climber::WindowMotorStall(){return leftWindowEncoder->IsStall() || rightWindowEncoder->IsStall();}
