#include "Collector.h"
#include "../Robotmap.h"

#define FOURDISCS 4
#define THREEDISCS 3
#define TWODISCS 2
#define ONEDISC 1

#define DISC_UPSIDE_DOWN_THRESHOLD 0.5

Collector::Collector() : Subsystem("Collector") {
	motor = RobotMap::collectorMotor;
	discOnShooterBed = RobotMap::collectorDiscOnShooterBed;
	discCountSensor = RobotMap::collectorDiscCountSensor;
}
    
void Collector::InitDefaultCommand() {}
void Collector::MotorOn(){motor->Set(COLLECTOR_SPEED_ON);}
void Collector::MotorOff() {motor->Set(COLLECTOR_SPEED_OFF);}
int Collector::GetNumberOfDiscs(){
	float voltage = discCountSensor->GetVoltage();
//	printf ("Get numeber of discs %f\n", voltage);
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

bool Collector::IsDiscOnShooterBed(){
	//TODO: look at proximity sensor on Shooter Bed (is a part of this class)
	return false;
}

