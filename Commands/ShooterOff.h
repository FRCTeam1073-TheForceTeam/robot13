#ifndef SHOOTEROFF_H
#define SHOOTEROFF_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterOff: public Command {
public:
	ShooterOff();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
