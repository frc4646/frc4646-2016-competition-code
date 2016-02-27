#include "UltrasonicSensor.h"
#include "../RobotMap.h"
#include "Commands/UltrasonicCommand.h"

UltrasonicSensor::UltrasonicSensor(AnalogPin port) :
		Subsystem("ExampleSubsystem"),
		DistSensor(new AnalogInput(port))
{
	LiveWindow::GetInstance()->AddSensor("UltrasonicSensor", "Sensor", DistSensor.get());

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

void UltrasonicSensor::SendSD() {
	SmartDashboard::PutNumber("Ultrasonic Distance", GetDistance());
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
