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
	puts("constructed without parameter");
	DoSequence();
}
AutonomousSequence::AutonomousSequence(StartPosition startPosition){
	this->startPosition = startPosition;
	puts("constructed auto with config");
	DoSequence();
}
void AutonomousSequence::Initialize(){
	printf("in init: ");
	switch(startPosition){
		case leftBack: printf("left"); break;
		case rightBack: printf("right"); break;
		case middleBack: printf("middle"); break;
		default: printf("invalid"); break;
	}
	printf("\n");
	 	 
}
void AutonomousSequence::End(){
	Robot::shooter->ElevatorOff();
	Robot::collector->MotorOff();
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
	float elevationAngle = 15;
	float shooterSpeed = 2750;
	switch(startPosition){
	case leftBack: puts("got left"); break;
	case rightBack: puts("got right"); break;
	case middleBack:
		puts("got middle");
		//In Autonomous Middle back we moved forward 0units, we should update this.
		AddSequential(new AutonomousForward(0.0));
		puts("Added AutonomousForward(0.0)");
		break;
	default: puts("hell broke loose"); break;	//to my understanding, left and right don't do anything prior to this sequence...
	}
	AddSequential(new SetRawShooterStuffDontUse(shooterSpeed, elevationAngle));
	AddSequential(new MoveShooterToSetElevationAngle(true));	//check for encoder failure
	AddSequential(new ShooterToggleOnOff());
	for(int i = 0; i < 10; i++){
		AddSequential(new WaitCommand(GetAutonomousWaitTime()));
		AddSequential(new Shoot());
	}
}
