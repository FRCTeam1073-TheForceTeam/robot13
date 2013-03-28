#include "WriteDriveData.h"
int WriteDriveData::count = 0;
extern "C" int Priv_SetwriteFileAllowed(UINT32 enable);
WriteDriveData::WriteDriveData() {}
void WriteDriveData::Initialize() {
	sprintf(fname, "%s%d%s", "ShooterData", count, ".csv");
	printf("Dumping %s\n", fname);
	file = fopen(fname, "w+");
	fprintf(file, "Timer, Front Shooter Speed, Front Shooter Current, Front Shooter Voltage, "
			"Back Shooter Speed, Back Shooter Current, Back Shooter Voltage\n");
			//	  "Back Shooter Speed, Back Shooter Current\n");"
	count++;
}
void WriteDriveData::Execute() {
	float dethklok = (float)Timer::GetFPGATimestamp();
	fprintf(file, "%f, %f, %f, %f, %f, %f, %f\n", dethklok,
			RobotMap::shooterJag->GetSpeed(), RobotMap::shooterJag->GetOutputCurrent(),
			RobotMap::shooterJag->GetOutputVoltage());
			//RobotMap::shooterBackJag->GetSpeed(), RobotMap::shooterBackJag->GetOutputCurrent());
}
bool WriteDriveData::IsFinished() {return false;}
void WriteDriveData::End() {Finished();}
void WriteDriveData::Interrupted() {Finished();}
void WriteDriveData::Finished(){
	puts("Dump finished");
	fclose(file);
}
