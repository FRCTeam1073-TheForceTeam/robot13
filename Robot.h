
#ifndef _ROBOT_H
#define _ROBOT_H
#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "SmartDashboardKeys.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousRightBack.h"
#include "Subsystems/AllignmentData.h"
#include "Subsystems/Climber.h"
#include "Subsystems/Collector.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/Light.h"
#include "Subsystems/Shooter.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Subsystems/DiscVelocity.h"
#include "OI.h"
class Robot : public IterativeRobot {
public:
	Command *autonomousCommand;
	static OI *oi;
	LiveWindow *lw;
	SendableChooser *chooser;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static Light* light;
	static Climber* climber;
	static DriveTrain* driveTrain;
	static Collector* collector;
	static Shooter* shooter;
	static AllignmentData* allignmentData;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static DiscVelocity* discVelocity;
	Robot();
	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
