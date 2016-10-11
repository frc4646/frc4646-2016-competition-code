#include "DriveStraight.h"
#include "Subsystems/DropDrive.h"
#include "OI.h"
DriveStraight::DriveStraight()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void DriveStraight::Initialize()
{
	dropdrive->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraight::Execute()
{
	double robotPower = -oi->GetLeftStick().GetRawAxis(1);
	dropdrive->StraightDrive(robotPower);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraight::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveStraight::End()
{
	dropdrive->SetDrive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraight::Interrupted()
{
	End();
}
