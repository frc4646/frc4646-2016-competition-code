#include "IntakeCommand.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "OI.h"

IntakeCommand::IntakeCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakeroller);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void IntakeCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute()
{
	intakeroller->SetSpeed(.80);
	leftlauncherpid->SetManual(-.55);
//	leftlauncherpid->Enable();
	rightlauncherpid->SetManual(-.55);
//	rightlauncherpid->Enable();
}

// Make this return true when this Command no longer needs to run execute()
bool IntakeCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void IntakeCommand::End()
{
	intakeroller->SetSpeed(0);
	leftlauncherpid->SetManual(0);
	rightlauncherpid->SetManual(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCommand::Interrupted()
{
	intakeroller->SetSpeed(0);
	leftlauncherpid->SetManual(0);
	rightlauncherpid->SetManual(0);

}
