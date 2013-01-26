#ifndef CLIMBER_H
#define CLIMBER_H
#define CHAINSAW_DOWN_SPEED -0.5
#define CHAINSAW_UP_SPEED 0.5
#include "Commands/Subsystem.h"
#include "WPILib.h"
class Climber: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool ClimberOnOff;
	float leftClimber;
	float rightClimber;
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	SpeedController* climberTalon;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	CANJaguar* leftClimberJag;
	CANJaguar* rightClimberJag;
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
