#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"
#include "../WPILibExtensions/WPILibExtensions.h"
Climber::Climber() : Subsystem("Climber") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	rightClimbWindowTalon = RobotMap::climberRightClimbWindowTalon;
	leftCIM = RobotMap::climberLeftCIM;
	rightCIM = RobotMap::climberRightCIM;
	leftClimbWindowTalon = RobotMap::climberLeftClimbWindowTalon;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	leftWindowEncoder = RobotMap::climberLeftWindowEncoder;
	rightWindowEncoder = RobotMap::climberRightWindowEncoder;
	ClimberOnOff = false;
}
    
void Climber::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Climber::Climb(float yPosition){
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
//What does Position 1 Mean?
void Climber::ChainsawPosition1(){
	leftClimbWindowTalon->Set(CHAINSAW_UP_SPEED);
	rightClimbWindowTalon->Set(CHAINSAW_UP_SPEED);
}
//What Does Position 2  Mean?
void Climber::ChainsawPosition2(){
	leftClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
	rightClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
}
//What Does Position Three Mean
//What is the diffrence between Position 2 and 3
void Climber::ChainsawPosition3(){
	leftClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
	rightClimbWindowTalon->Set(CHAINSAW_DOWN_SPEED);
}
bool Climber::ClimberIsDown(){
	const float voltage = 45.0f;
	return leftWindowEncoder->GetVoltage() == voltage || rightWindowEncoder->GetVoltage() == voltage;
}