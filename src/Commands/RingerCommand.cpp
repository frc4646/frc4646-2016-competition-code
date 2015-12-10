#include "RingerCommand.h"

RingerCommand::RingerCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(ringer);
}

// Called just before this Command runs the first time
void RingerCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RingerCommand::Execute()
{
	ringer->SetSpeed(0.2);
}

// Make this return true when this Command no longer needs to run execute()
bool RingerCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RingerCommand::End()
{
	ringer->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RingerCommand::Interrupted()
{
	End();
}
