#include "OI.h"
#include "HardwarePortDefinitions.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousSequence.h"
#include "Commands/AutonomousTurnToAngle.h"
#include "Commands/ClimberDrive.h"
#include "Commands/ClimberOff.h"
#include "Commands/ClimberOn.h"
#include "Commands/EngageClimber.h"
#include "Commands/JoystickDrive.h"
#include "Commands/PullShooterData.h"
#include "Commands/ChainsawUp.h"
#include "Commands/ChainsawMiddle.h"
#include "Commands/ChainsawDown.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterOff.h"
#include "Commands/ShooterOn.h"
#include "Commands/TurboDriveOn.h"
#include "Commands/WriteDriveData.h"
OI::OI() {
	operatorStick = new SmartJoystick(JOY_OPERATOR);
	
	engageAutoAim = new JoystickButton(operatorStick, 2);
	engageAutoAim->WhileHeld(new SetShooterToCalculatedValues());
	chainsawDown = new JoystickButton(operatorStick, 7);
	chainsawDown->WhenPressed(new ChainsawDown());
	chainsawMiddle = new JoystickButton(operatorStick, 6);
	chainsawMiddle->WhenPressed(new ChainsawMiddle());
	chainsawUp = new JoystickButton(operatorStick, 5);
	chainsawUp->WhenPressed(new ChainsawUp());
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
	rightStick = new SmartJoystick(JOY_RIGHT);
	
	rightTurboOn = new JoystickButton(rightStick, 1);
	rightTurboOn->WhileHeld(new TurboDriveOn());
	leftStick = new SmartJoystick(JOY_LEFT);
	
	pullShooterDashData = new JoystickButton(leftStick, 6);
	pullShooterDashData->WhenPressed(new PullShooterData());
	switchDrive = new JoystickButton(leftStick, 10);
	switchDrive->WhenPressed(new SetCubicDrive());
	leftTurboOn = new JoystickButton(leftStick, 1);
	leftTurboOn->WhileHeld(new TurboDriveOn());
     
	SmartDashboard::PutData("ShooterOn", new ShooterOn());
	SmartDashboard::PutData("ShooterOff", new ShooterOff());
	SmartDashboard::PutData("ClimberOn", new ClimberOn());
	SmartDashboard::PutData("ClimberOff", new ClimberOff());
	SmartDashboard::PutData("TurboDriveOn", new TurboDriveOn());
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
	SmartDashboard::PutData("SetChainsawPosition1", new ChainsawUp());
	SmartDashboard::PutData("SetChainsawPosition2", new ChainsawMiddle());
	SmartDashboard::PutData("SetChainsawPosition3", new ChainsawDown());
	SmartDashboard::PutData("ClimberDrive", new ClimberDrive());
	SmartDashboard::PutData("PullShooterData", new PullShooterData());
	SmartDashboard::PutData("EngageClimber", new EngageClimber());
	writeDriveDataButton = new JoystickButton(leftStick, 11);
	writeDriveDataButton->WhileHeld(new WriteDriveData());
	rightStick->ToggleInvertYAxis();
}
SmartJoystick* OI::getOperatorStick(){return operatorStick;}
SmartJoystick* OI::getRightStick(){return rightStick;}
SmartJoystick* OI::getLeftStick(){return leftStick;}
