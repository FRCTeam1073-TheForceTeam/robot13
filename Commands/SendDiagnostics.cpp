#include "SendDiagnostics.h"
#include "../Robot.h"

//#define DEBUG_DATA
#define CAN_TIMEOUT -44087
#define DEGREES_PER_VOLT 66.19
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
#ifdef DEBUG_DATA
	SmartDashboard::PutNumber(std::string(jagString) + "Encoder Value", thisJag->GetSpeed());
#endif
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
		
		//logic for locked on (DOESN'T INCLUDE LATERAL MOTION)
		//basically checked if calc angles and rpms agree
		bool isLockedOn = false;
		float calcAng = Robot::allignmentData->GetCalculatedAngle(); //degrees
		float calcRPM = Robot::allignmentData->GetCalculatedVelocityRPM();
		float curAng = RobotMap::shooterElevationEncoder->GetVoltage(); //currently a voltage
		curAng = ((curAng - 1.71) * DEGREES_PER_VOLT) + 10.5;
		float curRPM = RobotMap::shooterFrontJag->GetSpeed();
		bool doAngsMatch = (curAng <= calcAng + 5) && (curAng >= calcAng - 5);
		bool doRPMsMatch = (curRPM <= calcRPM + 200) && (curRPM >= calcRPM - 200);
		if(doAngsMatch && doRPMsMatch) {
			isLockedOn = true;
		}
		else isLockedOn = false;
		SmartDashboard::PutBoolean("Is Locked On", isLockedOn);
		
		//climber engaged
		SmartDashboard::PutBoolean("Is Climber Engaged", Robot::climber->GetClimberOnOff());
		
		//climber encoder values
		diagnosticsTable->PutNumber("Left Climber Encoder", Robot::climberArms->leftWindowEncoder->GetVoltage());
		diagnosticsTable->PutNumber("Right Climber Encoder", Robot::climberArms->rightWindowEncoder->GetVoltage());
		
		//drive encoders 
		SmartDashboard::PutNumber("Left Drive Encoder", Robot::driveTrain->leftMotor->GetSpeed());
		SmartDashboard::PutNumber("Right Drive Encoder", Robot::driveTrain->rightMotor->GetSpeed());
		
		SmartDashboard::PutNumber("Number of Discs", Robot::collector->GetNumberOfDiscs());
#ifdef DEBUG_DATA```
		SmartDashboard::PutNumber("Left Mag", RobotMap::climberArmLeftWindowEncoder->GetVoltage());
		SmartDashboard::PutNumber("Right mag", RobotMap::climberArmRightWindowEncoder->GetVoltage());
#endif
	}
	if (Robot::whichRobot == Robot::newRobot || Robot::whichRobot == Robot::mobileBase) {
		//Shooter Encoders
		diagnosticsTable->PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
		//Disc Count
		diagnosticsTable->PutNumber(COLLECTOR_DISC_COUNT, Robot::collector->GetNumberOfDiscs());
		//Disc Present
		diagnosticsTable->PutNumber("Disc In Shooter", RobotMap::collectorDiscOnShooterBed->Get());
		
		SmartDashboard::PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
		
		//scaled to 0-100 percentage
		SmartDashboard::PutNumber("Shooter Front Current Speed", RobotMap::shooterFrontJag->GetSpeed() / 37.5);
		SmartDashboard::PutNumber("Shooter Back Current Speed", RobotMap::shooterBackJag->GetSpeed() / 37.5);
	}
#ifdef DEBUG_DATA
	//Gyro
	diagnosticsTable->PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
#endif
	if(Robot::discVelocity->IsThereNewData()){
		float velocity = Robot::discVelocity->GetVelocityFPS();
		float time = Robot::discVelocity->GetEllapsedTime();
#ifdef DEBUG_DATA
		SmartDashboard::PutNumber(DISC_SHOT_SPEED_FPS, velocity);
		SmartDashboard::PutNumber(DISC_ELLAPSED_TIME, time);
#endif
	}
	
	if(Robot::whichRobot == Robot::mobileBase || Robot::whichRobot == Robot::elot) {
		SmartDashboard::PutNumber("Number of Discs", 2);
		SmartDashboard::PutBoolean("Is Locked On", false);
		SmartDashboard::PutBoolean("Is Climber Engaged", false);
	}
	//calculated values from extension onto dash
	float calcAngle = Robot::allignmentData->GetCalculatedAngle();
	float calcVelocityRPM = Robot::allignmentData->GetCalculatedVelocityRPM();		
	SmartDashboard::PutNumber("Calculated Angle", calcAngle);
	SmartDashboard::PutNumber("Calculated Velocity RPM", calcVelocityRPM);
} 
bool SendDiagnostics::IsFinished() {return false;}
void SendDiagnostics::End() {}
void SendDiagnostics::Interrupted() {}
