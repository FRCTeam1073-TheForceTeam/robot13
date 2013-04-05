#include "ElevateToGoodPosition.h"
#include "MoveShooterToSetElevationAngle.h"
ElevateToGoodPosition::ElevateToGoodPosition(){AddSequential(new MoveShooterToSetElevationAngle(true));}
void ElevateToGoodPosition::Initialize(){
	Robot::elevator->SetRawAngle(Robot::elevator->GetGoodShootingAngle());
}
