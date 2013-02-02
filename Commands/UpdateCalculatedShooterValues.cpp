#include "UpdateCalculatedShooterValues.h"
UpdateCalculatedShooterValues::UpdateCalculatedShooterValues(){
	Requires(Robot::allignmentData);
	Requires(Robot::shooter);
}
void UpdateCalculatedShooterValues::Initialize(){}
void UpdateCalculatedShooterValues::Execute(){	
	Robot::shooter->UpdateDefaults(Robot::allignmentData->GetCalculatedDistance(), 
		Robot::allignmentData->GetCalculatedAngle());
	
}

//goes until the Shooter is required elsewhere...
bool UpdateCalculatedShooterValues::IsFinished() {return false;}
void UpdateCalculatedShooterValues::End() {}
void UpdateCalculatedShooterValues::Interrupted() {}
