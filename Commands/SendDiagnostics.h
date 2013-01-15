#ifndef SENDDIAGNOSTICS_H
#define SENDDIAGNOSTICS_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class SendDiagnostics: public Command {
public:
	SendDiagnostics();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
