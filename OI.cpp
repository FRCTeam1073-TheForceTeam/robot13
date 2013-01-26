#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousLeftBack.h"
#include "Commands/AutonomousMiddleBack.h"
#include "Commands/AutonomousRightBack.h"
#include "Commands/AutonomousTurnLeft.h"
#include "Commands/AutonomousTurnRight.h"
#include "Commands/AutonomousTurns.h"
#include "Commands/ClimberLower.h"
#include "Commands/ClimberOff.h"
#include "Commands/ClimberOn.h"
#include "Commands/ClimberRaise.h"
#include "Commands/CollectDiscs.h"
#include "Commands/DiscsReverse.h"
#include "Commands/JoystickDrive.h"
#include "Commands/LightOn.h"
#include "Commands/ManualShooterAngleAdjust.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterOff.h"
#include "Commands/ShooterOn.h"
#include "Commands/TestSmartDashboard.h"
#include "Commands/TurboDrive.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new Joystick(1);
	
	climberDisengage = new JoystickButton(operatorStick, 12);
	climberDisengage->WhileHeld(new ClimberOff());
	climberEngage = new JoystickButton(operatorStick, 11);
	climberEngage->WhileHeld(new ClimberOn());
	climberDown = new JoystickButton(operatorStick, 9);
	climberDown->WhileHeld(new ClimberLower());
	climberUp = new JoystickButton(operatorStick, 10);
	climberUp->WhileHeld(new ClimberRaise());
	testSmartDashboard = new JoystickButton(operatorStick, 8);
	testSmartDashboard->WhenPressed(new TestSmartDashboard());
	shooterOffButton = new JoystickButton(operatorStick, 6);
	shooterOffButton->WhenPressed(new ShooterOff());
	shooterOnButton = new JoystickButton(operatorStick, 5);
	shooterOnButton->WhenPressed(new ShooterOn());
	shootButton = new JoystickButton(operatorStick, 1);
	shootButton->WhenPressed(new Shoot());
	rightStick = new Joystick(3);
	
	rightTurbo = new JoystickButton(rightStick, 1);
	rightTurbo->WhileHeld(new TurboDrive());
	leftStick = new Joystick(2);
	
	switchDrive = new JoystickButton(leftStick, 10);
	switchDrive->WhenPressed(new SetCubicDrive());
	leftTurbo = new JoystickButton(leftStick, 1);
	leftTurbo->WhileHeld(new TurboDrive());
     
        // SmartDashboard Buttons
	SmartDashboard::PutData("AutonomousRightBack", new AutonomousRightBack());
	SmartDashboard::PutData("AutonomousLeftBack", new AutonomousLeftBack());
	SmartDashboard::PutData("AutonomousMiddleBack", new AutonomousMiddleBack());
	SmartDashboard::PutData("Autonomous Turns", new AutonomousTurns());
	SmartDashboard::PutData("LightOn", new LightOn());
	SmartDashboard::PutData("ClimberOn", new ClimberOn());
	SmartDashboard::PutData("ClimberOff", new ClimberOff());
	SmartDashboard::PutData("ClimberRaise", new ClimberRaise());
	SmartDashboard::PutData("ClimberLower", new ClimberLower());
	SmartDashboard::PutData("TurboDrive", new TurboDrive());
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	//writeDriveDataButton = new JoystickButton(leftStick, 1);
	//WriteDriveData* command = new WriteDriveData();
	//writeDriveDataButton->WhenPressed(command);
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
