#ifndef OI_H
#define OI_H
#include "WPILib.h"
#include "WPILibExtensions/WPILibExtensions.h"
class OI {
private:
	SmartJoystick* operatorStick;
	JoystickButton* engageAutoAim;
	JoystickButton* chainsawDown;
	JoystickButton* chainsawMiddle;
	JoystickButton* chainsawUp;
	JoystickButton* climberDisengage;
	JoystickButton* climberEngage;
	JoystickButton* shooterOffButton;
	JoystickButton* shooterOnButton;
	JoystickButton* shootButton;
	SmartJoystick* rightStick;
	JoystickButton* rightTurboOn;
	SmartJoystick* leftStick;
	JoystickButton* pullShooterDashData;
	JoystickButton* switchDrive;
	JoystickButton* leftTurboOn;
    JoystickButton* writeDriveDataButton;
public:
	OI();
	SmartJoystick* getLeftStick();
	SmartJoystick* getRightStick();
	SmartJoystick* getOperatorStick();
};
#endif
