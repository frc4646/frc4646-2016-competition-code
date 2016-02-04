#include "HighSpeedCommand.h"
#include "Subsystems/LauncherPIDSubsystem.h"
HighSpeedCommand::HighSpeedCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void HighSpeedCommand::Initialize()
{
	//pidtest->ClearError();
	leftlauncherpid->SetSetpoint(1);
	leftlauncherpid->Enable();
	rightlauncherpid->SetSetpoint(1);
	rightlauncherpid->Enable();

}

// Called repeatedly when this Command is scheduled to run
void HighSpeedCommand::Execute()
{




}

// Make this return true when this Command no longer needs to run execute()
bool HighSpeedCommand::IsFinished()
{
	return !(leftlauncherpid->OnTarget() && rightlauncherpid->OnTarget());
}

// Called once after isFinished returns true
void HighSpeedCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HighSpeedCommand::Interrupted()
{
}
