#include "SetToFeederAngle.h"
#include "MoveShooterToSetElevationAngle.h"
#include "../Subsystems/Shooter.h"

SetToFeederAngle::SetToFeederAngle(){
	AddSequential(new MoveShooterToSetElevationAngle());
	
};

void SetToFeederAngle::Initialize(){
	Robot::shooter->SetToFeederPresetAngle();
	
}

