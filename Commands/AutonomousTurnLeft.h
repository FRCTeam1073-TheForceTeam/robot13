#ifndef AUTONOMOUSTURNLEFT_H
#define AUTONOMOUSTURNLEFT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousTurnLeft: public Command {
public:
	AutonomousTurnLeft();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};


#endif
