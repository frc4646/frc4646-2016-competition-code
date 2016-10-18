#include "CommandBase.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/UltrasonicSensor.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/VisionCalculation.h"
#include "Subsystems/LEDSystem.h"
#include "OI.h"
#include "Commands/Scheduler.h"
#include "PinEnums.h"
#include "Subsystems/SendSmartDash.h"
#include "Subsystems/FiringServo.h"
#include "Subsystems/FlashlightRelay.h"
#include "Subsystems/WriteInputs.h"
#include "DoubleMotor.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DropDrive* CommandBase::dropdrive = NULL;
UltrasonicSensor* CommandBase::ultrasonicsensor = NULL;
Counter* CommandBase::LeftPidCounter = NULL;
Counter* CommandBase::RightPidCounter = NULL;
SpeedController* CommandBase::launcherController = NULL;
SpeedController* CommandBase::RightLauncherController = NULL;
//SlavedLauncherPID* CommandBase::slavelauncherpid = NULL;
LauncherPIDSubsystem* CommandBase::leftlauncherpid = NULL;
LauncherPIDSubsystem* CommandBase::rightlauncherpid = NULL;
IntakeRoller* CommandBase::intakeroller = NULL;
IntakeArms* CommandBase::intakearms = NULL;
VisionCalculation* CommandBase::visioncalculation = NULL;
LEDSystem* CommandBase::ledsystem = NULL;
SendSmartDash* CommandBase::sendsmartdash = NULL;
FiringServo* CommandBase::firingservo = NULL;
FlashlightRelay* CommandBase::flashlightrelay = NULL;
WriteInputsCommand *writeinputs = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{

}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	dropdrive = new DropDrive(M9,M1,A1);			// left, right, gyro
	ultrasonicsensor = new UltrasonicSensor(A0);	// port

//	slavelauncherpid = new SlavedLauncherPID("Master", M8, M2, D2);
	LeftPidCounter = new Counter(D4);				// port
	RightPidCounter = new Counter(D2);				// port

	// Left launch wheel motor controller
	launcherController = new Victor(M8);			// motorPort
	// Is this the left controller?
	// If so, that is what is should be named

	// Right launch wheel motor controller
	RightLauncherController = new Victor(M2);		// motorPort

	// Left launcher wheel PID
	leftlauncherpid = new LauncherPIDSubsystem("Left", *launcherController,*LeftPidCounter);			// side, speedController, counter
	// Right launcher wheel PID
	rightlauncherpid = new LauncherPIDSubsystem("Right", *RightLauncherController,*RightPidCounter);	// side, speedController, counter
	// Intake belt/roller
	intakeroller = new IntakeRoller(M7);			// rollerPort
	intakearms = new IntakeArms(M5,D5,D1,D0,D7,D8);	// motorPort, limitPort, leftEncoderA, leftEncoderB, rightEncoderA, rightEncoderB
	visioncalculation = new VisionCalculation();	// [no inputs]
	ledsystem = new LEDSystem();					// [no inputs]
	sendsmartdash = new SendSmartDash();			// [no inputs]
	firingservo = new FiringServo(M4);				// servoPort
	// Is the relay port hard-coded? Or configurable?
	flashlightrelay = new FlashlightRelay();		// [no inputs]
	// Port is not configurable
	writeinputs = new WriteInputsCommand();			// [no inputs]

	//oi needs to be last
	oi = new OI();									// [no inputs]


	SmartDashboard::PutData(dropdrive);
//	SmartDashboard::PutData(ultrasonicsensor);
	SmartDashboard::PutData(leftlauncherpid);
	SmartDashboard::PutData(rightlauncherpid);
//	SmartDashboard::PutString("Hello world!", "testing testing 123");
//  LOL
	SmartDashboard::PutNumber("Gyroval", dropdrive->GetHeading());
//	SmartDashboard::PutNumber("Voltage", ultrasonicsensor->GetVoltage());
	SmartDashboard::PutNumber("LeftPID", leftlauncherpid->ReturnPIDInput());
	SmartDashboard::PutNumber("RightPID", rightlauncherpid->ReturnPIDInput());
	//SmartDashboard::PutNumber("WriteInputs", writeinputs->GetInput());
}
