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
	SmartJoystick* xbox;
	JoystickButton* shooterOnOffButton;
	JoystickButton* feedButton;
	JoystickButton* feedButtonReverse;
	JoystickButton* rightTurboOn;
	JoystickButton* pullShooterDashData;
	JoystickButton* switchDrive;
	JoystickButton* leftTurboOn;
    JoystickButton* writeDriveDataButton;
    JoystickButton* shooterSpeedUp;
    JoystickButton* shooterSpeedDown;
    JoystickButton* shooterElevationUp;
    JoystickButton* shooterElevationDown;
    JoystickButton* goToGoodShotAngle;
public:
	OI();
	SmartJoystick* getLeftStick();
	SmartJoystick* getRightStick();
	SmartJoystick* getOperatorStick();
	SmartJoystick* getXbox();
};
#endif
