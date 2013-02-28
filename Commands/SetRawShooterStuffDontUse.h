#ifndef SET_RAW_SHOOTER_STUFF_DONT_USE
#define SET_RAW_SHOOTER_STUFF_DONT_USE
#include "Commands/Subsystem.h"
#include "../Robot.h"
class SetRawShooterStuffDontUse : public Command{
public:
	SetRawShooterStuffDontUse(float speed, float angle);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float speed, angle;
};
#endif
