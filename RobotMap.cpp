#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
AnalogChannel* RobotMap::lightLightRing = NULL;
Ultrasonic* RobotMap::navigationRangeFinder = NULL;
AnalogChannel* RobotMap::navigationAltimiter = NULL;
Servo* RobotMap::climberClimberServo = NULL;
SpeedController* RobotMap::climberClimberVictor = NULL;
CANJaguar* RobotMap::driveTrainLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainRightMotor = NULL;
Gyro* RobotMap::driveTrainDriveTrainGyro = NULL;
CANJaguar* RobotMap::shooterElevationJag = NULL;
Encoder* RobotMap::shooterElevationEncoder = NULL;
Encoder* RobotMap::shooterWheelRPMEncoder = NULL;
CANJaguar* RobotMap::shooterPrimaryJag = NULL;
DigitalInput* RobotMap::shooterElevationTopSwitch = NULL;
DigitalInput* RobotMap::shooterElevationBottomSwitch = NULL;
CANJaguar* RobotMap::shooterSupportJag = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
#warning "Magic Numbers Practicing Dark Magic"
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	lightLightRing = new AnalogChannel(1, 2);
	lw->AddSensor("Light", "LightRing", lightLightRing);
	
	navigationRangeFinder = new Ultrasonic(1, 9, 1, 10);
	lw->AddSensor("Navigation", "RangeFinder", navigationRangeFinder);
	
	navigationAltimiter = new AnalogChannel(1, 3);
	lw->AddSensor("Navigation", "Altimiter", navigationAltimiter);
	
	climberClimberServo = new Servo(1, 1);
	lw->AddActuator("Climber", "ClimberServo", climberClimberServo);
	
	climberClimberVictor = new Victor(1, 2);
	lw->AddActuator("Climber", "ClimberVictor", (Victor*) climberClimberVictor);
	
	driveTrainLeftMotor = new CANJaguar(6);
	
	
	//driveTrainRightMotor = new CANJaguar(8);
	
	
	driveTrainDriveTrainGyro = new Gyro(1, 1);
	lw->AddSensor("DriveTrain", "DriveTrainGyro", driveTrainDriveTrainGyro);
	driveTrainDriveTrainGyro->SetSensitivity(1.25);
	shooterElevationJag = new CANJaguar(4);
	
	
	shooterElevationEncoder = new Encoder(1, 7, 1, 8, false, Encoder::k4X);
	lw->AddSensor("Shooter", "ElevationEncoder", shooterElevationEncoder);
	shooterElevationEncoder->SetDistancePerPulse(1.0);
        shooterElevationEncoder->SetPIDSourceParameter(Encoder::kRate);
        shooterElevationEncoder->Start();
	shooterWheelRPMEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Shooter", "WheelRPMEncoder", shooterWheelRPMEncoder);
	shooterWheelRPMEncoder->SetDistancePerPulse(1.0);
        shooterWheelRPMEncoder->SetPIDSourceParameter(Encoder::kRate);
        shooterWheelRPMEncoder->Start();
	shooterPrimaryJag = new CANJaguar(5);
	
	
	shooterElevationTopSwitch = new DigitalInput(1, 3);
	lw->AddSensor("Shooter", "ElevationTopSwitch", shooterElevationTopSwitch);
	
	shooterElevationBottomSwitch = new DigitalInput(1, 4);
	lw->AddSensor("Shooter", "ElevationBottomSwitch", shooterElevationBottomSwitch);
	
	shooterSupportJag = new CANJaguar(2);
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	
    driveTrainLeftMotor = new CANJaguar(6, CANJaguar::kPercentVbus);
    driveTrainRightMotor = new CANJaguar(1, CANJaguar::kPercentVbus);
    shooterPrimaryJag = new CANJaguar(5, CANJaguar:: kPercentVbus);
}
