#ifndef AUTONOMOUSTURNRIGHT_H
#define AUTONOMOUSTURNRIGHT_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousTurnRight: public Command {
public:
	AutonomousTurnRight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	float startingAngle;
};

#endif
