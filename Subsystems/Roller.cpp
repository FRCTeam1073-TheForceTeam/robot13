#include "Roller.h"
Roller::Roller() : Subsystem("Roller"){motor = RobotMap::rollerMotor;}
void Roller::MotorForward(){puts("motor forward");motor->Set(Relay::kForward);}
void Roller::MotorOff(){puts("motor off");motor->Set(Relay::kOff);}
