#include "SendDiagnostics.h"
#include "../Robot.h"

SendDiagnostics::SendDiagnostics() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void SendDiagnostics::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void SendDiagnostics::Execute() {
	//Drive Train Jaguar Diagnostics
	SmartDashboard::PutNumber("Left Drive Jag Current", RobotMap::driveTrainLeftDriveMotor->GetOutputCurrent());
	SmartDashboard::PutNumber("Left Drive Jag Bus Voltage", RobotMap::driveTrainLeftDriveMotor->GetBusVoltage());
	SmartDashboard::PutNumber("Left Drive Jag Voltage", RobotMap::driveTrainLeftDriveMotor->GetOutputVoltage());
	SmartDashboard::PutNumber("Left Drive Jag Temperature", RobotMap::driveTrainLeftDriveMotor->GetTemperature());
	SmartDashboard::PutNumber("Right Drive Jag Current", RobotMap::driveTrainRightDriveMotor->GetOutputCurrent());
	SmartDashboard::PutNumber("Right Drive Jag Bus Voltage", RobotMap::driveTrainRightDriveMotor->GetBusVoltage());
	SmartDashboard::PutNumber("Right Drive Jag Voltage", RobotMap::driveTrainRightDriveMotor->GetOutputVoltage());
	SmartDashboard::PutNumber("Right Drive Jag Temperature", RobotMap::driveTrainRightDriveMotor->GetTemperature());
	//Shooter Diagnostics
	SmartDashboard::PutNumber("Shooter Elevation Jag Current", RobotMap::shooterElevationJag->GetOutputCurrent());
	SmartDashboard::PutNumber("Shooter Elevation Jag Bus Voltage", RobotMap::shooterElevationJag->GetBusVoltage());
	SmartDashboard::PutNumber("Shooter Elevation Jag Voltage", RobotMap::shooterElevationJag->GetOutputVoltage());
	SmartDashboard::PutNumber("Shooter Elevation Jag Temperature", RobotMap::shooterElevationJag->GetTemperature());
	SmartDashboard::PutNumber("Shooter Jag Current", RobotMap::shooterShooterJag->GetOutputCurrent());
	SmartDashboard::PutNumber("Shooter Jag Bus Voltage", RobotMap::shooterShooterJag->GetBusVoltage());
	SmartDashboard::PutNumber("Shooter Jag Voltage", RobotMap::shooterShooterJag->GetOutputVoltage());
	SmartDashboard::PutNumber("Shooter Jag Temperature", RobotMap::shooterShooterJag->GetTemperature());
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
