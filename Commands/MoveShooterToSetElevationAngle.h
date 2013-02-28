#ifndef MOVE_SHOOTER_TO_SET_ELEVATION_ANGLE_H
#define MOVE_SHOOTER_TO_SET_ELEVATION_ANGLE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class MoveShooterToSetElevationAngle : public Command{
public:
	MoveShooterToSetElevationAngle();
	MoveShooterToSetElevationAngle(bool encoderCheck);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool encoderCheck;
};
#endif
