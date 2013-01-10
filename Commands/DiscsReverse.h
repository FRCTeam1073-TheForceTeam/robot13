#ifndef DISCSREVERSE_H
#define DISCSREVERSE_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class DiscsReverse: public Command {
public:
	DiscsReverse();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
