#ifndef AUTONOMOUSFORWARD_H
#define AUTONOMOUSFORWARD_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousForward: public Command {
public:
	AutonomousForward();
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
	
};

#endif
