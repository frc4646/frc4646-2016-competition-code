#include "TurnForAngle.h"
#include "Subsystems/DropDrive.h"
#include <math.h>

TurnForAngle::TurnForAngle(double robotPower, double robotAngle):
power(robotPower),
angle(robotAngle)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
}

// Called just before this Command runs the first time
void TurnForAngle::Initialize()
{
	initDif = abs(dropdrive->GetHeading() - angle);
}

// Called repeatedly when this Command is scheduled to run
void TurnForAngle::Execute()
{
	drive = power * abs((dropdrive->GetHeading() - angle))/initDif;
	if (drive < .2)
	{
		drive = .2;
	}
	if (angle > 0)
	{
		dropdrive->SetDrive(drive, 1);
	}
	else
	{
		dropdrive->SetDrive(drive, -1);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnForAngle::IsFinished()
{
	error = dropdrive->GetHeading() - angle;
	return abs(error) < 5;
}

// Called once after isFinished returns true
void TurnForAngle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnForAngle::Interrupted()
{

}
