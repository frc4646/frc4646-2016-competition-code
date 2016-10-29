#include "DriveUntilClose.h"
#include "Subsystems/DropDrive.h"
#include "Subsystems/UltrasonicSensor.h"

DriveUntilClose::DriveUntilClose(double power, double distance):
CommandBase("DriveUntilClose"),
robotPower(power),
sensorDistance(distance),
confidence(0)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(dropdrive);
	Requires(ultrasonicsensor);
}

// Called just before this Command runs the first time
void DriveUntilClose::Initialize()
{
//	dropdrive->ResetGyro();
}

// Called repeatedly when this Command is scheduled to run
void DriveUntilClose::Execute()
{
	gyroCurve = dropdrive->GetHeading()/90.0;
	dropdrive->SetDrive(robotPower, -gyroCurve);
	SmartDashboard::PutNumber("Gyro Heading", dropdrive->GetHeading());
	if (ultrasonicsensor->GetDistance()<sensorDistance)
	{
		confidence++;
	}
	else
	{
		confidence = 0;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveUntilClose::IsFinished()
{
	return confidence > 3;
}

// Called once after isFinished returns true
void DriveUntilClose::End()
{
	dropdrive->SetDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveUntilClose::Interrupted()
{
	End();
}
