#include "SendDiagnostics.h"
#include "../Robot.h"

//#define DEBUG_DATA
#define CAN_TIMEOUT -44087
#define DEGREES_PER_VOLT 66.19
#define START_VOLTAGE 1.71
#define START_ANGLE 0
SendDiagnostics::SendDiagnostics() {
	diagnosticsTable = NetworkTable::GetTable("diagnosticsTable");
	count = 0;
	Requires(Robot::diagnostics);
}

// Called just before this Command runs the first time
void SendDiagnostics::Initialize() {
	leftDriveExists = RobotMap::driveTrainLeftMotor->ExistsOnBus();
	printf("leftDriveExists %d\n", leftDriveExists);
	rightDriveExists = RobotMap::driveTrainRightMotor->ExistsOnBus();
	printf("rightDriveExists %d\n", rightDriveExists);
	primaryShooterExists = RobotMap::shooterJag->ExistsOnBus();
	printf("primaryShooterExists %d\n", primaryShooterExists);
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
	if(primaryShooterExists){JagDiags("Front Shooter", RobotMap::shooterJag, false);}
	if (Robot::whichRobot == Robot::newRobot){
		
		//logic for locked on (DOESN'T INCLUDE LATERAL MOTION)
		//basically checked if calc angles and rpms agree
		bool isLockedOn = false;
		float calcAng = Robot::allignmentData->GetCalculatedAngle(); //degrees 
		float calcRPM = Robot::allignmentData->GetCalculatedVelocityRPM();
		float curAng = Robot::elevator->GetCurrentAngle(); //currently a voltage
		float curRPM = RobotMap::newShooterIREncoder->GetRPM();
		bool doAngsMatch = (curAng <= calcAng + 5) && (curAng >= calcAng - 5);
		bool doRPMsMatch = (curRPM <= calcRPM + 200) && (curRPM >= calcRPM - 200);
		if(doAngsMatch && doRPMsMatch) {
			isLockedOn = true;
		}
		else isLockedOn = false;
		SmartDashboard::PutBoolean("Is Locked On", isLockedOn);
		SmartDashboard::PutNumber("Shooter Elevation Angle", curAng);
		
		
		//drive encoders 
		SmartDashboard::PutNumber("Left Drive Encoder", Robot::driveTrain->leftMotor->GetSpeed());
		SmartDashboard::PutNumber("Right Drive Encoder", Robot::driveTrain->rightMotor->GetSpeed());
		
#ifdef DEBUG_DATA
		SmartDashboard::PutNumber("Left Mag", RobotMap::climberArmLeftWindowEncoder->GetVoltage());
		SmartDashboard::PutNumber("Right mag", RobotMap::climberArmRightWindowEncoder->GetVoltage());
#endif
	}
	if (Robot::whichRobot == Robot::newRobot || Robot::whichRobot == Robot::mobileBase) {
		//Shooter Encoders
		diagnosticsTable->PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
		//Disc Present
		
		//SmartDashboard::PutNumber("Shooter Elevation Angle", RobotMap::shooterElevationEncoder->GetVoltage());
		
		SmartDashboard::PutNumber("Shooter Current Speed", RobotMap::newShooterIREncoder->GetRPM()/30);
		
		SmartDashboard::PutNumber("Shooter Current Speed TESTBOX", RobotMap::newShooterIREncoder->GetRPM());
	}
#ifdef DEBUG_DATA
	//Gyro
	diagnosticsTable->PutNumber("Drive Train Gyro Angle", RobotMap::driveTrainGyro->GetAngle());
#endif


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
