#include "Roller.h"
Roller::Roller() : Subsystem("Roller"){motor = RobotMap::rollerMotor;}
void Roller::MotorForward(){motor->Set(Relay::kForward);}
void Roller::MotorReverse(){motor->Set(Relay::kReverse);}
void Roller::MotorOff(){motor->Set(Relay::kOff);}
