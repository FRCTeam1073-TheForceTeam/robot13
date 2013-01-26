#ifndef CLIMBER_H
#define CLIMBER_H
#define CLIMBER_ON 0.5
#define CLIMBER_OFF 0.0
#define CHAINSAW_DOWN_SPEED -0.5
#define CHAINSAW_UP_SPEED 0.5
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Climber: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Servo* climberServo;
	SpeedController* climberVictor;
	CANJaguar* chainsawPositionJag;
	CANJaguar* chainsawSpeedJag;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	Encoder* climberChainsawElevationMEncoder;
	Climber();
	void InitDefaultCommand();
	void EngageClimber();
	void DisengageClimber();
	void ChainsawPosition1();
	void ChainsawPosition2();
	void ChainsawPosition3();
	void ChainsawMovementOff();
	double GetDistance();
};
#endif
