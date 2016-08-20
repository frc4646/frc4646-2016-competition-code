#include "FlashlightOnCommand.h"
#include "../Subsystems/FlashlightRelay.h"

FlashlightOnCommand::FlashlightOnCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(flashlightrelay);
}

// Called just before this Command runs the first time
void FlashlightOnCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FlashlightOnCommand::Execute()
{
	flashlightrelay->On();
}

// Make this return true when this Command no longer needs to run execute()
bool FlashlightOnCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void FlashlightOnCommand::End()
{
	flashlightrelay->Off();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FlashlightOnCommand::Interrupted()
{
	flashlightrelay->Off();
}
