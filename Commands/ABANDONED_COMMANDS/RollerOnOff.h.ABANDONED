#ifndef ROLLER_ON_OFF_H
#define ROLLER_ON_OFF_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/WPILibExtensions.h"
class RollerOnOff : public Command{
public:
	RollerOnOff(OnOff onOff);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	OnOff onOff;
};
#endif
