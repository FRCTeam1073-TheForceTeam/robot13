#ifndef SPIN_FEEDER_H
#define SPIN_FEEDER_H
#include "../Robot.h"
#include "Commands/Subsystem.h"
class SpinFeeder : public Command{
public:
	SpinFeeder();
	SpinFeeder(bool forward);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool forward;
};
#endif
