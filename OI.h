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
    JoystickButton* goToFeederAngle;
    
    JoystickButton *killFeeder;
    
public:
	OI();
	SmartJoystick* getLeftStick();
	SmartJoystick* getRightStick();
	SmartJoystick* getOperatorStick();
};
#endif
