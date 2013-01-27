#include "Climber.h"
#include "../RobotMap.h"
#include "../Robot.h"
#include "../Commands/ClimberDrive.h"

Climber::Climber() : Subsystem("Climber") {
	printf("In climber /n");
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	climberTalon = RobotMap::climberClimberTalon;
	leftClimberJag = RobotMap::climberLeftClimberJag;
	rightClimberJag = RobotMap::climberRightClimberJag;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	 ClimberOnOff = false;

}
    
void Climber::InitDefaultCommand() {
	printf("In Init /n");
	SetDefaultCommand(new ClimberDrive());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
void Climber::Climb(float yPosition){
	printf("In climb ClimberOnOff = %d yPosition = %f\n", ClimberOnOff, yPosition);
	if(ClimberOnOff){
		
		Climber::leftClimberJag->Set(yPosition);
//		Climber::rightClimberJag->Set(yPosition);
	}
	else{
		Climber::leftClimberJag->Set(0);
	//	Climber::rightClimberJag->Set(0);
		
	}


}
void Climber::EngageClimber(){
	printf("\n\n *****In engage *******\n\n");
	ClimberOnOff=true;
}
	
void Climber::DisengageClimber(){
	printf("\n\n *****In disengage *******\n\n");
	ClimberOnOff=false;
}
	
void Climber::ChainsawMovementOff(){
	RobotMap::climberClimberTalon->Set(0);
}
void Climber::ChainsawPosition1(){
	RobotMap::climberClimberTalon->Set(CHAINSAW_UP_SPEED);
 }
void Climber::ChainsawPosition2(){
	RobotMap::climberClimberTalon->Set(CHAINSAW_DOWN_SPEED);
}
void Climber::ChainsawPosition3(){
	RobotMap::climberClimberTalon->Set(CHAINSAW_DOWN_SPEED);
}
double Climber::GetDistance(){
	return RobotMap::climberChainsawElevationMEncoder->GetDistance();
}
