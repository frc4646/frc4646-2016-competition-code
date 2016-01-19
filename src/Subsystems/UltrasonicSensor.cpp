#include "UltrasonicSensor.h"
#include "../RobotMap.h"

UltrasonicSensor::UltrasonicSensor() :
		Subsystem("ExampleSubsystem"),
		DistSensor(new AnalogInput(0))
{

}

void UltrasonicSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

double UltrasonicSensor::GetDistance() {
	return DistSensor->GetVoltage()*1024/5;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
