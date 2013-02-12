#ifndef ChainsawUp_H
#define ChainsawUp_H


#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../WPILibExtensions/StallableAnalogEncoder.h"
/**
 *
 *
 * @author ExampleAuthor
 */
class ChainsawUp: public Command {
private:
	int manualPositionCounter;
public:
	ChainsawUp();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
