#include "SendDiagnostics.h"
#include "../Robot.h"3

#define CAN_TIMEOUT -44087

SendDiagnostics::SendDiagnostics() {
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
leftClimberExists = TestJags(RobotMap::climberLeftClimberJag);
rightClimberExists = TestJags(RobotMap::climberRightClimberJag);
primaryShooterExists = TestJags(RobotMap::shooterPrimaryJag);
supportShooterExists = TestJags(RobotMap::shooterSupportJag);
elevationShooterExists = TestJags(RobotMap::shooterElevationJag);
}

// Called repeatedly when this Command is scheduled to run
void SendDiagnostics::Execute() {
	//Drive Train Jaguar Diagnostics
	if(leftDriveExists == true)
	{
		SmartDashboard::PutNumber("Left Drive Jag Current", RobotMap::driveTrainLeftMotor->GetOutputCurrent());
		SmartDashboard::PutNumber("Left Drive Jag Bus Voltage", RobotMap::driveTrainLeftMotor->GetBusVoltage());
		SmartDashboard::PutNumber("Left Drive Jag Voltage", RobotMap::driveTrainLeftMotor->GetOutputVoltage());
		SmartDashboard::PutNumber("Left Drive Jag Temperature", RobotMap::driveTrainLeftMotor->GetTemperature());
	}
	if(rightDriveExists == true){
		SmartDashboard::PutNumber("Right Drive Jag Current", RobotMap::driveTrainRightMotor->GetOutputCurrent());
		SmartDashboard::PutNumber("Right Drive Jag Bus Voltage", RobotMap::driveTrainRightMotor->GetBusVoltage());
		SmartDashboard::PutNumber("Right Drive Jag Voltage", RobotMap::driveTrainRightMotor->GetOutputVoltage());
		SmartDashboard::PutNumber("Right Drive Jag Temperature", RobotMap::driveTrainRightMotor->GetTemperature());
	}
	//Shooter Jaguar Diagnostics
	if(elevationShooterExists == true){
		SmartDashboard::PutNumber("Shooter Elevation Jag Current", RobotMap::shooterElevationJag->GetOutputCurrent());
		SmartDashboard::PutNumber("Shooter Elevation Jag Bus Voltage", RobotMap::shooterElevationJag->GetBusVoltage());
		SmartDashboard::PutNumber("Shooter Elevation Jag Voltage", RobotMap::shooterElevationJag->GetOutputVoltage());
		SmartDashboard::PutNumber("Shooter Elevation Jag Temperature", RobotMap::shooterElevationJag->GetTemperature());
	}
	if(primaryShooterExists == true){
		SmartDashboard::PutNumber("Primary Shooter Jag Current", RobotMap::shooterPrimaryJag->GetOutputCurrent());
		SmartDashboard::PutNumber("Primary Shooter Jag Bus Voltage", RobotMap::shooterPrimaryJag->GetBusVoltage());
		SmartDashboard::PutNumber("Primary Shooter Jag Voltage", RobotMap::shooterPrimaryJag->GetOutputVoltage());
		SmartDashboard::PutNumber("Primary Shooter Jag Temperature", RobotMap::shooterPrimaryJag->GetTemperature());
	}
	if(supportShooterExists == true){
		SmartDashboard::PutNumber("Support Shooter Jag Current", RobotMap::shooterSupportJag->GetOutputCurrent());
		SmartDashboard::PutNumber("Support Shooter Jag Bus Voltage", RobotMap::shooterSupportJag->GetBusVoltage());
		SmartDashboard::PutNumber("Support Shooter Jag Voltage", RobotMap::shooterSupportJag->GetOutputVoltage());
		SmartDashboard::PutNumber("Support Shooter Jag Temperature", RobotMap::shooterSupportJag->GetTemperature());
	}
	//Drive Train Encoders
	SmartDashboard::PutNumber("Left Drive Train Position", RobotMap::driveTrainLeftMotor->GetPosition());
	SmartDashboard::PutNumber("Right Drive Train Position", RobotMap::driveTrainRightMotor->GetPosition());
	//Shooter Encoders
	SmartDashboard::PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetDistance());
	SmartDashboard::PutNumber("Shooter Speed", RobotMap::shooterWheelRPMEncoder->GetRate());
	//Gyro
	SmartDashboard::PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
	//Altimiter
	SmartDashboard::PutNumber("Altimiter Value", RobotMap::navigationAltimiter->GetValue()); //not sure if GetValue is the function we want to be using?

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
