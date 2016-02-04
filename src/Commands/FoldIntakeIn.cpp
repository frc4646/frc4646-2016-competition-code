#include "FoldIntakeIn.h"
#include "Subsystems/IntakeArms.h"
FoldIntakeIn::FoldIntakeIn()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void FoldIntakeIn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void FoldIntakeIn::Execute()
{
	intakearms->SetSpeed(-0.8);
}

// Make this return true when this Command no longer needs to run execute()
bool FoldIntakeIn::IsFinished()
{
	return intakearms->GetUpValue();
}

// Called once after isFinished returns true
void FoldIntakeIn::End()
{
	intakearms->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FoldIntakeIn::Interrupted()
{
	intakearms->SetSpeed(0);
}
