#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/CollectDiscs.h"
#include "Commands/DiscsReverse.h"
#include "Commands/JoystickDrive.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterOff.h"
#include "Commands/ShooterOn.h"
#include "SmartDashboard/SmartDashboard.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/AutonomousCommand.h"
#include "Commands/TestSmartDashboard.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new Joystick(3);
	
	shooterOffButton = new JoystickButton(operatorStick, 6);
	shooterOffButton->WhenPressed(new ShooterOff());
	shooterOnButton = new JoystickButton(operatorStick, 5);
	shooterOnButton->WhenPressed(new ShooterOn());
	shootButton = new JoystickButton(operatorStick, 1);
	shootButton->WhenPressed(new Shoot());
	rightStick = new Joystick(2);
	
	leftStick = new Joystick(1);
	
     
        // SmartDashboard Buttons
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getOperatorStick() {
	return operatorStick;
}
Joystick* OI::getRightStick() {
	return rightStick;
}
Joystick* OI::getLeftStick() {
	return leftStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
