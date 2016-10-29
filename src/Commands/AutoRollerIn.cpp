#include "AutoRollerIn.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/IntakeArms.h"

AutoRollerIn::AutoRollerIn():
CommandBase("AutoRollerIn")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakeroller);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void AutoRollerIn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoRollerIn::Execute()
{
	intakeroller->SetSpeed(.8);
	intakearms->Raise();
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRollerIn::IsFinished()
{
	return intakearms->GetUpValue();
}

// Called once after isFinished returns true
void AutoRollerIn::End()
{
	intakeroller->SetSpeed(0);
	intakearms->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRollerIn::Interrupted()
{
	End();
}
