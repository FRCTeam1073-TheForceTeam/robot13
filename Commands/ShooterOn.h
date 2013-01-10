#ifndef SHOOTERON_H
#define SHOOTERON_H
#include "Commands/Subsystem.h"
#include "../Robot.h"

class ShooterOn: public Command {
public:
	ShooterOn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
