#include "SetToFeederAngle.h"
#include "MoveShooterToSetElevationAngle.h"
#include "../Subsystems/Elevator.h"

SetToFeederAngle::SetToFeederAngle(){
	AddSequential(new MoveShooterToSetElevationAngle());
	
};

void SetToFeederAngle::Initialize(){
	Robot::elevator->SetToFeederAngle();
	
}

