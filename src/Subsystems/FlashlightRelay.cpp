#include "FlashlightRelay.h"
#include "../RobotMap.h"

FlashlightRelay::FlashlightRelay() :
		Subsystem("ExampleSubsystem"),
		lightSpike(0)
{

}

void FlashlightRelay::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void FlashlightRelay::On() {
	lightSpike.Set(Relay::Value::kForward);
}

void FlashlightRelay::Off() {
	lightSpike.Set(Relay::Value::kOff);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
