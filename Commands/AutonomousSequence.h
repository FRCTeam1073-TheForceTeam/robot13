#ifndef AUTONOMOUSSEQUENCE_H
#define AUTONOMOUSSEQUENCE_H
#include "Commands/CommandGroup.h"
class AutonomousSequence: public CommandGroup {
public:	
	enum StartPosition{leftBack, middleBack, rightBack};
	AutonomousSequence();	//defaults to left
	AutonomousSequence(StartPosition startPosition);
private:
	double GetAutonomousWaitTime();
	StartPosition startPosition;
	void DoSequence();
};

#endif