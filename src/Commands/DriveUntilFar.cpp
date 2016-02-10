#include "DriveUntilFar.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/UltrasonicSensor.h"

DriveUntilFar::DriveUntilFar(double power, double distance):
robotPower(power),
sensorDistance(distance)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
	Requires(ultrasonicsensor);
}

// Called just before this Command runs the first time
void DriveUntilFar::Initialize()
{
	dropdrive->SetDrive(robotPower, 0);
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilFar::Execute()
{
	dropdrive->SetDrive(robotPower, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilFar::IsFinished()
{
	return ultrasonicsensor->GetDistance()>sensorDistance;
}

// Called once after isFinished returns true
void DriveUntilFar::End()
{
	dropdrive->SetDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilFar::Interrupted()
{
	End();
}
