#include <Subsystems/AccelerometerSensor.h>
#include "../RobotMap.h"

AccelerometerSensor::AccelerometerSensor() :
		Subsystem("ExampleSubsystem")
{
	accel = new BuiltInAccelerometer(Accelerometer::kRange_4G);
}

void AccelerometerSensor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

double AccelerometerSensor::GetX() {
	return accel->GetX();
}

double AccelerometerSensor::GetY() {
	return accel->GetY();
}

double AccelerometerSensor::GetZ() {
	return accel->GetZ();
}
	// Put methods for controlling this subsystem
// here. Call these from Commands.
