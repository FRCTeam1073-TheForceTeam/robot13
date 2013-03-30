#include "SpinFeeder.h"
SpinFeeder::SpinFeeder(){Requires(Robot::collector);}
void SpinFeeder::Initialize(){Robot::collector->MotorOn();}
void SpinFeeder::Execute(){}
bool SpinFeeder::IsFinished(){return false;}
void SpinFeeder::End(){
	//in the event that something in the code changes, we want the feeder to stop spinning
	//something similar to this happened at GS
	Interrupted();
}
void SpinFeeder::Interrupted(){Robot::collector->MotorOff();}

