#include "Collector.h"
#include "../Robotmap.h"
Collector::Collector() : Subsystem("Collector") {
	motor = RobotMap::collectorMotor;
}
void Collector::InitDefaultCommand() {}
void Collector::MotorOn(){motor->Set(-1 * COLLECTOR_SPEED_ON);}
void Collector::MotorOff() {motor->Set(COLLECTOR_SPEED_OFF);}
