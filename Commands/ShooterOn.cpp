#include "ShooterOn.h"
ShooterOn::ShooterOn() {Requires(Robot::shooter);}
void ShooterOn::Initialize() {
	Robot::shooter->ShooterOnOff(true);}
void ShooterOn::Execute() {}
bool ShooterOn::IsFinished() {return false;}
void ShooterOn::End() {}
void ShooterOn::Interrupted() {}
