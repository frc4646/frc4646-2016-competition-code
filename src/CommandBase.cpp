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

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DropDrive* CommandBase::dropdrive = NULL;
UltrasonicSensor* CommandBase::ultrasonicsensor = NULL;
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
	dropdrive = new DropDrive(M9,M1,A1);
	ultrasonicsensor = new UltrasonicSensor(A0);

//	slavelauncherpid = new SlavedLauncherPID("Master", M8, M2, D2);
	leftlauncherpid = new LauncherPIDSubsystem("Left", M8,D2);
	rightlauncherpid = new LauncherPIDSubsystem("Right", M2,D4);
	intakeroller = new IntakeRoller(M7);
	intakearms = new IntakeArms(M5,D5,D1,D0,D7,D8);
	visioncalculation = new VisionCalculation();
	ledsystem = new LEDSystem();
	sendsmartdash = new SendSmartDash();
	firingservo = new FiringServo(M4);
	flashlightrelay = new FlashlightRelay();

	//oi needs to be last
	oi = new OI();


	SmartDashboard::PutData(dropdrive);
//	SmartDashboard::PutData(ultrasonicsensor);
	SmartDashboard::PutData(leftlauncherpid);
	SmartDashboard::PutData(rightlauncherpid);
//	SmartDashboard::PutString("Hello world!", "testing testing 123");
	SmartDashboard::PutNumber("Gyroval", dropdrive->GetHeading());
//	SmartDashboard::PutNumber("Voltage", ultrasonicsensor->GetVoltage());
	SmartDashboard::PutNumber("LeftPID", leftlauncherpid->ReturnPIDInput());
	SmartDashboard::PutNumber("RightPID", rightlauncherpid->ReturnPIDInput());
}
