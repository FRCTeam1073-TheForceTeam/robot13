
#include "TurboDriveOn.h"
TurboDriveOn::TurboDriveOn() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void TurboDriveOn::Initialize() {
	Robot::driveTrain->TurboOnOff(true);
	//printf("TurboDriveOn Initialize\n");
}
// Called repeatedly when this Command is scheduled to run
void TurboDriveOn::Execute() {
}
// Make this return true when this Command no longer needs to run execute()
bool TurboDriveOn::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void TurboDriveOn::End() {
	//printf("TurboDriveOn End\n");
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurboDriveOn::Interrupted() {
	Robot::driveTrain->TurboOnOff(false);

	//printf("TurboDriveOn Interrupted\n");
}
