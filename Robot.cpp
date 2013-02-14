#include "Robot.h"
#include "RobotMap.h"
#include "Commands/AutonomousSequence.h"
#include <Preferences.h>

OI* Robot::oi = NULL; 
//Greg Generated Static Variables
Climber* Robot::climber = NULL;
ClimberArms* Robot::climberArms = NULL;
DriveTrain* Robot::driveTrain = NULL;
Collector* Robot::collector = NULL;
Shooter* Robot::shooter = NULL;
AllignmentData* Robot::allignmentData = NULL;
DiscVelocity* Robot::discVelocity = NULL;
DigitalInput* Robot::jumper13 = NULL;
DigitalInput* Robot::jumper14 = NULL;
Diagnostics* Robot::diagnostics = NULL;
DigitalInput* Robot::jumper12 = NULL;
Robot::WhichRobot_t Robot::whichRobot;
Robot::Robot() {
	//NetworkTable::SetTeam(1073);
}
void Robot::RobotInit() {
	Preferences *prefs = Preferences::GetInstance();
	scaleType_t scaleTypePref;
	float scaleFactorPref;
	
	printf("\n\nFRC2013 " __DATE__ " " __TIME__ "\n" __FILE__ "\n\n" );
	
	RobotMap::init();
	
	scaleTypePref = (scaleType_t) prefs->GetInt("RearShooterScaleType", identical);
	scaleFactorPref = prefs->GetFloat("RearShooterScaleValue", 1.0);
	prefs->Save();
	
	jumper12 = new DigitalInput(DIGITAL_JUMPER_12);
	jumper13 = new DigitalInput(DIGITAL_JUMPER_13);
	jumper14 = new DigitalInput(DIGITAL_JUMPER_14);	

	if (jumper13->Get() == 0)	whichRobot = elot;
	else if(jumper14->Get() == 0)	whichRobot = mobileBase;
	else if(jumper12->Get() == 0) whichRobot = libra;
	else	whichRobot = newRobot;
	
	switch(whichRobot)
	{
	printf("Robot is ");
	case elot:
		printf("Elot");
		break;
	case mobileBase:
		printf("Mobile base");
		break;
	case newRobot:
		printf("new robot");
		break;
	case libra:
		printf("Libra");
		break;
	default:
		printf("something else -- HELP!");
	}
	printf("\n");
	climber = new Climber();
	driveTrain = new DriveTrain();
	collector = new Collector();
	shooter = new Shooter();
	allignmentData = new AllignmentData();
	diagnostics = new Diagnostics();
	discVelocity = new DiscVelocity(RobotMap::velocity1);
	oi = new OI();
	lw = LiveWindow::GetInstance();
	
	shooter->SetBackMode(scaleTypePref, scaleFactorPref);
	
	chooser = new SendableChooser();
	chooser->AddDefault("Right Back", new AutonomousSequence(AutonomousSequence::rightBack));
	chooser->AddObject("Left Back", new AutonomousSequence(AutonomousSequence::leftBack));
	chooser->AddObject("Middle Back", new AutonomousSequence(AutonomousSequence::middleBack));
			
	SmartDashboard::PutData(AUTONOMOUS_CHOOSER_KEY, chooser);
	SmartDashboard::PutNumber(AUTONOMOUS_WAIT_TIME, 3);
	SmartDashboard::PutNumber(SHOOTER_P, RobotMap::shooterFrontJag->GetP());
	SmartDashboard::PutNumber(SHOOTER_I, RobotMap::shooterFrontJag->GetI());
	SmartDashboard::PutNumber(SHOOTER_D, RobotMap::shooterFrontJag->GetD());
	SmartDashboard::PutNumber(SHOOTER_FRONT_SET_SPEED, shooter->GetFrontSetSpeed());
	SmartDashboard::PutNumber(SHOOTER_BACK_SET_SPEED, shooter->GetBackSetSpeed());
	SendNewDashboardData();
	autonomousCommand = new AutonomousSequence();
  }
	
void Robot::AutonomousInit() {	
	autonomousCommand = (Command *) chooser->GetSelected();
	const char* temporaryString = autonomousCommand->GetName().c_str();
	printf("Auto Command Chosen: %s\n", temporaryString);
	
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	autonomousCommand->Cancel();
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)	Scheduler::GetInstance()->Run();
	SendNewDashboardData();
}
void Robot::TestPeriodic() {
	lw->Run();
}
void Robot::SendNewDashboardData(){
	SmartDashboard::PutNumber(SHOOTER_FRONT_CURRENT_SPEED, RobotMap::shooterFrontJag->GetSpeed());
	SmartDashboard::PutNumber(SHOOTER_BACK_CURRENT_SPEED, RobotMap::shooterBackJag->GetSpeed());
}
Robot::WhichRobot_t Robot::GetWhichRobot(){return whichRobot;}
START_ROBOT_CLASS(Robot);
