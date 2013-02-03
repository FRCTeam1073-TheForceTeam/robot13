#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
Relay* RobotMap::lightLightRing = NULL;
SpeedController* RobotMap::climberRightClimbWindowTalon = NULL;
CANJaguar* RobotMap::climberLeftCIM = NULL;
CANJaguar* RobotMap::climberRightCIM = NULL;
SpeedController* RobotMap::climberLeftClimbWindowTalon = NULL;
CANJaguar* RobotMap::driveTrainLeftMotor = NULL;
CANJaguar* RobotMap::driveTrainRightMotor = NULL;
Gyro* RobotMap::driveTrainGyro = NULL;
SpeedController* RobotMap::collectorMotor = NULL;
DigitalInput* RobotMap::collectordiscOnShooterBed = NULL;
AnalogChannel* RobotMap::collectordiscCountSensor = NULL;
AnalogChannel* RobotMap::collectordiscUpsideDownSensor = NULL;
CANJaguar* RobotMap::shooterElevationJag = NULL;
Encoder* RobotMap::shooterElevationEncoder = NULL;
Encoder* RobotMap::shooterWheelRPMEncoder = NULL;
CANJaguar* RobotMap::shooterPrimaryJag = NULL;
CANJaguar* RobotMap::shooterSupportJag = NULL;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
LimitSwitch* RobotMap::shooterElevationTopSwitch = NULL;
LimitSwitch* RobotMap::shooterElevationBottomSwitch = NULL;
LimitSwitch* RobotMap::climberChainsawBottomSwitch = NULL;
LimitSwitch* RobotMap::climberChainsawTopSwitch = NULL;
Encoder* RobotMap::climberChainsawElevationMEncoder = NULL;
DigitalInput* RobotMap::velocity1 = NULL;
DigitalInput* RobotMap::velocity2 = NULL;
void RobotMap::init() {
#warning "Magic Numbers Practicing Dark Magic"
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	LiveWindow* lw = LiveWindow::GetInstance();
	lightLightRing = new Relay(1, 1);
	lw->AddActuator("Light", "LightRing", lightLightRing);
	
	climberRightClimbWindowTalon = new Talon(1, 2);
	lw->AddActuator("Climber", "RightClimbWindowTalon", (Talon*) climberRightClimbWindowTalon);
	
	climberLeftCIM = new CANJaguar(2);
	
	
	climberRightCIM = new CANJaguar(3);
	
	
	climberLeftClimbWindowTalon = new Talon(1, 3);
	lw->AddActuator("Climber", "LeftClimbWindowTalon", (Talon*) climberLeftClimbWindowTalon);
	
	driveTrainLeftMotor = new CANJaguar(6);
	
	
	driveTrainRightMotor = new CANJaguar(9);
	
	
	driveTrainGyro = new Gyro(1, 1);
	lw->AddSensor("DriveTrain", "Gyro", driveTrainGyro);
	driveTrainGyro->SetSensitivity(1.25);
	collectorMotor = new Victor(1, 1);
	lw->AddActuator("Collector", "Motor", (Victor*) collectorMotor);
	
	collectordiscOnShooterBed = new DigitalInput(1, 5);
	lw->AddSensor("Collector", "discOnShooterBed", collectordiscOnShooterBed);
	
	collectordiscCountSensor = new AnalogChannel(1, 2);
	lw->AddSensor("Collector", "discCountSensor", collectordiscCountSensor);
	
	collectordiscUpsideDownSensor = new AnalogChannel(1, 3);
	lw->AddSensor("Collector", "discUpsideDownSensor", collectordiscUpsideDownSensor);
	
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
	
	
	shooterSupportJag = new CANJaguar(7);
	
	
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    velocity1 = new DigitalInput(1,4);
    velocity2 = new DigitalInput(1, 5);
	shooterElevationTopSwitch = new LimitSwitch(1, 7);
	shooterElevationBottomSwitch = new LimitSwitch(1, 6);
	lw->AddSensor("Shooter", "ElevationTopSwitch", shooterElevationTopSwitch);
	lw->AddSensor("Shooter", "ElevationBottomSwitch", shooterElevationBottomSwitch);
	
}
