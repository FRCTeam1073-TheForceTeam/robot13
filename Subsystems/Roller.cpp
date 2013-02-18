#include "Roller.h"
Roller::Roller() : Subsystem("Roller"){motor = RobotMap::rollerMotor;}
void Roller::MotorForward(){motor->Set(SPEED_FORWARD);}
void Roller::MotorReverse(){motor->Set(SPEED_REVERSE);}
void Roller::MotorOff(){motor->Set(SPEED_OFF);}
