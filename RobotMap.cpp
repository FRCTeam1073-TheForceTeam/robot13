#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
AnalogChannel* RobotMap::lightLightRing = NULL;
Ultrasonic* RobotMap::navigationRangeFinder = NULL;
AnalogChannel* RobotMap::navigationAltimiter = NULL;
Servo* RobotMap::climberRightServo = NULL;
Servo* RobotMap::climberLeftServo = NULL;
CANJaguar* RobotMap::driveTrainLeftDriveMotor = NULL;
CANJaguar* RobotMap::driveTrainRightDriveMotor = NULL;
Gyro* RobotMap::driveTrainDriveTrainGyro = NULL;
CANJaguar* RobotMap::shooterElevationJag = NULL;
Encoder* RobotMap::shooterElevationEncoder = NULL;
CANJaguar* RobotMap::shooterShooterJag = NULL;
Encoder* RobotMap::shooterShooterEncoder = NULL;
DigitalInput* RobotMap::shooterElevationTopSwitch = NULL;
DigitalInput* RobotMap::shooterElevationBottomSwitch = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
void RobotMap::init() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	lightLightRing = new AnalogChannel(1, 2);
	lw->AddSensor("Light", "LightRing", lightLightRing);
	
	navigationRangeFinder = new Ultrasonic(1, 9, 1, 10);
	lw->AddSensor("Navigation", "RangeFinder", navigationRangeFinder);
	
	navigationAltimiter = new AnalogChannel(1, 1);
	lw->AddSensor("Navigation", "Altimiter", navigationAltimiter);
	
	climberRightServo = new Servo(1, 1);
	lw->AddActuator("Climber", "RightServo", climberRightServo);
	
	climberLeftServo = new Servo(1, 2);
	lw->AddActuator("Climber", "LeftServo", climberLeftServo);
	
	driveTrainLeftDriveMotor = new CANJaguar(6);
	
	
	driveTrainRightDriveMotor = new CANJaguar(3);
	
	
	driveTrainDriveTrainGyro = new Gyro(1, 5);
	lw->AddSensor("DriveTrain", "DriveTrainGyro", driveTrainDriveTrainGyro);
	driveTrainDriveTrainGyro->SetSensitivity(1.25);
	shooterElevationJag = new CANJaguar(4);
	
	
	shooterElevationEncoder = new Encoder(1, 7, 1, 8, false, Encoder::k4X);
	lw->AddSensor("Shooter", "ElevationEncoder", shooterElevationEncoder);
	shooterElevationEncoder->SetDistancePerPulse(1.0);
        shooterElevationEncoder->SetPIDSourceParameter(Encoder::kRate);
        shooterElevationEncoder->Start();
	shooterShooterJag = new CANJaguar(5);
	
	
	shooterShooterEncoder = new Encoder(1, 1, 1, 2, false, Encoder::k4X);
	lw->AddSensor("Shooter", "ShooterEncoder", shooterShooterEncoder);
	shooterShooterEncoder->SetDistancePerPulse(1.0);
        shooterShooterEncoder->SetPIDSourceParameter(Encoder::kRate);
        shooterShooterEncoder->Start();
	shooterElevationTopSwitch = new DigitalInput(1, 3);
	lw->AddSensor("Shooter", "ElevationTopSwitch", shooterElevationTopSwitch);
	
	shooterElevationBottomSwitch = new DigitalInput(1, 4);
	lw->AddSensor("Shooter", "ElevationBottomSwitch", shooterElevationBottomSwitch);
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    /* Reconstruct because Robot Builder doesn't support Encoders plugged into Jaguars - Can you blame them,
     * I mean who even does that? To keep Robot Builder's automatic Jaguar indexing in line (which is off by 1,
     * for some reason), I kept the jags in RB, but I'll reconstruct them below. Some tool.
     */
    driveTrainLeftDriveMotor = new CANJaguar(2, CANJaguar::kPercentVbus);
    driveTrainRightDriveMotor = new CANJaguar(3, CANJaguar::kPercentVbus);
}
