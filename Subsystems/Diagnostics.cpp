//Does this have to be a subsystem.
//All it does is run a command, you can send commands into the Scheduler in Robot::TeleopPeriodic() Without a Subsystem...
#include "Diagnostics.h"
#include "../Robotmap.h"
#include "../Commands/SendDiagnostics.h"

Diagnostics::Diagnostics() : Subsystem("Diagnostics") {puts("Diagnostic Subsystems Constructed");}
void Diagnostics::InitDefaultCommand() {
	puts("Diagnostic Init Default Command Method");
//	SetDefaultCommand(new SendDiagnostics());
}
