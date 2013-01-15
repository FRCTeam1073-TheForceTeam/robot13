#ifndef PULLNEWALLIGNMENTDATA_H
#define PULLNEWALLIGNMENTDATA_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class PullNewAllignmentData: public Command {
public:
	PullNewAllignmentData();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
#endif
