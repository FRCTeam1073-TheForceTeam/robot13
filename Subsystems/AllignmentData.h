#ifndef ALLIGNMENTDATA_H
#define ALLIGNMENTDATA_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
class AllignmentData: public Subsystem {
private:
	static int DEFAULT;
	double calculatedDistance;
	double calculatedAngle;
	NetworkTable* trackingDataTable;
public:
	AllignmentData();
	void InitDefaultCommand();
	double GetCalculatedVelocityFPS();
	double GetCalculatedAngle();
	void SendCurrentAngle(float angle);
	void SendCurrentSpeed(int speed);
	bool IsTarget();
};
#endif
