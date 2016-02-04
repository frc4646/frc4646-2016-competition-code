#include "MedSpeedCommand.h"
#include "Subsystems/LauncherPIDSubsystem.h"

MedSpeedCommand::MedSpeedCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void MedSpeedCommand::Initialize()
{
	//pidtest->ClearError();
	leftlauncherpid->SetSetpoint(.8);
	leftlauncherpid->Enable();
	rightlauncherpid->SetSetpoint(.8);
	rightlauncherpid->Enable();


}

// Called repeatedly when this Command is scheduled to run
void MedSpeedCommand::Execute()
{




}

// Make this return true when this Command no longer needs to run execute()
bool MedSpeedCommand::IsFinished()
{
	return !(leftlauncherpid->OnTarget() && rightlauncherpid->OnTarget());
}

// Called once after isFinished returns true
void MedSpeedCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MedSpeedCommand::Interrupted()
{

}
