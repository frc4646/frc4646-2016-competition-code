#include "ReverseIntakeCommand.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/LauncherPIDSubsystem.h"

ReverseIntakeCommand::ReverseIntakeCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakeroller);
//	Requires(leftlauncherpid);
//	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void ReverseIntakeCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ReverseIntakeCommand::Execute()
{
	intakeroller->SetSpeed(-0.8);

}

// Make this return true when this Command no longer needs to run execute()
bool ReverseIntakeCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReverseIntakeCommand::End()
{
	intakeroller->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReverseIntakeCommand::Interrupted()
{
	intakeroller->SetSpeed(0);
}
