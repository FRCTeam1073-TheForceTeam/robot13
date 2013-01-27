#ifndef PULLSHOOTERDATA_H
#define PULLSHOOTERDATA_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../SmartDashboardKeys.h"
class PullShooterData: public Command {
public:
	PullShooterData();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End(){}
	void Interrupted() {}
};

#endif
