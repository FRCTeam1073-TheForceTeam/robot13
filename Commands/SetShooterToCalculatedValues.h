#ifndef SETSHOOTERTOCALCULATEDVALUES_H
#define SETSHOOTERTOCALCULATEDVALUES_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class SetShooterToCalculatedValues: public Command {
public:
	SetShooterToCalculatedValues();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
