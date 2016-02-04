#include "DriveUntilClose.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/UltrasonicSensor.h"

DriveUntilClose::DriveUntilClose(double power, double distance):
robotPower(power),
sensorDistance(distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
	Requires(ultrasonicsensor);
}

// Called just before this Command runs the first time
void DriveUntilClose::Initialize()
{
	dropdrive->SetDrive(robotPower);
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilClose::Execute()
{
	dropdrive->SetDrive(robotPower);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilClose::IsFinished()
{
	return ultrasonicsensor->GetDistance()<sensorDistance;
}

// Called once after isFinished returns true
void DriveUntilClose::End()
{
	dropdrive->SetDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilClose::Interrupted()
{
	End();
}
