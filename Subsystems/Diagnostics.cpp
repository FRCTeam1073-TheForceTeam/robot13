//Does this have to be a subsystem.
//All it does is run a command, you can send commands into the Scheduler in Robot::TeleopPeriodic() Without a Subsystem...
#include "Diagnostics.h"
#include "../Robotmap.h"
#include "../Commands/SendDiagnostics.h"

Diagnostics::Diagnostics() : Subsystem("Diagnostics") {
	printf("Diagnostics::Diagnostics CALLED !!!!!!!!!!!!!!!!!!!\n");
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}
    
void Diagnostics::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
	printf("Diagnostic::InitDefaultCommand CALLED ~~~~~~~~~~~~~\n");
//	SetDefaultCommand(new SendDiagnostics());
}
