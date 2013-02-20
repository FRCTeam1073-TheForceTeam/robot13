#include "AutonomousSequence.h"
#include "AutonomousForward.h"
#include "AutonomousTurnToAngle.h"
#include "Commands/WaitCommand.h"
#include "ShooterToggleOnOff.h"
#include "Shoot.h"
#include "MoveShooterToSetElevationAngle.h"
#include "ShooterToggleOnOff.h"
#include "../Subsystems/Shooter.h"
AutonomousSequence::AutonomousSequence(){
	startPosition = leftBack;
}
AutonomousSequence::AutonomousSequence(StartPosition startPosition){
	this->startPosition = startPosition;
}
void AutonomousSequence::Initialize(){
	SetTimeout(14);
	int elevationAngle = 30;
	int shooterSpeed = 2550;
	switch(startPosition){
	case middleBack:
		//In Autonomous Middle back we moved forward 0units, we should update this.
		AddSequential(new AutonomousForward(0.0));
		break;
	default: break;	//to my understanding, left and right don't do anything prior to this sequence...
	}
	Robot::shooter->SetRawElevationAngle(elevationAngle);
	Robot::shooter->SetRawSpeed(shooterSpeed);
	if(!Robot::shooter->GetElevationEncoderFailed()) {
		AddSequential(new MoveShooterToSetElevationAngle());
	}
	AddSequential(new ShooterToggleOnOff());
	//AddSequential(new AutonomousTurnToAngle(45.0));	//this was to test autonomous turning
}

void AutonomousSequence::Execute(){
	AddSequential(new WaitCommand(GetAutonomousWaitTime()));
	AddSequential(new Shoot());
}
bool AutonomousSequence::IsFinished(){
	return (Robot::collector->GetNumberOfDiscs() == 0) || IsTimedOut();
}

void AutonomousSequence::End(){
	AddSequential(new ShooterToggleOnOff());
}
void AutonomousSequence::Interrupted(){End();}
double AutonomousSequence::GetAutonomousWaitTime(){
	double waitTime = 2;
	try{
		waitTime = SmartDashboard::GetNumber("AutonomousWaitTime");
	}
	catch(exception e){
		const char* text = e.what();
		printf("SmartDashboard::GetNumber %s", text);
	}	
	return waitTime;
}
