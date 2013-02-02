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
#include "Commands/ClimberDrive.h"
#include "Commands/ClimberOff.h"
#include "Commands/ClimberOn.h"
#include "Commands/DiscsReverse.h"
#include "Commands/JoystickDrive.h"
#include "Commands/LightOn.h"
#include "Commands/PullShooterData.h"
#include "Commands/SetChainsawPosition1.h"
#include "Commands/SetChainsawPosition2.h"
#include "Commands/SetChainsawPosition3.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterOff.h"
#include "Commands/ShooterOn.h"
#include "Commands/TurboDrive.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "Commands/WriteDriveData.h"
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	operatorStick = new Joystick(1);
	
	engageAutoAim = new JoystickButton(operatorStick, 2);
	engageAutoAim->WhileHeld(new SetShooterToCalculatedValues());
	chainsawPos3 = new JoystickButton(operatorStick, 7);
	chainsawPos3->WhenPressed(new SetChainsawPosition3());
	chainsawPos2 = new JoystickButton(operatorStick, 6);
	chainsawPos2->WhenPressed(new SetChainsawPosition2());
	chainsawPos1 = new JoystickButton(operatorStick, 5);
	chainsawPos1->WhenPressed(new SetChainsawPosition1());
	climberDisengage = new JoystickButton(operatorStick, 12);
	climberDisengage->WhenPressed(new ClimberOff());
	climberEngage = new JoystickButton(operatorStick, 11);
	climberEngage->WhenPressed(new ClimberOn());
	shooterOffButton = new JoystickButton(operatorStick, 10);
	shooterOffButton->WhenPressed(new ShooterOff());
	shooterOnButton = new JoystickButton(operatorStick, 9);
	shooterOnButton->WhenPressed(new ShooterOn());
	shootButton = new JoystickButton(operatorStick, 1);
	shootButton->WhenPressed(new Shoot());
	rightStick = new Joystick(3);
	
	rightTurbo = new JoystickButton(rightStick, 1);
	rightTurbo->WhileHeld(new TurboDrive());
	leftStick = new Joystick(2);
	
	pullShooterDashData = new JoystickButton(leftStick, 6);
	pullShooterDashData->WhenPressed(new PullShooterData());
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
	SmartDashboard::PutData("ShooterOn", new ShooterOn());
	SmartDashboard::PutData("ShooterOff", new ShooterOff());
	SmartDashboard::PutData("ClimberOn", new ClimberOn());
	SmartDashboard::PutData("ClimberOff", new ClimberOff());
	SmartDashboard::PutData("TurboDrive", new TurboDrive());
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
	SmartDashboard::PutData("SetChainsawPosition1", new SetChainsawPosition1());
	SmartDashboard::PutData("SetChainsawPosition2", new SetChainsawPosition2());
	SmartDashboard::PutData("PullShooterData", new PullShooterData());
	SmartDashboard::PutData("SetChainsawPosition3", new SetChainsawPosition3());
	SmartDashboard::PutData("ClimberDrive", new ClimberDrive());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	writeDriveDataButton = new JoystickButton(leftStick, 11);
	writeDriveDataButton->WhileHeld(new WriteDriveData());
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
