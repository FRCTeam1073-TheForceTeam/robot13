#include "SendDiagnostics.h"
#include "../Robot.h"

#define CAN_TIMEOUT -44087

SendDiagnostics::SendDiagnostics() {
	diagnosticsTable = NetworkTable::GetTable("diagnosticsTable");
	count = 0;
	Requires(Robot::diagnostics);
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
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
}

// Called repeatedly when this Command is scheduled to run
void SendDiagnostics::Execute() {
	count++;
	if(count % 20 != 0)
	{
		return;
	}
		
	//Drive Train Jaguar Diagnostics
	if(leftDriveExists == true)
	{
		diagnosticsTable->PutNumber("Left Drive Jag Current", RobotMap::driveTrainLeftMotor->GetOutputCurrent());
		diagnosticsTable->PutNumber("Left Drive Jag Bus Voltage", RobotMap::driveTrainLeftMotor->GetBusVoltage());
		diagnosticsTable->PutNumber("Left Drive Jag Voltage", RobotMap::driveTrainLeftMotor->GetOutputVoltage());
		diagnosticsTable->PutNumber("Left Drive Jag Temperature", RobotMap::driveTrainLeftMotor->GetTemperature());
		diagnosticsTable->PutNumber("Left Drive Train Position", RobotMap::driveTrainLeftMotor->GetPosition());
	}
	if(rightDriveExists == true){
		diagnosticsTable->PutNumber("Right Drive Jag Current", RobotMap::driveTrainRightMotor->GetOutputCurrent());
		diagnosticsTable->PutNumber("Right Drive Jag Bus Voltage", RobotMap::driveTrainRightMotor->GetBusVoltage());
		diagnosticsTable->PutNumber("Right Drive Jag Voltage", RobotMap::driveTrainRightMotor->GetOutputVoltage());
		diagnosticsTable->PutNumber("Right Drive Jag Temperature", RobotMap::driveTrainRightMotor->GetTemperature());
		diagnosticsTable->PutNumber("Right Drive Train Position", RobotMap::driveTrainRightMotor->GetPosition());
	}
	//Shooter Jaguar Diagnostics
	if(elevationShooterExists == true){
		diagnosticsTable->PutNumber("Shooter Elevation Jag Current", RobotMap::shooterElevationJag->GetOutputCurrent());
		diagnosticsTable->PutNumber("Shooter Elevation Jag Bus Voltage", RobotMap::shooterElevationJag->GetBusVoltage());
		diagnosticsTable->PutNumber("Shooter Elevation Jag Voltage", RobotMap::shooterElevationJag->GetOutputVoltage());
		diagnosticsTable->PutNumber("Shooter Elevation Jag Temperature", RobotMap::shooterElevationJag->GetTemperature());
	}
	if(primaryShooterExists == true){
		diagnosticsTable->PutNumber("Front Shooter Jag Current", RobotMap::shooterFrontJag->GetOutputCurrent());
		diagnosticsTable->PutNumber("Front Shooter Jag Bus Voltage", RobotMap::shooterFrontJag->GetBusVoltage());
		diagnosticsTable->PutNumber("Front Shooter Jag Voltage", RobotMap::shooterFrontJag->GetOutputVoltage());
		diagnosticsTable->PutNumber("Front Shooter Jag Temperature", RobotMap::shooterFrontJag->GetTemperature());
	}
	if(supportShooterExists == true){
		diagnosticsTable->PutNumber("Back Shooter Jag Current", RobotMap::shooterBackJag->GetOutputCurrent());
		diagnosticsTable->PutNumber("Back Shooter Jag Bus Voltage", RobotMap::shooterBackJag->GetBusVoltage());
		diagnosticsTable->PutNumber("Back Shooter Jag Voltage", RobotMap::shooterBackJag->GetOutputVoltage());
		diagnosticsTable->PutNumber("Back Shooter Jag Temperature", RobotMap::shooterBackJag->GetTemperature());
	}
	//Shooter Encoders
	diagnosticsTable->PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
	//Gyro
	diagnosticsTable->PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
	//Disc Count
	diagnosticsTable->PutNumber(COLLECTOR_DISC_COUNT, Robot::collector->GetNumberOfDiscs());
	//Battery Voltage
	diagnosticsTable->PutNumber("Battery Voltage", DriverStation::GetInstance()->GetBatteryVoltage());
	//MatchTimer
	diagnosticsTable->PutNumber("Match Timer", DriverStation::GetInstance()->GetMatchTime());
	
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
