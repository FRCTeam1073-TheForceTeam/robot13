#ifndef COLLECTDISCS_H
#define COLLECTDISCS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

class CollectDiscs: public Command {
public:
	CollectDiscs();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif