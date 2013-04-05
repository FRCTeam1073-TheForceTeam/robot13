#include "OI.h"
#include "HardwarePortDefinitions.h"
#include "JoystickButtonSheet.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousForward.h"
#include "Commands/AutonomousSequence.h"
#include "Commands/AutonomousTurnToAngle.h"
#include "Commands/JoystickDrive.h"
#include "Commands/PullShooterData.h"
#include "Commands/SetCubicDrive.h"
#include "Commands/SetShooterToCalculatedValues.h"
#include "Commands/ShooterToggleOnOff.h"
#include "Commands/TurboDriveOn.h"
#include "Commands/WriteDriveData.h"
#include "Commands/ShooterAdjustAngle.h"
#include "Commands/ManualShooterSpeedAdjust.h"
#include "Commands/SetToFeederAngle.h"
#include "Commands/SpinFeeder.h"
//#define DEBUG_DATA

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
}
void OI::ConstructJoystickButtons(){
	//use auto aim (calculated) variables
	engageAutoAim = new JoystickButton(operatorStick, OPERATOR_SHOOTER_AUTOAIM_BTN);
	engageAutoAim->WhileHeld(new SetShooterToCalculatedValues());
	
	//dashboardy commands
	writeDriveDataButton = new JoystickButton(leftStick, LEFT_DASHBOARD_WRITE_DRIVE_DATA_BTN);
	writeDriveDataButton->WhileHeld(new WriteDriveData());
	pullShooterDashData = new JoystickButton(leftStick, LEFT_DASHBOARD_PULL_SHOOTER_DATA_BTN);
	pullShooterDashData->WhenPressed(new PullShooterData());
	//drive commands, turbo & cubic/normal
	leftTurboOn = new JoystickButton(leftStick, LEFT_DRIVE_TRAIN_TURBO_ON_BTN);
	leftTurboOn->WhileHeld(new TurboDriveOn(leftStick));
	rightTurboOn = new JoystickButton(rightStick, RIGHT_DRIVE_TRAIN_TURBO_ON_BTN);
	rightTurboOn->WhileHeld(new TurboDriveOn(rightStick));
	switchDrive = new JoystickButton(rightStick, RIGHT_DRIVE_TRAIN_CHANGE_DRIVE_BTN);
	switchDrive->WhenPressed(new SetCubicDrive());
	//shooter speed increment
	shooterSpeedUp = new JoystickButton (operatorStick, OPERATOR_SHOOTER_SPEED_INCREMENT_UP_BTN);
	shooterSpeedUp->WhenPressed(new ManualShooterSpeedAdjust(true, true));
	shooterSpeedDown = new JoystickButton (operatorStick, OPERATOR_SHOOTER_SPEED_INCREMENT_DOWN_BTN);
	shooterSpeedDown->WhenPressed(new ManualShooterSpeedAdjust(false, true));
	//shooter elevator
	shooterElevationDown = new JoystickButton(operatorStick, OPERATOR_SHOOTER_ELEVATOR_ANGLE_DOWN_BTN);
	shooterElevationDown->WhileHeld(new ShooterAdjustAngle(false));
	shooterElevationUp = new JoystickButton(operatorStick, OPERATOR_SHOOTER_ELEVATOR_ANGLE_UP_BTN);
	shooterElevationUp->WhileHeld(new ShooterAdjustAngle(true));
	//shooter misc commands, on/off & shoot
	shooterOnOffButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_TOGGLE_ON_OFF_BTN);
	shooterOnOffButton->WhenPressed(new ShooterToggleOnOff());
	feedButton = new JoystickButton(operatorStick, OPERATOR_SHOOTER_SHOOT_BTN);
	feedButton->WhileHeld(new SpinFeeder());	
	feedButtonReverse = new JoystickButton(operatorStick, OPERATOR_FEEDER_REVERSE_BTN);
	feedButtonReverse->WhileHeld(new SpinFeeder(false));	//reverses feeder while held
	
}
void OI::ConstructSmartDashCommands(){
#ifdef DEBUG_DATA
	SmartDashboard::PutData("ShooterOn", new ShooterToggleOnOff());
	SmartDashboard::PutData("ShooterOff", new ShooterToggleOnOff());
	SmartDashboard::PutData("SetCubicDrive", new SetCubicDrive());
	SmartDashboard::PutData("PullShooterData", new PullShooterData());
#endif
}
SmartJoystick* OI::getOperatorStick(){return operatorStick;}
SmartJoystick* OI::getRightStick(){return rightStick;}
SmartJoystick* OI::getLeftStick(){return leftStick;}
