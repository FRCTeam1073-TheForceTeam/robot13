#include "Collector.h"
#include "../Robotmap.h"

#define DISC_UPSIDE_DOWN_THRESHOLD 0.5

Collector::Collector() : Subsystem("Collector") {
	motor = RobotMap::collectorMotor;
	discOnShooterBed = RobotMap::collectorDiscOnShooterBed;
	overrided = false;
}
    
void Collector::InitDefaultCommand() {}
void Collector::MotorOn(){motor->Set(-1 * COLLECTOR_SPEED_ON);}
void Collector::MotorOff() {
	puts("you are in the collector subsystem, turning off the motors. this should be happening irl");
	motor->Set(COLLECTOR_SPEED_OFF);
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

