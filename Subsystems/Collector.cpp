#include "Collector.h"
#include "../Robotmap.h"

#define FOURDISCS 3
#define THREEDISCS 2.1
#define TWODISCS 1.5
#define ONEDISC 0.8

#define DISC_UPSIDE_DOWN_THRESHOLD 0.5

Collector::Collector() : Subsystem("Collector") {
	motor = RobotMap::collectorMotor;
	discOnShooterBed = RobotMap::collectorDiscOnShooterBed;
	discCountSensor = RobotMap::collectorDiscCountSensor;
	overrided = false;
}
    
void Collector::InitDefaultCommand() {}
void Collector::MotorOn(){motor->Set(COLLECTOR_SPEED_ON);}
void Collector::MotorOff() {motor->Set(COLLECTOR_SPEED_OFF);}
int Collector::GetNumberOfDiscs(){
	int numberOfDiscs;
	float voltage = discCountSensor->GetVoltage();
	printf("Number of Disc sensor voltage: %f", voltage);
	printf ("Get number of discs %f\n", voltage);
	if (voltage > FOURDISCS)
		numberOfDiscs = 4;
	else if (voltage > THREEDISCS)
		numberOfDiscs = 3;
	else if (voltage > TWODISCS)
		numberOfDiscs = 2;
	else if (voltage > ONEDISC)
		numberOfDiscs = 1; 
	else 
		numberOfDiscs = 0;
	
	printf ("numberOfDIscs %d\n", numberOfDiscs);
	return numberOfDiscs;
}

bool Collector::IsDiscOnShooterBed(){
	if(overrided)
		return true;
	else if (discOnShooterBed->Get() == 1)
		return true;
	else
		return false;
	//TODONE

}

