#include "AllignmentData.h"
#include "../Robotmap.h"
AllignmentData::AllignmentData() : Subsystem("AllignmentData") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	calculatedDistance = -1;
	calculatedAngle = -1;
}
int AllignmentData::GetCalculatedAngle() {return calculatedAngle;}
int AllignmentData::GetCalculatedDistance() {return calculatedDistance;}
void AllignmentData::SetCalculatedAngle(int calculatedAngle){
	this->calculatedAngle = calculatedAngle;
}
void AllignmentData::SetCalculatedDistance(int calculatedDistance){
	this->calculatedDistance = calculatedDistance;
}
