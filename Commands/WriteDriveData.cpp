#include "WriteDriveData.h"
int WriteDriveData::count = 0;
extern "C" int Priv_SetwriteFileAllowed(UINT32 enable);
WriteDriveData::WriteDriveData() {}
void WriteDriveData::Initialize() {
	sprintf(fname, "%s%d%s", "ShooterData", count, ".csv");
	printf("Dumping %s\n", fname);
	file = fopen(fname, "w+");
	fprintf(file, "Timer, Primary Shooter Speed, Primary Shooter Current, Primary Shooter Voltage, "
			"Support Shooter Speed, Support Shooter Current, Support Shooter Voltage\n");
			//	  "Support Shooter Speed, Support Shooter Current\n");"
	count++;
}
void WriteDriveData::Execute() {
	float time = (float)Timer::GetFPGATimestamp();
	fprintf(file, "%f, %f, %f, %f, %f, %f, %f\n", time,
			RobotMap::shooterPrimaryJag->GetSpeed(), RobotMap::shooterPrimaryJag->GetOutputCurrent(),
			RobotMap::shooterPrimaryJag->GetOutputVoltage(), RobotMap::shooterSupportJag->GetSpeed(),
			RobotMap::shooterSupportJag->GetOutputVoltage(), RobotMap::shooterSupportJag->GetOutputCurrent());
			//RobotMap::shooterSupportJag->GetSpeed(), RobotMap::shooterSupportJag->GetOutputCurrent());
}
bool WriteDriveData::IsFinished() {return false;}
void WriteDriveData::End() {Finished();}
void WriteDriveData::Interrupted() {Finished();}
void WriteDriveData::Finished(){
	puts("Dump finished");
	fclose(file);
}
