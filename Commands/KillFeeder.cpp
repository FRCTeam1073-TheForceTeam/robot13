#include "KillFeeder.h"
KillFeeder::KillFeeder(){
	Requires(Robot::collector);
}
void KillFeeder::Initialize(){
	puts("killing feeder");
	Robot::collector->MotorOff();
	puts("killed feeder");
}
void KillFeeder::Execute(){}
bool KillFeeder::IsFinished(){return true;}
void KillFeeder::End(){}
void KillFeeder::Interrupted(){}
