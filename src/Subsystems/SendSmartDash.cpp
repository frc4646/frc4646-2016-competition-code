#include <Subsystems/SendSmartDash.h>
#include "../RobotMap.h"
#include "Commands/SendDash.h"

SendSmartDash::SendSmartDash() :
		Subsystem("SendSmartDash")
{

}

void SendSmartDash::InitDefaultCommand()
{
	SetDefaultCommand (new SendDash());
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

