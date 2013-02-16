#include "DiscVelocity.h"
//#include "../Robot.h"
#include "../Commands/DefaultDiscVelocityCommand.h"

//C style function forinterrupt...
void DiscInterrupt(uint32_t mask, void *param)
{
	DiscVelocity * discVelocity = (DiscVelocity *)param;
	discVelocity->ProcessInterrupt();
}
DiscVelocity::DiscVelocity(DigitalInput* input) : Subsystem("Disc Velocity"){
		this->input = input;
		input->RequestInterrupts(DiscInterrupt, this);
		input->SetUpSourceEdge(true, true);
		input->EnableInterrupts();
		Reset();
		newData = false;
}
void DiscVelocity::InitDefaultCommand(){
	SetDefaultCommand(new DefaultDiscVelocityCommand());
}
float DiscVelocity::GetStartTime(){return startTime;}
float DiscVelocity::GetStopTime() {return stopTime;}
float DiscVelocity::GetEllapsedTime() {return ellapsedTime;}
float DiscVelocity::GetVelocityFPS() {
	newData = false;
	return velocity;
}
void DiscVelocity::ProcessInterrupt(){
	switch(state){
	case(NotWaiting):
		break;
	case(WaitingForDetect):
			if(input->Get() == 0){
				state = NotWaiting;
				startTime = Timer::GetFPGATimestamp();
				state = WaitingForExit;
			}
			break;
	case(WaitingForExit):
			if(input->Get() == 1){
				state = NotWaiting;
				stopTime = Timer::GetFPGATimestamp();
				ellapsedTime = stopTime - startTime;
				velocity = DISC_DIAMETER_FEET / ellapsedTime;
				Reset();
				newData = true;
			}
			break;
	default: break;
	}
}
void DiscVelocity::Reset(){
		state = WaitingForDetect;
		startTime = --stopTime;
		index = 0;
		for(int i = 0; i < SHOTS_PER_TEST; i++)	speeds[i] = -1.0f;
	}
bool DiscVelocity::IsThereNewData() {return newData;}
