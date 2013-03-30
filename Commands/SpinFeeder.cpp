#include "SpinFeeder.h"
SpinFeeder::SpinFeeder(){
	Requires(Robot::collector);
	this->forward = true;
}
SpinFeeder::SpinFeeder(bool forward){
	Requires(Robot::collector);
	this->forward = forward;
}
void SpinFeeder::Initialize(){
	if(forward)Robot::collector->MotorOn();
	else Robot::collector->MotorReverse();
}
void SpinFeeder::Execute(){}
bool SpinFeeder::IsFinished(){return false;}
void SpinFeeder::End(){
	//in the event that something in the code changes, we want the feeder to stop spinning
	//something similar to this happened at GSR
	Interrupted();
}
void SpinFeeder::Interrupted(){Robot::collector->MotorOff();}

