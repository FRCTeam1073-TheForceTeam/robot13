#ifndef AUTONOMOUSTURNTOANGLE_H
#define AUTONOMOUSTURNTOANGLE_H
#include "Commands/Subsystem.h"
#include "../Robot.h"
class AutonomousTurnToAngle: public Command {
public:
	AutonomousTurnToAngle(float targetAngle);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
private:
	bool leftIsBest;
	float leftSpeed, rightSpeed;
	float currentAngle, targetAngle;
	float CalculateCoterminalAngle(float targetAngle);
	void UpdateCurrentAngle();
};

#endif
