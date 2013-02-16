#ifndef CLIMBERSAFE_H
#define CLIMbERSAFE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ClimberSafe: public Command {
public:
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:

};
#endif
