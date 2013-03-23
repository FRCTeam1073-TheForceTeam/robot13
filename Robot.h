#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "SmartDashboardKeys.h"
#include "Commands/AutonomousSequence.h"
#include "Subsystems/AllignmentData.h"
#include "Subsystems/Collector.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Diagnostics.h"
#include "Subsystems/DiscVelocity.h"
#include "OI.h"
#include "HardwarePortDefinitions.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	SendableChooser *chooser;
	static DriveTrain* driveTrain;
	static Collector* collector;
	static Shooter* shooter;
	static AllignmentData* allignmentData;
	static DiscVelocity* discVelocity;
	static Diagnostics* diagnostics;
	Robot();
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
	virtual void DisabledInit();
	static enum WhichRobot_t {newRobot, mobileBase, elot, libra} whichRobot;
	static WhichRobot_t GetWhichRobot();

private:
	static DigitalInput *jumper14;
	static DigitalInput *jumper13;
	static DigitalInput *jumper12;
};
#endif
