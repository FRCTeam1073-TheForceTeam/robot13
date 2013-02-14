#ifndef SENDCOLLECTORDATA_H
#define SENDCOLLECTORDATA_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../SmartDashboardKeys.h"
class SendCollectorData: public Command {
public:
	SendCollectorData();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End(){}
	void Interrupted() {}
};

#endif
