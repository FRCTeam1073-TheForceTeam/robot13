#ifndef AUTONOMOUSFORWARD_H
#define AUTONOMOUSFORWARD_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class AutonomousForward: public Command {
public:
	AutonomousForward(float distance);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float startingLeft;
	float startingRight;
	float targetAngle;
	float startingAngle;
	float distanceToDrive;
};
#endif
