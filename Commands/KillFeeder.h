#ifndef KILL_FEEDER_H
#define KILL_FEEDER_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class KillFeeder : public Command{
public:
	KillFeeder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
