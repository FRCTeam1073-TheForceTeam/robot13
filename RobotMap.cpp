#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
SpeedController* RobotMap::shooterElevationVictor = NULL;
SpeedController* RobotMap::climberLeftClimbWindowVictor = NULL;
SpeedController* RobotMap::climberRightClimbWindowVictor = NULL;
CANJaguar* RobotMap::climberLeftCIM = NULL;
CANJaguar* RobotMap::climberRightCIM = NULL;
CANJaguar* RobotMap::driveTrainLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainRightMotor = NULL;
#ifdef ADD_SECONDARY_DRIVE
CANJaguar* RobotMap::driveTrainLeftMotorSecondary = NULL;
CANJaguar* RobotMap::driveTrainRightMotorSecondary = NULL;
#endif
Gyro* RobotMap::driveTrainGyro = NULL;
SpeedController* RobotMap::collectorMotor = NULL;
DigitalInput* RobotMap::collectorDiscOnShooterBed = NULL;
AnalogChannel* RobotMap::collectorDiscCountSensor = NULL;
AnalogChannel* RobotMap::collectorDiscUpsideDownSensor = NULL;
CANJaguar* RobotMap::shooterElevationJag = NULL;
CANJaguar* RobotMap::shooterFrontJag = NULL;
CANJaguar* RobotMap::shooterBackJag = NULL;
DigitalInput* RobotMap::shooterElevationBottomSwitch = NULL;
DigitalInput* RobotMap::velocity1 = NULL;
DigitalInput* RobotMap::velocity2 = NULL;
StallableAnalogEncoder* RobotMap::shooterElevationEncoder = NULL;
StallableAnalogEncoder* RobotMap::climberLeftWindowEncoder = NULL;
StallableAnalogEncoder* RobotMap::climberRightWindowEncoder = NULL;
void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	
	shooterElevationVictor = new Victor(PWM_SHOOTER_ELEVATION_MOTOR);
	lw->AddActuator("Shooter", "ShooterElevationVictor", (Victor*) shooterElevationVictor);
	
	climberLeftClimbWindowVictor = new Victor(PWM_CLIMBER_LEFT_WINDOW_MOTOR);
	lw->AddActuator("Climber", "LeftClimbWindowVictor", (Victor*) climberLeftClimbWindowVictor);
	
	climberRightClimbWindowVictor = new Victor(PWM_CLIMBER_RIGHT_WINDOW_MOTOR);
	lw->AddActuator("Climber", "RightClimbWindowVictor", (Victor*) climberRightClimbWindowVictor);
	
	climberLeftCIM = new CANJaguar(JAGUAR_CLIMBER_CIM_LEFT);
	climberRightCIM = new CANJaguar(JAGUAR_CLIMBER_CIM_RIGHT);
	driveTrainLeftMotor = new CANJaguar(JAGUAR_DRIVE_LEFT);
	driveTrainRightMotor = new CANJaguar(JAGUAR_DRIVE_RIGHT);
#ifdef ADD_SECONDARY_DRIVE
	driveTrainLeftMotorSecondary = new CANJaguar(JAGUAR_DRIVE_LEFT_SECONDARY);
	driveTrainRightMotorSecondary = new CANJaguar(JAGUAR_DRIVE_RIGHT_SECONDARY);
#endif
	
	driveTrainGyro = new Gyro(ANALOG_GYRO);
	lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(1.25);
	collectorMotor = new Victor(PWM_FEEDER_MOTOR);
	lw->AddActuator("Collector", "Motor", (Victor*) collectorMotor);
	
	collectorDiscOnShooterBed = new DigitalInput(DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR);
	lw->AddSensor("Collector", "DiscOnShooterBed", collectorDiscOnShooterBed);
	
	collectorDiscCountSensor = new AnalogChannel(ANALOG_COLLECTOR_DISC_PROXIMITY);
	lw->AddSensor("Collector", "DiscCountSensor", collectorDiscCountSensor);
	
	collectorDiscUpsideDownSensor = new AnalogChannel(ANALOG_COLLECTOR_DISC_UPSIDEDOWN);
	lw->AddSensor("Collector", "DiscUpsideDownSensor", collectorDiscUpsideDownSensor);
	
	shooterElevationJag = new CANJaguar(JAGUAR_SHOOTER_ANGLE);
	shooterFrontJag = new CANJaguar(JAGUAR_SHOOTER_FRONT);
	shooterBackJag = new CANJaguar(JAGUAR_SHOOTER_BACK);
	
    shooterElevationEncoder = new StallableAnalogEncoder(ANALOG_SHOOTER_ANGLE_MAG_ENCODER);
	climberLeftWindowEncoder = new StallableAnalogEncoder(ANALOG_CLIMBER_LEFT_ANGLE_MAG_ENCODER);
	climberRightWindowEncoder = new StallableAnalogEncoder(ANALOG_CLIMBER_RIGHT_ANGLE_MAG_ENCODER);
    velocity1 = new DigitalInput(DIGITAL_MUZZLE_VELOCITY_ONE);
    velocity2 = new DigitalInput(DIGITAL_MUZZLE_VELOCITY_TWO);
	shooterElevationBottomSwitch = new DigitalInput(DIGITAL_SHOOTER_ELEVATION_BOTTOM_LIMIT);
	lw->AddSensor("Shooter", "ElevationBottomSwitch", shooterElevationBottomSwitch);
	driveTrainGyro->Reset();
}
