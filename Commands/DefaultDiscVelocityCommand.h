#ifndef DEFAULT_DISC_VELOCITY_COMMAND_H
#define DEFAULT_DISC_VELOCITY_COMMAND_H
#include "Commands/Subsystem.h"
#include "../Robot.h"

class DefaultDiscVelocityCommand : public Command{
public:
	DefaultDiscVelocityCommand() {}
	void Initialize(){}
	void Execute(){
/*		if(Robot::discVelocity->IsThereNewData()){
			printf("Disc Shot @ %ffps!\n", Robot::discVelocity->GetVelocityFPS());
		}	
*/	}
	bool IsFinished() {return false;}
	void End(){}
	void Interrupted(){}
};
#endif
