#include "AllignmentData.h"
#include "../Robotmap.h"
#include "../Commands/PullNewAllignmentData.h"
int AllignmentData::DEFAULT = -1;
AllignmentData::AllignmentData() : Subsystem("AllignmentData") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	calculatedDistance = DEFAULT;
	calculatedAngle = DEFAULT;
	table = NetworkTable::GetTable(this->GetName());
}
void AllignmentData::InitDefaultCommand(){SetDefaultCommand(new PullNewAllignmentData());}
double AllignmentData::GetCalculatedAngle() {return calculatedAngle;}
double AllignmentData::GetCalculatedDistance() {return calculatedDistance;}
bool AllignmentData::IsTarget(){return calculatedDistance != DEFAULT && calculatedAngle != DEFAULT;}
void AllignmentData::Refresh(){
	//begin transaction
	calculatedDistance = table->GetNumber("calculatedDistance");
	calculatedAngle = table->GetNumber("calculatedAngle");
	//end transaction...
}