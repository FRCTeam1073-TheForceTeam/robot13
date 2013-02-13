#ifndef CHAINSAW_POSITION_H
#define CHAINSAW_POSITION_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/StallableAnalogEncoder.h"
class ChainsawPosition : public Command{
public:
	typedef enum {up, middle, down} Destination;
	ChainsawPosition(Destination destination);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void Interrupted();
	virtual void End();
private:
	bool lessThan;
	bool left, right;
	Destination destination;
	void Reset();
};
#endif
