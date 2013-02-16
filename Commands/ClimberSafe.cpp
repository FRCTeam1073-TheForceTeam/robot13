#include "ClimberSafe.h"

void ClimberSafe::Initialize() {

}

void ClimberSafe::Execute() {
	Robot::climberArms->climberIsSafe = false;
	printf("\n\n Climber is now NOT SAFE! \n\n");
}
bool ClimberSafe::IsFinished() {
	return true;
}
void ClimberSafe::End() {}
void ClimberSafe::Interrupted() {}
