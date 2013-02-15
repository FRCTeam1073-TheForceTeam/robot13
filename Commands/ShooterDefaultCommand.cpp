#include "ShooterDefaultCommand.h"
#include "ShooterAdjustAngle.h"
#include "ElevationPID.h"
ShooterDefaultCommand::ShooterDefaultCommand() {
	AddParallel(new ShooterAdjustAngle());
	printf ("ShooterDefaultCommand\n");
	//AddParallel(new ElevationPID());
}
