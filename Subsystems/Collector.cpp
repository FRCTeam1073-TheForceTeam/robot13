#include "Collector.h"
#include "../Robotmap.h"
Collector::Collector() : Subsystem("Collector") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	motor = RobotMap::collectormotor;
	discCountSensor = RobotMap::collectordiscCountSensor;
	discUpsideDownSensor = RobotMap::collectordiscUpsideDownSensor;
	discOnShooterBed = RobotMap::collectordiscOnShooterBed;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	numberOfDiscs = 0;
}
    
void Collector::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
int Collector::GetNumberOfDiscs(){
	return numberOfDiscs;
}
bool Collector::IsNextDiscUpsideDown(){
	return false;	//TODO: look at Disc Collection Sensor
}
void Collector::Hop(){
	
}
void Collector::Feed(){
	
}
