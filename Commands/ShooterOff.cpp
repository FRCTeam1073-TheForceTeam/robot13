#include "ShooterOff.h"
ShooterOff::ShooterOff() {Requires(Robot::shooter);}
void ShooterOff::Initialize() {Robot::shooter->ShooterOnOff(false);}
void ShooterOff::Execute() {}
bool ShooterOff::IsFinished() {return true;}
void ShooterOff::End() {}
void ShooterOff::Interrupted() {}
