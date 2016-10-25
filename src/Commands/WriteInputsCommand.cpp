/*#include <Commands/WriteInputsCommand.h>
#include "Subsystems/WriteInputs.h"

WriteInputs wi;

WriteInputsCommand::WriteInputsCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void WriteInputsCommand::Initialize()
{
	wi = new WriteInputs();
}

// Called repeatedly when this Command is scheduled to run
void WriteInputsCommand::Execute()
{
	wi.SendSD();
}

// Make this return true when this Command no longer needs to run execute()
bool WriteInputsCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void WriteInputsCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WriteInputsCommand::Interrupted()
{

}
*/
