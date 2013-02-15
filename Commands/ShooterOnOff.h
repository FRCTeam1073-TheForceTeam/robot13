#ifndef SHOOTER_ON_OFF_H
#define SHOOTER_ON_OFF_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class ShooterOnOff : public Command{
public:
	ShooterOnOff(OnOff onOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	OnOff onOff;
};
#endif
