#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
SpeedController* RobotMap::shooterElevationVictor = NULL;
StallableAnalogEncoder* RobotMap::shooterElevationEncoder;
SmartCANJaguar* RobotMap::driveTrainLeftMotor = NULL;
SmartCANJaguar* RobotMap::driveTrainRightMotor = NULL;
#ifdef ADD_SECONDARY_DRIVE
SmartCANJaguar* RobotMap::driveTrainSecondaryLeftMotor = NULL;
SmartCANJaguar* RobotMap::driveTrainSecondaryRightMotor = NULL;
#endif
SmartGyro* RobotMap::driveTrainGyro = NULL;
SpeedController* RobotMap::collectorMotor = NULL;
DigitalInput* RobotMap::collectorDiscOnShooterBed = NULL;
SmartCANJaguar* RobotMap::shooterFrontJag = NULL;
SmartCANJaguar* RobotMap::shooterBackJag = NULL;
DigitalInput* RobotMap::shooterIREncoder = NULL;
void RobotMap::init() {
	LiveWindow* lw = LiveWindow::GetInstance();
	
	shooterElevationVictor = new Victor(PWM_SHOOTER_ELEVATION_MOTOR);
	lw->AddActuator("Shooter", "ShooterElevationVictor", (Victor*) shooterElevationVictor);

	driveTrainLeftMotor = new SmartCANJaguar(JAGUAR_DRIVE_LEFT);
	lw->AddActuator("DriveTrain","leftdrivemotor", driveTrainLeftMotor);
	
	driveTrainRightMotor = new SmartCANJaguar(JAGUAR_DRIVE_RIGHT);
	driveTrainRightMotor->Invert();
	lw->AddActuator("DriveTrain", "rightdrivemotor", driveTrainRightMotor);
	
	
#ifdef ADD_SECONDARY_DRIVE
	driveTrainSecondaryLeftMotor = new SmartCANJaguar(JAGUAR_DRIVE_SECONDARY_LEFT);
	lw->AddActuator("DriveTrain", "leftdrivesecondarymotor", driveTrainSecondaryLeftMotor);
	driveTrainSecondaryRightMotor = new SmartCANJaguar(JAGUAR_DRIVE_SECONDARY_RIGHT);
	driveTrainSecondaryRightMotor->Invert();
	lw->AddActuator("DriveTrain", "rightdrivesecondarymotor", driveTrainSecondaryRightMotor);
#endif
	
	driveTrainGyro = new SmartGyro(ANALOG_GYRO);
	lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
	driveTrainGyro->SetGyroMode(SmartGyro::degrees);
	driveTrainGyro->SetSensitivity(1.25);
	collectorMotor = new Victor(PWM_FEEDER_MOTOR);
	lw->AddActuator("Collector", "Motor", (Victor*) collectorMotor);
	
	collectorDiscOnShooterBed = new DigitalInput(DIGITAL_COLLECTOR_OPTICAL_SHOT_SENSOR);
	lw->AddSensor("Collector", "DiscOnShooterBed", collectorDiscOnShooterBed);
	
	shooterFrontJag = new SmartCANJaguar(JAGUAR_SHOOTER_FRONT);
	shooterFrontJag->Invert();
	lw->AddActuator("Shooter", "Front Jag", shooterFrontJag);
	shooterBackJag = new SmartCANJaguar(JAGUAR_SHOOTER_BACK);
	shooterBackJag->Invert();
	lw->AddActuator("Shooter", "Back Jag", shooterBackJag);
	
    shooterElevationEncoder = new StallableAnalogEncoder(ANALOG_SHOOTER_ANGLE_MAG_ENCODER);
    lw->AddSensor("Shooter", "Elevation Encoder", (AnalogChannel*)shooterElevationEncoder);

    shooterIREncoder = new DigitalInput(DIGITAL_SHOOTER_IR_ENCODER);
    
	driveTrainGyro->Reset();
	//lw->AddActuator("Roller", "Spike", rollerMotor);
}
