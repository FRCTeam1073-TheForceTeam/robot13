#include "AutonomousSequence.h"
#include "AutonomousForward.h"
#include "Commands/WaitCommand.h"
#include "ShooterOn.h"
#include "Shoot.h"
#include "MoveShooterToSetElevationAngle.h"
#include "ShooterOff.h"
#include "../Subsystems/Shooter.h"
AutonomousSequence::AutonomousSequence(){
	startPosition = leftBack;
	DoSequence();
}
AutonomousSequence::AutonomousSequence(StartPosition startPosition) {
	this->startPosition = startPosition;
	DoSequence();
}
void AutonomousSequence::DoSequence(){
	int elevationAngle = 30;
	int shooterSpeed = 2550;
	double shotWaitTime = 1;
	switch(startPosition){
	case middleBack:
		//In Autonomous Middle back we moved forward 0units, we should update this.
		AddSequential(new AutonomousForward(0.0));
		break;
	default: break;	//to my understanding, left and right don't do anything prior to this sequence...
	}
	Robot::shooter->SetRawElevationAngle(elevationAngle);
	Robot::shooter->SetRawSpeed(shooterSpeed);
	AddSequential(new MoveShooterToSetElevationAngle());
	AddSequential(new ShooterOn());
	AddSequential(new WaitCommand(GetAutonomousWaitTime()));
	AddSequential(new Shoot());
	AddSequential(new WaitCommand(shotWaitTime));
	AddSequential(new Shoot());
	AddSequential(new WaitCommand(shotWaitTime));
	AddSequential(new Shoot());
	AddSequential(new ShooterOff());
}
double AutonomousSequence::GetAutonomousWaitTime(){
	double waitTime = 3;
	try{
		waitTime = SmartDashboard::GetNumber("AutonomousWaitTime");
	}
	catch(exception e){
		const char* text = e.what();
		printf("SmartDashboard::GetNumber %s", text);
	}	
	return waitTime;
}
