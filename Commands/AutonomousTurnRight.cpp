#include "AutonomousTurnRight.h"
#define FORWARD_SPEED 100
#define TURNING_ANGLE 90
AutonomousTurnRight::AutonomousTurnRight() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveTrain);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void AutonomousTurnRight::Initialize() {
	Robot::driveTrain->Move(FORWARD_SPEED, 0);
}
// Called repeatedly when this Command is scheduled to run
void AutonomousTurnRight::Execute() {
	
}
// Make this return true when this Command no longer needs to run execute()
bool AutonomousTurnRight::IsFinished() {
	float currentAngle = Robot::driveTrain->GetGyroAngle();
	if (currentAngle - startingAngle > TURNING_ANGLE)
		return true;
	return false;
}
// Called once after isFinished returns true
void AutonomousTurnRight::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousTurnRight::Interrupted() {
}
