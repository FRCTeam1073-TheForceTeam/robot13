#include "ClimberOn.h"
ClimberOn::ClimberOn() {Requires(Robot::climber);}
void ClimberOn::Initialize() {Robot::climber->EngageClimber();}
void ClimberOn::Execute() {}
bool ClimberOn::IsFinished() {return true;}
void ClimberOn::End() {}
void ClimberOn::Interrupted() {End();}
