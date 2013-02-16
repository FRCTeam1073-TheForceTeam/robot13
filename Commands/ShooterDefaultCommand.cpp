#include "ShooterDefaultCommand.h"
#include "ShooterAdjustAngle.h"
#include "ElevationPID.h"
ShooterDefaultCommand::ShooterDefaultCommand() {
	//AddParallel(new ShooterAdjustAngle()); dont want to be default, see spec sheet / heden
	printf ("ShooterDefaultCommand\n");
	//AddParallel(new ElevationPID());
}
