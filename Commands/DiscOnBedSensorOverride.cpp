#include "DiscOnBedSensorOverride.h"

DiscOnBedSensorOverride::DiscOnBedSensorOverride() {
	Requires(Robot::collector);
}
void DiscOnBedSensorOverride::Initialize() {
	Robot::collector->overrided = true;
}
void DiscOnBedSensorOverride::Execute() {

}
bool DiscOnBedSensorOverride::IsFinished() {
	return true;
}
void DiscOnBedSensorOverride::End(){}
void DiscOnBedSensorOverride::Interrupted() {}
