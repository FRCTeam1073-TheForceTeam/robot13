#include "Collector.h"
#include "../Robotmap.h"
#include "../Commands/CollectorSendDiscCount.h"
#define FOURDISCS 4
#define THREEDISCS 3
#define TWODISCS 2
#define ONEDISC 1
Collector::Collector() : Subsystem("Collector") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	motor = RobotMap::collectorMotor;
	discOnShooterBed = RobotMap::collectorDiscOnShooterBed;
	discCountSensor = RobotMap::collectorDiscCountSensor;
	discUpsideDownSensor = RobotMap::collectorDiscUpsideDownSensor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Collector::InitDefaultCommand() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	SetDefaultCommand(new CollectorSendDiscCount());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}
void Collector::MotorOn(){motor->Set(1.0f);}
void Collector::MotorOff() {motor->Set(0.0f);}
int Collector::GetNumberOfDiscs(){
	float voltage = discCountSensor->GetVoltage();
	printf ("Get numeber of discs %f\n", voltage);
	if (voltage > FOURDISCS)
		return FOURDISCS;
	else if (voltage > THREEDISCS)
		return THREEDISCS;
	else if (voltage > TWODISCS)
		return TWODISCS;
	else if (voltage > ONEDISC)
		return ONEDISC; 
	return 0;
}
bool Collector::IsNextDiscUpsideDown(){
	return false;	//TODO: look at Disc Collection Sensor
}
bool Collector::IsDiscOnShooterBed(){
	//TODO: look at proximity sensor on Shooter Bed (is a part of this class)
	return false;
}
