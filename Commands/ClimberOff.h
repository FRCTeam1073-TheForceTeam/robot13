#ifndef CLIMBEROFF_H
#define CLIMBEROFF_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ClimberOff: public Command {
public:
	ClimberOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
