#ifndef MANUAL_CLIMBER_ARM_CONTROL_H
#define MANUAL_CLIMBER_ARM_CONTROL_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ManualClimberArmControl : public Command{
public:
	ManualClimberArmControl(bool goUp);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool goUp;
};
#endif
