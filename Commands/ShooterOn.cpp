#include "ShooterOn.h"
ShooterOn::ShooterOn() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
void ShooterOn::Initialize() {Robot::shooter->ShooterOnOff(true);}
void ShooterOn::Execute() {}
bool ShooterOn::IsFinished() {return true;}
void ShooterOn::End() {}
void ShooterOn::Interrupted() {}
