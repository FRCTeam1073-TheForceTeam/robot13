#include "AllignmentData.h"
#include "../Robotmap.h"
#include "../Robot.h"
int AllignmentData::DEFAULT = -1;
AllignmentData::AllignmentData() : Subsystem("AllignmentData") {
	calculatedDistance = DEFAULT;
	calculatedAngle = DEFAULT;
	trackingDataTable = NetworkTable::GetTable("tracking");
}
void AllignmentData::InitDefaultCommand(){}
<<<<<<< HEAD
double AllignmentData::GetCalculatedVelocityFPS() {return trackingDataTable->GetNumber("calculatedRPM", -1);}
=======
double AllignmentData::GetCalculatedVelocityRPM() {return trackingDataTable->GetNumber("calculatedVelocityRPM", -1);}
>>>>>>> origin/master
double AllignmentData::GetCalculatedAngle() {return trackingDataTable->GetNumber("calculatedAngle", -1);}
bool AllignmentData::IsTarget(){return calculatedDistance != DEFAULT && calculatedAngle != DEFAULT;}
void AllignmentData::SendCurrentAngle(float angle)
{
	trackingDataTable->PutNumber("currentAngle", angle);
	printf("AllignmentData SendCurrentAngle angle: %f\n", angle);
	printf("Network Table is Connected %d", trackingDataTable->IsConnected());
}
void AllignmentData::SendCurrentSpeed(int speed) {
	trackingDataTable->PutNumber("currentSpeed", speed);
	printf("AllignmentData SendCurrentSpeed speed: %d\n", speed);
	printf("Network Table is Connected %d", trackingDataTable->IsConnected());
}
 	
