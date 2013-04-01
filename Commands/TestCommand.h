#ifndef TEST_COMMAND_H
#define TEST_COMMAND_H
#include "../Robot.h"
#include "Commands/Subsystem.h"
class TestCommand : public Command{
public:
	TestCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
