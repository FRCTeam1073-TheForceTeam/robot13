#include "SetRawShooterStuffDontUse.h"
SetRawShooterStuffDontUse::SetRawShooterStuffDontUse(float speed, float angle){
	Requires(Robot::shooter);
	SetTimeout(1.5);
	this->speed = speed;
	this->angle = angle;
}
void SetRawShooterStuffDontUse::Initialize(){
	puts("you probably shouldn't be here and you should probably only see this once");
	Robot::shooter->SetRawElevationAngle(angle);
	Robot::shooter->SetRawSpeed(speed);	
}
void SetRawShooterStuffDontUse::Execute(){}
bool SetRawShooterStuffDontUse::IsFinished(){return IsTimedOut();}
void SetRawShooterStuffDontUse::End(){}
void SetRawShooterStuffDontUse::Interrupted(){End();}

