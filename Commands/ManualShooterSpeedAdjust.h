#ifndef MANUAL_SHOOTER_SPEED_ADJUST_H
#define MANUAL_SHOOTER_SPEED_ADJUST_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ManualShooterSpeedAdjust : public Command{
public:
	ManualShooterSpeedAdjust(bool positive, bool coarse);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool positive, coarse;
};
#endif
