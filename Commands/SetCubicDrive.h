#ifndef SETCUBICDRIVE_H
#define SETCUBICDRIVE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class SetCubicDrive: public Command {
public:
	SetCubicDrive();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	void ChangeMode(SmartJoystick* smartJoystick);
};

#endif
