#include "SpinUp.h"
#include "Subsystems/LauncherPIDSubsystem.h"
#include "Subsystems/SlavedLauncherPID.h"
SpinUp::SpinUp(double speed)
:launchSpeed(speed)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
//	Requires(slavelauncherpid);
	Requires(leftlauncherpid);
	Requires(rightlauncherpid);
}

// Called just before this Command runs the first time
void SpinUp::Initialize()
{
	//pidtest->ClearError();
//	slavelauncherpid->SetSetpoint(launchSpeed);
//	slavelauncherpid->Enable();
	leftlauncherpid->SetSetpoint(launchSpeed);
	leftlauncherpid->Enable();
	rightlauncherpid->SetSetpoint(launchSpeed);
	rightlauncherpid->Enable();

}

// Called repeatedly when this Command is scheduled to run
void SpinUp::Execute()
{




}

// Make this return true when this Command no longer needs to run execute()
bool SpinUp::IsFinished()
{
	//SmartDashboard::PutBoolean("SlaveOnTarget", slavelauncherpid->OnTarget());
	SmartDashboard::PutBoolean("LeftOnTarget", leftlauncherpid->OnTarget());
	SmartDashboard::PutBoolean("RightOnTarget", rightlauncherpid->OnTarget());
	//	return !leftlauncherpid->OnTarget();
	//return slavelauncherpid->OnTarget();
		return (leftlauncherpid->OnTarget() && rightlauncherpid->OnTarget());
}

// Called once after isFinished returns true
void SpinUp::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpinUp::Interrupted()
{
}
