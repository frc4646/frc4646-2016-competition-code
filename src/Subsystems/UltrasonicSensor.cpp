#include "UltrasonicSensor.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicCommand.h"

UltrasonicSensor::UltrasonicSensor() :
		Subsystem("ExampleSubsystem"),
		DistSensor(new AnalogInput(0))
{

}

void UltrasonicSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new UltrasonicCommand());
}

double UltrasonicSensor::GetDistance() {
	return DistSensor->GetVoltage()/.012;
}

double UltrasonicSensor::GetVoltage() {
	return DistSensor->GetVoltage();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
