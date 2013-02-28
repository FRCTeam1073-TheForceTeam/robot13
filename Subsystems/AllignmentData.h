#ifndef ALLIGNMENTDATA_H
#define ALLIGNMENTDATA_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class AllignmentData: public Subsystem {
private:
	NetworkTable* trackingDataTable;
public:
	AllignmentData();
	void InitDefaultCommand();
	double GetCalculatedVelocityRPM();
	double GetCalculatedAngle();
	void SendCurrentAngle(float angle);
	void SendCurrentSpeed(int speed);
};
#endif
