#include "AllignmentData.h"
#include "../Robotmap.h"
#include "../Robot.h"

AllignmentData::AllignmentData() : Subsystem("AllignmentData") {

	trackingDataTable = NetworkTable::GetTable("tracking");
}
void AllignmentData::InitDefaultCommand(){}

double AllignmentData::GetCalculatedVelocityRPM() {return trackingDataTable->GetNumber("calculatedVelocityRPM", -1);}
double AllignmentData::GetCalculatedAngle() {return trackingDataTable->GetNumber("calculatedAngle", -1);}
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
 	
