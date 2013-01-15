//hack command to kill running commands easily with the JoystickButton
#ifndef KILL_COMMAND_COMMAND_H
#define KILL_COMMAND_COMMAND_H
#include "../Robot.h"
#include "Commands/Subsystem.h"
class KillCommandCommand : public Command{
public:
	KillCommandCommand(Command* command);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif