#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Relay* RobotMap::lightLightRing = NULL;
AnalogChannel* RobotMap::navigationAltimiter = NULL;
Servo* RobotMap::climberClimberServo = NULL;
SpeedController* RobotMap::climberClimberVictor = NULL;
CANJaguar* RobotMap::climberChainsawPositionJag = NULL;
CANJaguar* RobotMap::climberChainsawSpeedJag = NULL;
CANJaguar* RobotMap::driveTrainLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainRightMotor = NULL;
Gyro* RobotMap::driveTrainGyro = NULL;
CANJaguar* RobotMap::shooterElevationJag = NULL;
Encoder* RobotMap::shooterElevationEncoder = NULL;
Encoder* RobotMap::shooterWheelRPMEncoder = NULL;
CANJaguar* RobotMap::shooterPrimaryJag = NULL;
CANJaguar* RobotMap::shooterSupportJag = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
LimitSwitch* RobotMap::shooterElevationTopSwitch = NULL;
LimitSwitch* RobotMap::shooterElevationBottomSwitch = NULL;
void RobotMap::init() {
#warning "Magic Numbers Practicing Dark Magic"
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	lightLightRing = new Relay(1, 1);
	lw->AddActuator("Light", "LightRing", lightLightRing);
	
	navigationAltimiter = new AnalogChannel(1, 3);
	lw->AddSensor("Navigation", "Altimiter", navigationAltimiter);
	
	climberClimberServo = new Servo(1, 1);
	lw->AddActuator("Climber", "ClimberServo", climberClimberServo);
	
	climberClimberVictor = new Victor(1, 2);
	lw->AddActuator("Climber", "ClimberVictor", (Victor*) climberClimberVictor);
	
	climberChainsawPositionJag = new CANJaguar(3);
	
	
	climberChainsawSpeedJag = new CANJaguar(7);
	
	
	driveTrainLeftMotor = new CANJaguar(6);
	
	
<<<<<<< HEAD
	driveTrainRightMotor = new CANJaguar(8);
=======
	//driveTrainRightMotor = new CANJaguar(8); wont work, no #8 jag
>>>>>>> f1ed59a3a9ff4d34b18b3bdc0b42aec31aee687a
	
	
	driveTrainGyro = new Gyro(1, 1);
	lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(1.25);
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
	
	
	shooterSupportJag = new CANJaguar(2);
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    
	shooterElevationTopSwitch = new LimitSwitch(1, 3);
	shooterElevationBottomSwitch = new LimitSwitch(1, 4);
	
	lw->AddSensor("Shooter", "ElevationTopSwitch", shooterElevationTopSwitch);
	
	lw->AddSensor("Shooter", "ElevationBottomSwitch", shooterElevationBottomSwitch);
	
	shooterSupportJag = new CANJaguar(2);
	
	
    driveTrainLeftMotor = new CANJaguar(6, CANJaguar::kPercentVbus);
    driveTrainRightMotor = new CANJaguar(1, CANJaguar::kPercentVbus);
    shooterPrimaryJag = new CANJaguar(5, CANJaguar:: kPercentVbus);
}
