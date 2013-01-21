#ifndef AUTONOMOUS_TURNS_H
#define AUTONOMOUS_TURNS_H


#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class AutonomousTurns: public Command {
public:
	AutonomousTurns(bool isRight);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool turnRight;
	float startingAngle, currentAngle;
};

#endif
