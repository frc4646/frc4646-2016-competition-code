#include "LowSpeedCommand.h"
#include "Subsystems/LauncherPIDSubsystem.h"

LowSpeedCommand::LowSpeedCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void LowSpeedCommand::Initialize()
{
//	pidtest->ClearError();
	leftlauncherpid->SetSetpoint(.4);
	leftlauncherpid->Enable();
	rightlauncherpid->SetSetpoint(.4);
	rightlauncherpid->Enable();

}

// Called repeatedly when this Command is scheduled to run
void LowSpeedCommand::Execute()
{




}

// Make this return true when this Command no longer needs to run execute()
bool LowSpeedCommand::IsFinished()
{
	return !(leftlauncherpid->OnTarget() && rightlauncherpid->OnTarget());
}

// Called once after isFinished returns true
void LowSpeedCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LowSpeedCommand::Interrupted()
{

}
