#ifndef SETTOFEEDERANGLE_H
#define SETTOFEEDERANGLE_H
#include "Commands/CommandGroup.h"
class SetToFeederAngle: public CommandGroup {
public:
	SetToFeederAngle();
	virtual void Initialize();
};

#endif
