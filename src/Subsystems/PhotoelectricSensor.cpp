#include "PhotoelectricSensor.h"
#include "../RobotMap.h"
#include "Commands/PhotoelectricCommand.h"
#include "Counter.h"

PhotoelectricSensor::PhotoelectricSensor() :
		Subsystem("ExampleSubsystem"),
		PhotoSensor(2)
{
	PhotoSensor.SetSamplesToAverage(6);
}

void PhotoelectricSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new PhotoelectricCommand());
}

double PhotoelectricSensor::GetValue() {
	return (1.0/(PhotoSensor.GetPeriod()))*60.0;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
