#include "WriteDriveData.h"
int WriteDriveData::count = 0;
const char * WriteDriveData::name = "DriveData.csv";WriteDriveData::WriteDriveData() {
	//Hack diagnostic command, do not actually require the drivetrain!
	//Requires(Robot::driveTrain);
	Requires(Robot::shooter);
	file = fopen(name, "w+");
	fprintf(file, "Left Encoder Speed, Left Encoder Voltage, Left Encoder Current, " 
		"Right Encoder Speed, Right Encoder Voltage, Right Encoder Current, "
		"Shooter Encoder Speed, Shooter Encoder Voltage, Shooter Encoder Current, "
		"Battery Voltage, Gyro Angle\n");
	fclose(file);
}
void WriteDriveData::Initialize() {
	file = fopen(name, "w+");
	printf("Starting dump to:\n");
	puts(name);
}
void WriteDriveData::Execute() {
	fprintf(file, "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f, %f\n",
		Robot::driveTrain->GetDriveSpeed(true), Robot::driveTrain->GetDriveVoltage(true),
		Robot::driveTrain->GetDriveCurrent(true), Robot::driveTrain->GetDriveSpeed(false),
		Robot::driveTrain->GetDriveVoltage(false), Robot::driveTrain->GetDriveCurrent(false),
		Robot::shooter->GetEncoderSpeed(), Robot::shooter->GetVoltage(), Robot::shooter->GetCurrent(),
		DriverStation::GetInstance()->GetBatteryVoltage(), Robot::driveTrain->GetGyroAngle());
}
bool WriteDriveData::IsFinished() {return false;}
void WriteDriveData::End() {Finished();}
void WriteDriveData::Interrupted() {Finished();}
void WriteDriveData::Finished(){
	puts("Dump finished");
	fclose(file);
}
