#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
SpeedController* RobotMap::shooterElevationVictor = NULL;
SpeedController* RobotMap::climberArmLeftClimbWindowVictor = NULL;
SpeedController* RobotMap::climberArmRightClimbWindowVictor = NULL;
SmartCANJaguar* RobotMap::climberLeftCIM = NULL;
CANJaguar* RobotMap::climberRightCIM = NULL;
CANJaguar* RobotMap::driveTrainLeftMotor = NULL;
SmartCANJaguar* RobotMap::driveTrainRightMotor = NULL;
#ifdef ADD_SECONDARY_DRIVE
CANJaguar* RobotMap::driveTrainLeftMotorSecondary = NULL;
CANJaguar* RobotMap::driveTrainRightMotorSecondary = NULL;
#endif
SmartGyro* RobotMap::driveTrainGyro = NULL;
SpeedController* RobotMap::collectorMotor = NULL;
DigitalInput* RobotMap::collectorDiscOnShooterBed = NULL;
AnalogChannel* RobotMap::collectorDiscCountSensor = NULL;
SmartCANJaguar* RobotMap::shooterFrontJag = NULL;
SmartCANJaguar* RobotMap::shooterBackJag = NULL;
DigitalInput* RobotMap::velocity1 = NULL;
DigitalInput* RobotMap::velocity2 = NULL;
StallableAnalogEncoder* RobotMap::shooterElevationEncoder = NULL;
StallableAnalogEncoder* RobotMap::climberArmLeftWindowEncoder = NULL;
StallableAnalogEncoder* RobotMap::climberArmRightWindowEncoder = NULL;
void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	
	shooterElevationVictor = new Victor(PWM_SHOOTER_ELEVATION_MOTOR);
	lw->AddActuator("Shooter", "ShooterElevationVictor", (Victor*) shooterElevationVictor);
	
	climberArmLeftClimbWindowVictor = new Victor(PWM_CLIMBER_LEFT_WINDOW_MOTOR);
	lw->AddActuator("Climber Arms", "LeftClimbWindowVictor", (Victor*) climberArmLeftClimbWindowVictor);
	
	climberArmRightClimbWindowVictor = new Victor(PWM_CLIMBER_RIGHT_WINDOW_MOTOR);
	lw->AddActuator("Climber Arms", "RightClimbWindowVictor", (Victor*) climberArmRightClimbWindowVictor);
	
	climberLeftCIM = new SmartCANJaguar(JAGUAR_CLIMBER_CIM_LEFT);
	climberLeftCIM->Invert();
	lw->AddActuator("Climber", "Left CIM", climberLeftCIM);
	
	climberRightCIM = new CANJaguar(JAGUAR_CLIMBER_CIM_RIGHT);
	lw->AddActuator("Climber", "Right CIM", climberRightCIM);
	
	driveTrainLeftMotor = new CANJaguar(JAGUAR_DRIVE_LEFT);
	
	driveTrainRightMotor = new SmartCANJaguar(JAGUAR_DRIVE_RIGHT);
	driveTrainRightMotor->Invert();
	
	
#ifdef ADD_SECONDARY_DRIVE
	driveTrainLeftMotorSecondary = new CANJaguar(JAGUAR_DRIVE_LEFT_SECONDARY);
	driveTrainRightMotorSecondary = new CANJaguar(JAGUAR_DRIVE_RIGHT_SECONDARY);
#endif
	
	driveTrainGyro = new SmartGyro(ANALOG_GYRO);
	lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
	driveTrainGyro->SetGyroMode(SmartGyro::degrees);
	driveTrainGyro->SetSensitivity(1.25);
	collectorMotor = new Victor(PWM_FEEDER_MOTOR);
	lw->AddActuator("Collector", "Motor", (Victor*) collectorMotor);
	
	collectorDiscOnShooterBed = new DigitalInput(DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR);
	lw->AddSensor("Collector", "DiscOnShooterBed", collectorDiscOnShooterBed);
	
	collectorDiscCountSensor = new AnalogChannel(ANALOG_COLLECTOR_DISC_PROXIMITY);
	lw->AddSensor("Collector", "DiscCountSensor", collectorDiscCountSensor);
	
	shooterFrontJag = new SmartCANJaguar(JAGUAR_SHOOTER_FRONT);
	shooterFrontJag->Invert();
	lw->AddActuator("Shooter", "Front Jag", shooterFrontJag);
	shooterBackJag = new SmartCANJaguar(JAGUAR_SHOOTER_BACK);
	lw->AddActuator("Shooter", "Back Jag", shooterBackJag);
	
    shooterElevationEncoder = new StallableAnalogEncoder(ANALOG_SHOOTER_ANGLE_MAG_ENCODER);
    lw->AddSensor("Shooter", "Elevation Encoder", (AnalogChannel*)shooterElevationEncoder);
	climberArmLeftWindowEncoder = new StallableAnalogEncoder(ANALOG_CLIMBER_LEFT_ANGLE_MAG_ENCODER);
	lw->AddSensor("Climber Arms", "Left Arm Encoder", (AnalogChannel*)climberArmLeftWindowEncoder);
	climberArmRightWindowEncoder = new StallableAnalogEncoder(ANALOG_CLIMBER_RIGHT_ANGLE_MAG_ENCODER);
	lw->AddSensor("Climber Arms", "Right Arm Encoder", (AnalogChannel*)climberArmRightWindowEncoder);
    velocity1 = new DigitalInput(DIGITAL_MUZZLE_VELOCITY_ONE);
    velocity2 = new DigitalInput(DIGITAL_MUZZLE_VELOCITY_TWO);
	driveTrainGyro->Reset();
}
