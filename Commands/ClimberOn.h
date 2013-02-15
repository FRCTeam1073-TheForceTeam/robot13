
#ifndef CLIMBERON_H
#define CLIMBERON_H


#include "Commands/Subsystem.h"
#include "../Robot.h"


/**
 *
 *
 * @author ExampleAuthor
 */
class ClimberOn: public Command {
public:
	ClimberOn();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
