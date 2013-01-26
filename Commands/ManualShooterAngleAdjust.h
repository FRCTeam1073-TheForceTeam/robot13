#ifndef MANUAL_SHOOTER_ANGLE_ADJUST
#define MANUAL_SHOOTER_ANGLE_ADJUST
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ManualShooterAngleAdjust : public Command{
public:
	ManualShooterAngleAdjust();
	ManualShooterAngleAdjust(bool coarse, bool positive);
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool coarse, positive;
};
#endif
