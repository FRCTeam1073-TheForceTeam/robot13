#include "Robot.h"
#include "RobotMap.h"
#include "Commands/AutonomousSequence.h"
#include "Commands/SendDiagnostics.h"
#include <Preferences.h>

//#define DEBUG_DATA

OI* Robot::oi = NULL; 
DriveTrain* Robot::driveTrain = NULL;
Collector* Robot::collector = NULL;
Shooter* Robot::shooter = NULL;
Elevator* Robot::elevator = NULL;
AllignmentData* Robot::allignmentData = NULL;
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
	bool isElevatorEncoderFailed;
	float leftArmUpEncValPref;
	float leftArmMiddleEncValPref;
	float leftArmDownEncValPref;
	float rightArmUpEncValPref;
	float rightArmMiddleEncValPref;
	float rightArmDownEncValPref;
	
	float elevatorEncoderMinVoltage = 1.71f;
	float elevatorEncoderMaxVoltage = 2.34f;
	 
	
	printf("\n\nFRC2013 " __DATE__ " " __TIME__ "\n" __FILE__ "\n\n" );
	
	RobotMap::init();
	
	//shooter preferences
	scaleTypePref = (scaleType_t) prefs->GetInt("RearShooterScaleType", identical);
	scaleFactorPref = prefs->GetFloat("RearShooterScaleValue", 1.0);
	isElevatorEncoderFailed = prefs->GetBoolean("isElevatorEncoderFailed", false);
	//shooter elevating preferences
	elevatorEncoderMinVoltage = prefs->GetFloat("elevatorEncoderMinVoltage", elevatorEncoderMinVoltage);
	elevatorEncoderMaxVoltage = prefs->GetFloat("elevatorEncoderMaxVoltage", elevatorEncoderMaxVoltage);

	
	//turns out this isn;t quite done - i used the pound defines in shooter.cpp
	//Robot::shooter->UpdateElevatorAngleConstants(elevatorEncoderMinVoltage, elevatorEncoderMaxVoltage);

	
	//chainsaw preferences
	leftArmUpEncValPref  = prefs->GetFloat("leftArmUpEncVal", 3.3f);
	leftArmMiddleEncValPref = prefs->GetFloat("leftArmMiddleEncVal", 2.6f);
	leftArmDownEncValPref = prefs->GetFloat("leftArmDownEncVal", 1.9f);
	rightArmUpEncValPref = prefs->GetFloat("rightArmUpEncVal", 0.82f);
	rightArmMiddleEncValPref = prefs->GetFloat("rightArmMiddleEncVal", 1.4f);
	rightArmDownEncValPref  = prefs->GetFloat("rightArmDownEncVal", 2.15f);
	
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
	if(whichRobot == newRobot) {}
	if(whichRobot == mobileBase || whichRobot == newRobot){}
	if(whichRobot == mobileBase || whichRobot == newRobot || whichRobot == elot) {
		collector = new Collector();
		shooter = new Shooter();
		allignmentData = new AllignmentData();
		elevator = new Elevator();
		elevator->SetEncoderFailed(isElevatorEncoderFailed);
		//is elevation encoder failed preference		
	}

	driveTrain = new DriveTrain();
	diagnostics = new Diagnostics();
	
	oi = new OI();
	lw = LiveWindow::GetInstance();
	
	chooser = new SendableChooser();
	chooser->AddDefault("Right Back", new AutonomousSequence(AutonomousSequence::rightBack));
	chooser->AddObject("Left Back", new AutonomousSequence(AutonomousSequence::leftBack));
	chooser->AddObject("Middle Back", new AutonomousSequence(AutonomousSequence::middleBack));
			
	SmartDashboard::PutData(AUTONOMOUS_CHOOSER_KEY, chooser);
	
#ifdef DEBUG_DATA
	SmartDashboard::PutNumber(AUTONOMOUS_WAIT_TIME, 3);
	SmartDashboard::PutNumber(SHOOTER_P, RobotMap::shooterFrontJag->GetP());
	SmartDashboard::PutNumber(SHOOTER_I, RobotMap::shooterFrontJag->GetI());
	SmartDashboard::PutNumber(SHOOTER_D, RobotMap::shooterFrontJag->GetD());
	SmartDashboard::PutNumber(SHOOTER_FRONT_SET_SPEED, shooter->GetFrontSetSpeed());
	SmartDashboard::PutNumber(SHOOTER_BACK_SET_SPEED, shooter->GetBackSetSpeed());
#endif
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
	Robot::elevator->MotorOff();
	Robot::collector->MotorOff();
}
	
void Robot::TeleopPeriodic() {
	if (autonomousCommand != NULL)	Scheduler::GetInstance()->Run();
}
void Robot::TestPeriodic() {
	lw->Run();
}
void Robot::DisabledInit(){
	SendDiagnostics* SmoothDiags = new SendDiagnostics();
	SmoothDiags->Start();
}
Robot::WhichRobot_t Robot::GetWhichRobot(){return whichRobot;}
START_ROBOT_CLASS(Robot);
