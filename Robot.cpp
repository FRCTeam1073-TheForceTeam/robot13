#include "Robot.h"
#include "RobotMap.h"
#include "Commands/AutonomousRightBack.h"
#include "Commands/AutonomousLeftBack.h"
#include "Commands/AutonomousMiddleBack.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
//Greg Generated Static Variables
Climber* Robot::climber = NULL;
DriveTrain* Robot::driveTrain = NULL;
Collector* Robot::collector = NULL;
Shooter* Robot::shooter = NULL;
AllignmentData* Robot::allignmentData = NULL;
DiscVelocity* Robot::discVelocity = NULL;
Robot::Robot() {
	//NetworkTable::SetTeam(1073);
}
void Robot::RobotInit() {
	printf("\n\nFRC2013 " __DATE__ " " __TIME__ "\n" __FILE__ "\n\n" );
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	climber = new Climber();
	driveTrain = new DriveTrain();
	collector = new Collector();
	shooter = new Shooter();
	allignmentData = new AllignmentData();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	discVelocity = new DiscVelocity(RobotMap::velocity1);
	oi = new OI();
	lw = LiveWindow::GetInstance();
	
	chooser = new SendableChooser();
	chooser->AddDefault("Right Back", new AutonomousRightBack());
	chooser->AddObject("Left Back", new AutonomousLeftBack());
	chooser->AddObject("Middle Back", new AutonomousMiddleBack());
			
	//Add another option here
	SmartDashboard::PutData(AUTONOMOUS_CHOOSER_KEY, chooser);
	SmartDashboard::PutNumber(AUTONOMOUS_WAIT_TIME, 3);

	SmartDashboard::PutNumber(SHOOTER_P, 0.04 );
	SmartDashboard::PutNumber(SHOOTER_I, 0.003);
	SmartDashboard::PutNumber(SHOOTER_D, 0);
	SmartDashboard::PutNumber(SHOOTER_FRONT_SET_SPEED, 1500);
	SmartDashboard::PutNumber(SHOOTER_BACK_SET_SPEED, 1500);
	SendNewDashboardData();
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousRightBack();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
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
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
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
	SmartDashboard::PutNumber(SHOOTER_RPM_ENCODER, RobotMap::shooterWheelRPMEncoder->Get());		
}
START_ROBOT_CLASS(Robot);
