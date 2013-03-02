#ifndef SHOOT_H
#define SHOOT_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class Shoot: public Command {
private:
	bool abort;
	enum DiscState{enteringShooter, inShooter, leftCollector};
	DiscState discState;
public:
	Shoot();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void Interrupted();
	virtual void End();
};
#endif
