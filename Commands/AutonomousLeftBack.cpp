#include "AutonomousLeftBack.h"
#include "Commands/WaitCommand.h"
#include "ShooterOn.h"
#include "Shoot.h"
#include "MoveShooterToSetElevationAngle.h"
#include "ShooterOff.h"
#include "../Subsystems/Shooter.h"

float GetWaitTime()
{
	double waitTime = 3;
	try
	{
		waitTime = SmartDashboard::GetNumber("AutonomousWaitTime");
	}
	catch(exception e)
	{
		//dont care
	}
	
	return waitTime;
}

AutonomousLeftBack::AutonomousLeftBack() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	
	int elevationAngle = 14;
	int shooterSpeed = 1500;
	double shotWaitTime = 1;
	double waitTime = GetWaitTime();
	Robot::shooter->SetRawElevationAngle(elevationAngle);
	Robot::shooter->SetRawSpeed(shooterSpeed);
	AddSequential(new MoveShooterToSetElevationAngle());
	AddSequential(new ShooterOn());
	AddSequential(new WaitCommand(waitTime));
	AddSequential(new Shoot());
	AddSequential(new WaitCommand(shotWaitTime));
	AddSequential(new Shoot());
	AddSequential(new WaitCommand(shotWaitTime));
	AddSequential(new Shoot());
	AddSequential(new ShooterOff());
}
