#include "Robot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
//Greg Generated Static Variables
Climber* Robot::climber = NULL;
DriveTrain* Robot::driveTrain = NULL;
Collector* Robot::collector = NULL;
Shooter* Robot::shooter = NULL;

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	climber = new Climber();
	driveTrain = new DriveTrain();
	collector = new Collector();
	shooter = new Shooter();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
	
	chooser = new SendableChooser();
	chooser->AddDefault("Default Auto", new AutonomousCommand);
	chooser->AddObject("Test Command", new TestSmartDashboard);
	//Add another option here
	SmartDashboard::PutData("Autonomous Chooser", chooser);
	
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
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
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
	
	SmartDashboard::PutNumber("Jag 5 Temperature", shooter->shooterJag->GetTemperature());
}
void Robot::TestPeriodic() {
	lw->Run();
}
START_ROBOT_CLASS(Robot);
