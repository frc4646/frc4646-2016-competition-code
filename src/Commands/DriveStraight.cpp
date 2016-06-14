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
	double gyroCurve = dropdrive->GetHeading()/90.0;
	double robotPower = -oi->GetGamepad().GetRawAxis(1);
	if (robotPower > 0) {
		dropdrive->SetDrive(robotPower, -gyroCurve);
	}
	else {
		dropdrive->SetDrive(robotPower, gyroCurve);
	}

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
