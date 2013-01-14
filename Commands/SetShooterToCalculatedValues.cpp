#include "SetShooterToCalculatedValues.h"
SetShooterToCalculatedValues::SetShooterToCalculatedValues() {Requires(Robot::shooter);}
void SetShooterToCalculatedValues::Initialize() {Robot::shooter->SetToDefaults();}
void SetShooterToCalculatedValues::Execute() {}
bool SetShooterToCalculatedValues::IsFinished() {return true;}
void SetShooterToCalculatedValues::End() {}void SetShooterToCalculatedValues::Interrupted() {}
