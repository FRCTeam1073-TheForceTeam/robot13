#ifndef CLIMBER_ON_OFF_H
#define CLIMBER_ON_OFF_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class ClimberOnOff : public Command{
public:
	ClimberOnOff(OnOff onOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	OnOff onOff;
};
#endif
