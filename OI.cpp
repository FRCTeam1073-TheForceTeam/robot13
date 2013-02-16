#include "OI.h"
#include "HardwarePortDefinitions.h"
#include "JoystickButtonSheet.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousSequence.h"
#include "Commands/AutonomousTurnToAngle.h"
#include "Commands/ClimberDrive.h"
#include "Commands/ClimberOnOff.h"
#include "Commands/JoystickDrive.h"
#include "Commands/PullShooterData.h"
#include "Commands/ChainsawPosition.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/Shoot.h"
#include "Commands/ShooterToggleOnOff.h"
#include "Commands/TurboDriveOn.h"
#include "Commands/WriteDriveData.h"
OI::OI() {
	//organized such that null pointers do not occur
	ConstructJoysticks();
	ConstructJoystickButtons();
	ConstructSmartDashCommands();
}
void OI::ConstructJoysticks(){
	operatorStick = new SmartJoystick(JOY_OPERATOR);
	leftStick = new SmartJoystick(JOY_LEFT);
	rightStick = new SmartJoystick(JOY_RIGHT);
	rightStick->ToggleInvertYAxis();	
}
void OI::ConstructJoystickButtons(){
	engageAutoAim = new JoystickButton(operatorStick, OPERATOR_SHOOTER_AUTOAIM_BTN);
	engageAutoAim->WhileHeld(new SetShooterToCalculatedValues());
	chainsawDown = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_DOWN_BTN);
	chainsawDown->WhenPressed(new ChainsawPosition(ChainsawPosition::down));
	chainsawMiddle = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_MIDDLE_BTN);
	chainsawMiddle->WhenPressed(new ChainsawPosition(ChainsawPosition::middle));
	chainsawUp = new JoystickButton(operatorStick, OPERATOR_CLIMBER_CHAINSAW_UP_BTN);
	chainsawUp->WhenPressed(new ChainsawPosition(ChainsawPosition::up));
	climberDisengage = new JoystickButton(operatorStick, OPERATOR_CLIMBER_DISENGAGE_BTN);
	climberDisengage->WhenPressed(new ClimberOnOff(off));
	climberEngage = new JoystickButton(operatorStick, OPERATOR_CLIMBER_ENGAGE_BTN);
	climberEngage->WhenPressed(new ClimberOnOff(on));
	shooterOffButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_TOGGLE_ON_OFF_BTN);
	shooterOffButton->WhenPressed(new ShooterToggleOnOff());
	shootButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_SHOOT_BTN);
	shootButton->WhenPressed(new Shoot());
	rightTurboOn = new JoystickButton(rightStick, RIGHT_DRIVE_TRAIN_TURBO_ON_BTN);
	rightTurboOn->WhileHeld(new TurboDriveOn(rightStick));
	pullShooterDashData = new JoystickButton(leftStick, LEFT_DASHBOARD_PULL_SHOOTER_DATA_BTN);
	pullShooterDashData->WhenPressed(new PullShooterData());
	switchDrive = new JoystickButton(rightStick, RIGHT_DRIVE_TRAIN_CHANGE_DRIVE_BTN);
	switchDrive->WhenPressed(new SetCubicDrive());
	leftTurboOn = new JoystickButton(leftStick, LEFT_DRIVE_TRAIN_TURBO_ON_BTN);
	leftTurboOn->WhileHeld(new TurboDriveOn(leftStick));	    
	writeDriveDataButton = new JoystickButton(leftStick, LEFT_DASHBOARD_WRITE_DRIVE_DATA_BTN);
	writeDriveDataButton->WhileHeld(new WriteDriveData());
}
void OI::ConstructSmartDashCommands(){
	SmartDashboard::PutData("ShooterOn", new ShooterToggleOnOff());
	SmartDashboard::PutData("ShooterOff", new ShooterToggleOnOff());
	SmartDashboard::PutData("ClimberOn", new ClimberOnOff(on));
	SmartDashboard::PutData("ClimberOff", new ClimberOnOff(off));
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
	SmartDashboard::PutData("SetChainsawPositionUp", new ChainsawPosition(ChainsawPosition::up));
	SmartDashboard::PutData("SetChainsawPositionMiddle", new ChainsawPosition(ChainsawPosition::middle));
	SmartDashboard::PutData("SetChainsawPositionDown", new ChainsawPosition(ChainsawPosition::down));
	SmartDashboard::PutData("ClimberDrive", new ClimberDrive());
	SmartDashboard::PutData("PullShooterData", new PullShooterData());
}
SmartJoystick* OI::getOperatorStick(){return operatorStick;}
SmartJoystick* OI::getRightStick(){return rightStick;}
SmartJoystick* OI::getLeftStick(){return leftStick;}
