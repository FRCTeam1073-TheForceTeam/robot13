#include "SendDiagnostics.h"
#include "../Robot.h"

#define CAN_TIMEOUT -44087

SendDiagnostics::SendDiagnostics() {
	diagnosticsTable = NetworkTable::GetTable("diagnosticsTable");
	count = 0;
	Requires(Robot::diagnostics);
}

bool SendDiagnostics::TestJags(CANJaguar* jag)
{

	bool exists = false;
	jag->GetFirmwareVersion();
	if(jag->GetError().GetCode() == CAN_TIMEOUT)
	{
		jag->ClearError();
		exists = false;
	}
	else
	{
		exists = true;
	}
	return exists;
}

// Called just before this Command runs the first time
void SendDiagnostics::Initialize() {
	leftDriveExists = TestJags(RobotMap::driveTrainLeftMotor);
	rightDriveExists = TestJags(RobotMap::driveTrainRightMotor);
	leftClimberExists = TestJags(RobotMap::climberLeftCIM);
	rightClimberExists = TestJags(RobotMap::climberRightCIM);
	primaryShooterExists = TestJags(RobotMap::shooterFrontJag);
	supportShooterExists = TestJags(RobotMap::shooterBackJag);
	elevationShooterExists = TestJags(RobotMap::shooterElevationJag);
	return;
}

// Common function for handling jag diagnostics
void SendDiagnostics::JagDiags(char *jagString, CANJaguar *thisJag, bool printPosition)
{
	diagnosticsTable->PutNumber(std::string(jagString) + "Jag Current", thisJag->GetOutputCurrent());
	diagnosticsTable->PutNumber(std::string(jagString) + "Jag Bus Voltage", thisJag->GetBusVoltage());
	diagnosticsTable->PutNumber(std::string(jagString) + "Jag Voltage", thisJag->GetOutputVoltage());
	diagnosticsTable->PutNumber(std::string(jagString) + "Jag Temperature", thisJag->GetTemperature());
	if (printPosition)
		diagnosticsTable->PutNumber(std::string(jagString) + "Train Position", thisJag->GetPosition());
		
	printf("%s %f\n", std::string(jagString) + "Encoder Value", thisJag->GetSpeed());
	SmartDashboard::PutNumber(std::string(jagString) + "Encoder Value", thisJag->GetSpeed());
}
// Called repeatedly when this Command is scheduled to run
void SendDiagnostics::Execute() {
	count++;
	if(count % 20 != 0)
	{
		return;
	}

	//MatchTimer
	diagnosticsTable->PutNumber("Match Timer", DriverStation::GetInstance()->GetMatchTime());
	//printf("Sending up Match Time");
	//Battery Voltage
	diagnosticsTable->PutNumber("Battery Voltage", DriverStation::GetInstance()->GetBatteryVoltage());
		
	if(leftDriveExists)
	{
		JagDiags("Left Drive", RobotMap::driveTrainLeftMotor, true);
	}
	if(rightDriveExists){
		JagDiags("Right Drive", RobotMap::driveTrainRightMotor, true);
	}
	if(elevationShooterExists){
		JagDiags("Shooter Elevation", RobotMap::shooterElevationJag, false);
	}
	if(primaryShooterExists){
		JagDiags("Front Shooter", RobotMap::shooterFrontJag, false);
	}
	if(supportShooterExists){
		JagDiags("Back Shooter", RobotMap::shooterBackJag, false);
	}
	if(leftClimberExists){
		JagDiags("Left Climb", RobotMap::climberLeftCIM, true);
	}
	if(rightClimberExists){
		JagDiags("Right Climb", RobotMap::climberRightCIM, true);
	}
	//Shooter Encoders
	diagnosticsTable->PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
	//Gyro
	diagnosticsTable->PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
	//Disc Count
	diagnosticsTable->PutNumber(COLLECTOR_DISC_COUNT, Robot::collector->GetNumberOfDiscs());
	//Disc Inverted?
	diagnosticsTable->PutBoolean("Bottom Disc Reversed", Robot::collector->IsNextDiscUpsideDown());
	//climber encoder values
	diagnosticsTable->PutNumber("Left Climber Encoder", Robot::climberArms->leftWindowEncoder->GetVoltage());
	diagnosticsTable->PutNumber("Right Climber Encoder", Robot::climberArms->rightWindowEncoder->GetVoltage());
	
	SmartDashboard::PutNumber("Left Mag", RobotMap::climberArmLeftWindowEncoder->GetVoltage());
	SmartDashboard::PutNumber("Right mag", RobotMap::climberArmRightWindowEncoder->GetVoltage());

	return;
} 

// Make this return true when this Command no longer needs to run execute()
bool SendDiagnostics::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void SendDiagnostics::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SendDiagnostics::Interrupted() {

}
