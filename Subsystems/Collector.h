#ifndef COLLECTOR_H
#define COLLECTOR_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Collector: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Collector();
	void InitDefaultCommand();
};
#endif
