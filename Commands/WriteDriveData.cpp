#include "WriteDriveData.h"
int WriteDriveData::count = 0;
const char * WriteDriveData::name = "DriveData.csv";WriteDriveData::WriteDriveData() {
	//Hack diagnostic command, do not actually require the drivetrain!
	//Requires(Robot::driveTrain);
	Requires(Robot::shooter);
#if 0
	file = fopen(name, "w+");
	fprintf(file, "Left Encoder Speed, Left Encoder Voltage, Left Encoder Current, " 
		"Right Encoder Speed, Right Encoder Voltage, Right Encoder Current, "
		"Shooter Encoder Speed, Shooter Encoder Voltage, Shooter Encoder Current, "
		"Battery Voltage, Gyro Angle\n");
	fclose(file);
#endif
}
void WriteDriveData::Initialize() {
#if 0
	file = fopen(name, "w+");
	printf("Starting dump to:\n");
	puts(name);
#endif
}
void WriteDriveData::Execute() {
#if 0
	fprintf(file, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n",
		Robot::driveTrain->GetDriveSpeed(true), Robot::driveTrain->GetDriveBusVoltage(true),
		Robot::driveTrain->GetDriveCurrent(true), Robot::driveTrain->GetDriveSpeed(false),
		Robot::driveTrain->GetDriveBusVoltage(false), Robot::driveTrain->GetDriveCurrent(false),
		Robot::shooter->GetEncoderSpeed(), Robot::shooter->GetVoltage(), Robot::shooter->GetCurrent(),
		DriverStation::GetInstance()->GetBatteryVoltage(), Robot::driveTrain->GetGyroAngle());
#endif			
}
bool WriteDriveData::IsFinished() {return true;}	//TODO: make this right
void WriteDriveData::End() {Finished();}
void WriteDriveData::Interrupted() {Finished();}
void WriteDriveData::Finished(){
	puts("Dump finished");
//	fclose(file);
}
