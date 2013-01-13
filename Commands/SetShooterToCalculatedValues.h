/* Because Robot Builder supports a minimalistic software design approach I must take my bloated Commands that
 * require more than a single Subsysetem to the editor. Therefore you will never ever see this Command appear in
 * Robot Builder - do not allow that to be of any alarm to you */
#ifndef SET_SHOOTER_TO_CALCULATED_VALUES_H
#define SET_SHOOTER_TO_CALCULATED_VALUES_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class SetShooterToCalculatedValues : public Command{
	SetShooterToCalculatedValues();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
