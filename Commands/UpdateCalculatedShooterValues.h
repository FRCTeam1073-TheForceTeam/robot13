/* Because Robot Builder supports a minimalistic software design approach I must take my bloated Commands that
 * require more than a single Subsysetem to the editor. Therefore you will never ever see this Command appear in
 * Robot Builder - do not allow that to be of any alarm to you */
#ifndef UPDATE_SHOOTER_CALCULATED_VALUES_H
#define UPDATE_SHOOTER_CALCULATED_VALUES_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class UpdateCalculatedShooterValues : public Command{
public:
	UpdateCalculatedShooterValues();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif
