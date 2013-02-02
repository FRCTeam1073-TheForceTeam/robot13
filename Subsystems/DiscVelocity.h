#ifndef DISC_VELOCITY_H
#define DISC_VELOCITY_H
#include "../RobotMap.h"
#include "Commands/Subsystem.h"
#include "../FieldElements.h"

#define SHOTS_PER_TEST 3

class DiscVelocity : public Subsystem{
private:
	int index;
	float speeds[SHOTS_PER_TEST];
	DigitalInput* input;
	enum State {NotWaiting, WaitingForDetect, WaitingForExit};
	State state;
	float startTime, stopTime;
	float ellapsedTime;
	float velocity;
	bool newData;
	void Reset();
public:
	DiscVelocity(DigitalInput* input);
	void InitDefaultCommand();
	float GetStartTime();
	float GetStopTime();
	float GetEllapsedTime();
	float GetVelocityFPS();
	void ProcessInterrupt();
	bool IsThereNewData();
};

#endif
