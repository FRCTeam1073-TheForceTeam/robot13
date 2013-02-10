//is this needed?
#ifndef DIAGNOSTICS_H
#define DIAGNOSTICS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Diagnostics: public Subsystem {
private:
public:
	Diagnostics();
	void InitDefaultCommand();
};
#endif
