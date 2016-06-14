
#include "TankDrive.h"
#include "Subsystems/DropDrive.h"
#include "OI.h"

TankDrive::TankDrive()
:CommandBase("TankDrive")
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void TankDrive::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute()
{
	dropdrive->HandleDrive(oi->GetGamepad().GetRawAxis(1),oi->GetGamepad().GetRawAxis(5));
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDrive::End()
{
	dropdrive->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted()
{
	End();
}
