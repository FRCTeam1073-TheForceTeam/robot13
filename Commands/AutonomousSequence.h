#ifndef AUTONOMOUSSEQUENCE_H
#define AUTONOMOUSSEQUENCE_H
#include "Commands/CommandGroup.h"
class AutonomousSequence: public CommandGroup {
public:	
	enum StartPosition{leftBack, middleBack, rightBack};
	AutonomousSequence();	//defaults to left
	AutonomousSequence(StartPosition startPosition);
	virtual void Initialize();
	virtual void End();
	virtual void Interrupted();
private:
	void DoSequence();
	double GetAutonomousWaitTime();
	StartPosition startPosition;
};

#endif
