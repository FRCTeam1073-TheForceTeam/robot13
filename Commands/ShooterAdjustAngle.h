#ifndef SHOOTERADJUSTANGLE_H
#define SHOOTERADJUSTANGLE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ShooterAdjustAngle: public Command {
public:
	ShooterAdjustAngle(bool positive);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	bool IsAtTopLimit();
	bool IsAtBottomLimit();
private:
	bool positive;
};
#endif
