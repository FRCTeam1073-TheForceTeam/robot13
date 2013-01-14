/* Another command that sits out of Robot Builder's stone cold, orphan slaying grasp.
 * I decided to apply some simple OO and use a Command with a constructor but Robot Builder does not support that.
 */
#ifndef MANUAL_SHOOTER_SPEED_ADJUST_H
#define MANUAL_SHOOTER_SPEED_ADJUST_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class ManualShooterSpeedAdust : public Command{
public:
	ManualShooterSpeedAdust(bool positive, bool coarse);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool positive, coarse;
};
#endif
