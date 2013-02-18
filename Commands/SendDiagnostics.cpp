#include "SendDiagnostics.h"
#include "../Robot.h"
#define CAN_TIMEOUT -44087
SendDiagnostics::SendDiagnostics() {
	diagnosticsTable = NetworkTable::GetTable("diagnosticsTable");
	count = 0;
	Requires(Robot::diagnostics);
}
bool SendDiagnostics::TestJags(CANJaguar* jag){
	jag->GetFirmwareVersion();
	if(jag->GetError().GetCode() == CAN_TIMEOUT)
	{
		jag->ClearError();
		return false;
	}
	return true;
}
// Called just before this Command runs the first time
void SendDiagnostics::Initialize() {
	leftDriveExists = TestJags(RobotMap::driveTrainLeftMotor);
	printf("leftDriveExists %d\n", leftDriveExists);
	rightDriveExists = TestJags(RobotMap::driveTrainRightMotor);
	printf("rightDriveExists %d\n", rightDriveExists);
	leftClimberExists = TestJags(RobotMap::climberLeftCIM);
	printf("leftClimberExists %d\n", leftClimberExists);
	rightClimberExists = TestJags(RobotMap::climberRightCIM);
	printf("rightClimberExists %d\n", rightClimberExists);
	primaryShooterExists = TestJags(RobotMap::shooterFrontJag);
	printf("primaryShooterExists %d\n", primaryShooterExists);
	supportShooterExists = TestJags(RobotMap::shooterBackJag);
	printf("supportShooterExists %d\n", supportShooterExists);
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
	
//	string foo = std::string(jagString) + "Encoder Value";
//	printf("%s %f\n", foo.c_str(), thisJag->GetSpeed());
	SmartDashboard::PutNumber(std::string(jagString) + "Encoder Value", thisJag->GetSpeed());
//	printf("sent jagSpeed to smartDashboard\n");
}
// Called repeatedly when this Command is scheduled to run
void SendDiagnostics::Execute() {
	count++;
	if(count % 20 != 0)	return;
	
	//MatchTimer
	diagnosticsTable->PutNumber("Match Timer", DriverStation::GetInstance()->GetMatchTime());
	diagnosticsTable->PutNumber("High Speed Timer", Timer::GetFPGATimestamp());
	//printf("Sending up Match Time");
	//Battery Voltage
	diagnosticsTable->PutNumber("Battery Voltage", DriverStation::GetInstance()->GetBatteryVoltage());
	if(leftDriveExists){JagDiags("Left Drive", RobotMap::driveTrainLeftMotor, true);}
	if(rightDriveExists){JagDiags("Right Drive", RobotMap::driveTrainRightMotor, true);}
	if(primaryShooterExists){JagDiags("Front Shooter", RobotMap::shooterFrontJag, false);}
	if(supportShooterExists){JagDiags("Back Shooter", RobotMap::shooterBackJag, false);}
	if(leftClimberExists){JagDiags("Left Climb", RobotMap::climberLeftCIM, true);}
	if(rightClimberExists){JagDiags("Right Climb", RobotMap::climberRightCIM, true);}
	if (Robot::whichRobot == Robot::newRobot){
		//climber encoder values
		diagnosticsTable->PutNumber("Left Climber Encoder", Robot::climberArms->leftWindowEncoder->GetVoltage());
		diagnosticsTable->PutNumber("Right Climber Encoder", Robot::climberArms->rightWindowEncoder->GetVoltage());		
		SmartDashboard::PutNumber("Left Mag", RobotMap::climberArmLeftWindowEncoder->GetVoltage());
		SmartDashboard::PutNumber("Right mag", RobotMap::climberArmRightWindowEncoder->GetVoltage());
	}
	if (Robot::whichRobot == Robot::newRobot || Robot::whichRobot == Robot::mobileBase) {
		//Shooter Encoders
		diagnosticsTable->PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
		//Disc Count
		diagnosticsTable->PutNumber(COLLECTOR_DISC_COUNT, Robot::collector->GetNumberOfDiscs());
		//Disc Present
		diagnosticsTable->PutNumber("Disc In Shooter", RobotMap::collectorDiscOnShooterBed->Get());
		SmartDashboard::PutNumber("Shooter Front Jag Speeed", RobotMap::shooterFrontJag->GetSpeed());
		SmartDashboard::PutNumber("Shooter Back Jag Speeed", RobotMap::shooterBackJag->GetSpeed());
	}
	//Gyro
	diagnosticsTable->PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
	if(Robot::discVelocity->IsThereNewData()){
		float velocity = Robot::discVelocity->GetVelocityFPS();
		float time = Robot::discVelocity->GetEllapsedTime();
		printf("Disc Shot @ %ffps!\nTime Delta:\t%f\n",velocity, time);
		SmartDashboard::PutNumber(DISC_SHOT_SPEED_FPS, velocity);
		SmartDashboard::PutNumber(DISC_ELLAPSED_TIME, time);
	}	
} 
bool SendDiagnostics::IsFinished() {return false;}
void SendDiagnostics::End() {}
void SendDiagnostics::Interrupted() {}
