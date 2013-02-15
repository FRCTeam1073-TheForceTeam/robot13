#ifndef TURBODRIVEON_H
#define TURBODRIVEON_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class TurboDriveOn: public Command {
public:
	TurboDriveOn(SmartJoystick* stick);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	SmartJoystick* stick;
	SmartJoystick::JoystickMode old;
};
#endif
