#ifndef ELEVATE_TO_GOOD_POSITION_H
#define ELEVATE_TO_GOOD_POSITION_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ElevateToGoodPosition : public CommandGroup{
public:
	ElevateToGoodPosition();
	void Initialize();
};
#endif
