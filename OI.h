#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
class OI {
private:
	void ConstructJoysticks();
	void ConstructJoystickButtons();
	void ConstructSmartDashCommands();
	SmartJoystick* operatorStick;
	SmartJoystick* leftStick;
	SmartJoystick* rightStick;
	JoystickButton* engageAutoAim;
	JoystickButton* chainsawDown;
	JoystickButton* chainsawMiddle;
	JoystickButton* chainsawUp;
	JoystickButton* climberDisengage;
	JoystickButton* climberEngage;
	JoystickButton* shooterOnOffButton;
	JoystickButton* shootButton;
	JoystickButton* rightTurboOn;
	JoystickButton* pullShooterDashData;
	JoystickButton* switchDrive;
	JoystickButton* leftTurboOn;
    JoystickButton* writeDriveDataButton;
    JoystickButton* shooterSpeedUp;
    JoystickButton* shooterSpeedDown;
    JoystickButton* shooterElevationUp;
    JoystickButton* shooterElevationDown;
    JoystickButton* rollerOn;
    JoystickButton* rollerOff;
public:
	OI();
	SmartJoystick* getLeftStick();
	SmartJoystick* getRightStick();
	SmartJoystick* getOperatorStick();
};
#endif
