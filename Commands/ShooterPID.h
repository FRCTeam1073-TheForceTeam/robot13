#ifndef SHOOTER_PID_H
#define SHOOTER_PID_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ShooterPID : public Command{
public:
	ShooterPID();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
