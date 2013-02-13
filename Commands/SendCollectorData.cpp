#include "SendCollectorData.h"
SendCollectorData::SendCollectorData() {
}

void SendCollectorData::Initialize() {
}

void SendCollectorData::Execute(){
	char tempString[8];
	sprintf(tempString, "%d,%d", Robot::collector->GetNumberOfDiscs(), Robot::collector->IsNextDiscUpsideDown());
	SmartDashboard::PutString("CollectorStatus", tempString);
}
bool SendCollectorData::IsFinished() {return true;}
