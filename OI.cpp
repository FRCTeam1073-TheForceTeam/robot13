#include "OI.h"
#include "HardwarePortDefinitions.h"
#include "JoystickButtonSheet.h"
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
#include "Commands/ChainsawPosition.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterOff.h"
#include "Commands/ShooterOn.h"
#include "Commands/TurboDriveOn.h"
#include "Commands/WriteDriveData.h"
OI::OI() {
	operatorStick = new SmartJoystick(JOY_OPERATOR);
	
	engageAutoAim = new JoystickButton(operatorStick, OPERATOR_SHOOTER_AUTOAIM_BTN);
	engageAutoAim->WhileHeld(new SetShooterToCalculatedValues());
	chainsawDown = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_DOWN_BTN);
	chainsawDown->WhenPressed(new ChainsawPosition(ChainsawPosition::down));
	chainsawMiddle = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_MIDDLE_BTN);
	chainsawMiddle->WhenPressed(new ChainsawPosition(ChainsawPosition::middle));
	chainsawUp = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_UP_BTN);
	chainsawUp->WhenPressed(new ChainsawPosition(ChainsawPosition::up));
	climberDisengage = new JoystickButton(operatorStick, OPERATOR_CLIMBER_DISENGAGE_BTN);
	climberDisengage->WhenPressed(new ClimberOff());
	climberEngage = new JoystickButton(operatorStick, OPERATOR_CLIMBER_ENGAGE_BTN);
	climberEngage->WhenPressed(new ClimberOn());
	shooterOffButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_OFF_BTN);
	shooterOffButton->WhenPressed(new ShooterOff());
	shooterOnButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_ON_BTN);
	shooterOnButton->WhenPressed(new ShooterOn());
	shootButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_SHOOT_BTN);
	shootButton->WhenPressed(new Shoot());
	rightStick = new SmartJoystick(JOY_RIGHT);
	
	rightTurboOn = new JoystickButton(rightStick, RIGHT_DRIVE_TRAIN_TURBO_ON_BTN);
	rightTurboOn->WhileHeld(new TurboDriveOn());
	leftStick = new SmartJoystick(JOY_LEFT);
	
	pullShooterDashData = new JoystickButton(leftStick, LEFT_DASHBOARD_PULL_SHOOTER_DATA_BTN);
	pullShooterDashData->WhenPressed(new PullShooterData());
	switchDrive = new JoystickButton(leftStick, LEFT_DRIVE_TRAIN_CHANGE_DRIVE_BTN);
	switchDrive->WhenPressed(new SetCubicDrive());
	leftTurboOn = new JoystickButton(leftStick, LEFT_DRIVE_TRAIN_TURBO_ON_BTN);
	leftTurboOn->WhileHeld(new TurboDriveOn());
     
	SmartDashboard::PutData("ShooterOn", new ShooterOn());
	SmartDashboard::PutData("ShooterOff", new ShooterOff());
	SmartDashboard::PutData("ClimberOn", new ClimberOn());
	SmartDashboard::PutData("ClimberOff", new ClimberOff());
	SmartDashboard::PutData("TurboDriveOn", new TurboDriveOn());
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
	SmartDashboard::PutData("SetChainsawPositionUp", new ChainsawPosition(ChainsawPosition::up));
	SmartDashboard::PutData("SetChainsawPositionMiddle", new ChainsawPosition(ChainsawPosition::middle));
	SmartDashboard::PutData("SetChainsawPositionDown", new ChainsawPosition(ChainsawPosition::down));
	SmartDashboard::PutData("ClimberDrive", new ClimberDrive());
	SmartDashboard::PutData("PullShooterData", new PullShooterData());
	SmartDashboard::PutData("EngageClimber", new EngageClimber());
	writeDriveDataButton = new JoystickButton(leftStick, LEFT_DASHBOARD_WRITE_DRIVE_DATA_BTN);
	writeDriveDataButton->WhileHeld(new WriteDriveData());
	rightStick->ToggleInvertYAxis();
}
SmartJoystick* OI::getOperatorStick(){return operatorStick;}
SmartJoystick* OI::getRightStick(){return rightStick;}
SmartJoystick* OI::getLeftStick(){return leftStick;}
