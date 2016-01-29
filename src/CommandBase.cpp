#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
DropDrive* CommandBase::dropdrive = NULL;
UltrasonicSensor* CommandBase::ultrasonicsensor = NULL;
PIDTest* CommandBase::pidtest = NULL;
PhotoelectricSensor* CommandBase::photoelectricsensor = NULL;

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
	examplesubsystem = new ExampleSubsystem();
	photoelectricsensor = new PhotoelectricSensor();
	dropdrive = new DropDrive();
	ultrasonicsensor = new UltrasonicSensor();
	oi = new OI();
	pidtest = new PIDTest();

	SmartDashboard::PutData(ultrasonicsensor);
	SmartDashboard::PutData(pidtest);
	SmartDashboard::PutString("Hello world!", "testing testing 123");
	SmartDashboard::PutNumber("Distance", ultrasonicsensor->GetDistance());
	SmartDashboard::PutNumber("Voltage", ultrasonicsensor->GetVoltage());
	SmartDashboard::PutNumber("PhotoElectric Sensor", photoelectricsensor->GetValue());
}
