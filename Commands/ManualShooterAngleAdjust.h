#ifndef MANUAL_SHOOTER_ANGLE_ADJUST
#define MANUAL_SHOOTER_ANGLE_ADJUST
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ManualShooterAngleAjust : public Command{
public:
	ManualShooterAngleAjust(bool coarse, bool positive);
	void Initialize();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool coarse, positive;
};
#endif
