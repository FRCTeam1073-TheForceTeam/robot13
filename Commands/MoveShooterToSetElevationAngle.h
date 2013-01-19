#ifndef MOVE_SHOOTER_TO_SET_ELEVATION_ANGLE_H
#define MOVE_SHOOTER_TO_SET_ELEVATION_ANGLE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class MoveShooterToSetElevationAngle : public Command{
private: void Done();
public:
	MoveShooterToSetElevationAngle();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
