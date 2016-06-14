#include "IntakeCommand.h"
#include "Subsystems/IntakeRoller.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"
#include "Subsystems/IntakeArms.h"
#include "OI.h"

IntakeCommand::IntakeCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(intakeroller);
	Requires(slavelauncherpid);
	//	Requires(leftlauncherpid);
//	Requires(rightlauncherpid);
	Requires(intakearms);
}

// Called just before this Command runs the first time
void IntakeCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void IntakeCommand::Execute()
{
	intakeroller->SetSpeed(.80);
//	double lift_power = -0.35;
	double lift_power = -0.28 - (0.2 * oi->GetMechanismStick().GetRawAxis(1));

//	double lift_power = -0.35 - (0.2 * oi->GetMechanismStick().GetRawAxis(1));

	intakearms->SetSpeed(lift_power);
	slavelauncherpid->SetManual(-.55);
	//	leftlauncherpid->SetManual(-.55);
////	leftlauncherpid->Enable();
//	rightlauncherpid->SetManual(-.55);
////	rightlauncherpid->Enable();
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
	slavelauncherpid->SetManual(0);
	//	leftlauncherpid->SetManual(0);
//	rightlauncherpid->SetManual(0);
	intakearms->SetSpeed(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void IntakeCommand::Interrupted()
{
	intakeroller->SetSpeed(0);
	slavelauncherpid->SetManual(0);
	//	leftlauncherpid->SetManual(0);
//	rightlauncherpid->SetManual(0);
	intakearms->SetSpeed(0);

}
