#ifndef CLIMBERDRIVE_H
#define CLIMBERDRIVE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ClimberDrive: public Command {
public:
	ClimberDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
