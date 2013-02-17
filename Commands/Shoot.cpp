#include "Shoot.h"
Shoot::Shoot() {
	Requires(Robot::collector);
	if (Robot::collector->overrided)
		SetTimeout(0.75);
	else
		SetTimeout(2);
}
void Shoot::Initialize() {
	abort = (!Robot::shooter->IsShooterMotorOn() || Robot::collector->GetNumberOfDiscs() == 0);
	if(abort){
		printf("ERROR! You either have no discs or the shooter is not running!\n");
		return;
	}
	discState = enteringShooter;
	Robot::collector->MotorOn();
}
void Shoot::Execute() {
	if(abort) return;
	switch(discState){
	case (enteringShooter):
		if(Robot::collector->IsDiscOnShooterBed()) discState = inShooter;
		break;
	case (inShooter):
		if(!Robot::collector->IsDiscOnShooterBed()) discState = leftCollector;
		break;
	default: break;
	}
}
bool Shoot::IsFinished() {
	if(abort) 
		return true;
	
	return discState == leftCollector || IsTimedOut();
		
}
void Shoot::End() {
	if(abort) return;
	Robot::collector->MotorOff();
}
