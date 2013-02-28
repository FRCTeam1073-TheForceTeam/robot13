#include "AutonomousSequence.h"
#include "AutonomousForward.h"
#include "AutonomousTurnToAngle.h"
#include "Commands/WaitCommand.h"
#include "ShooterToggleOnOff.h"
#include "Shoot.h"
#include "SetRawShooterStuffDontUse.h"
#include "MoveShooterToSetElevationAngle.h"
#include "ShooterToggleOnOff.h"
#include "../Subsystems/Shooter.h"
AutonomousSequence::AutonomousSequence(){
	startPosition = leftBack;
	
}
AutonomousSequence::AutonomousSequence(StartPosition startPosition){
	this->startPosition = startPosition;
}
void AutonomousSequence::Initialize(){}
void AutonomousSequence::End(){
	Robot::shooter->ShooterOnOff(false);
	Robot::shooter->ElevatorOff();
}
void AutonomousSequence::Interrupted(){End();}
double AutonomousSequence::GetAutonomousWaitTime(){
	double waitTime = 2;
#ifdef DEBUG_DATA
	try{
		waitTime = SmartDashboard::GetNumber("AutonomousWaitTime");
	}
	catch(exception e){
		const char* text = e.what();
		printf("SmartDashboard::GetNumber %s", text);
	}	
#endif
	return waitTime;
}
void AutonomousSequence::DoSequence(){
	float elevationAngle = 44;
	float shooterSpeed = 3000;
	switch(startPosition){
	case middleBack:
		//In Autonomous Middle back we moved forward 0units, we should update this.
		AddSequential(new AutonomousForward(0.0));
		break;
	default: break;	//to my understanding, left and right don't do anything prior to this sequence...
	}
	AddSequential(new SetRawShooterStuffDontUse(shooterSpeed, elevationAngle));
	AddSequential(new MoveShooterToSetElevationAngle(true));	//check for encoder failure
	for(int i = 0; i < 10; i++){
		AddSequential(new WaitCommand(GetAutonomousWaitTime()));
		AddSequential(new Shoot());
	}
}
