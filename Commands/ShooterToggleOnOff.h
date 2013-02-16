#ifndef SHOOTER_TOGGLE_ON_OFF_H
#define SHOOTER_TOGGLE_ON_OFF_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class ShooterToggleOnOff : public Command{
public:
	ShooterToggleOnOff();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	OnOff previousOnOff;
};
#endif
